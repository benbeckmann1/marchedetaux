#include "OptionForeignPerfBasket.hpp"


OptionForeignPerfBasket::OptionForeignPerfBasket(const std::vector<int>& nbAssetsPerCurrency,
                                                 const std::vector<InterestRateModel>& foreignInterestRates,
                                                 const InterestRateModel& domesticInterestRate,
                                                 const ITimeGrid& monitoringTimeGrid,
                                                 double strike, double maturity)
    : Option(nbAssetsPerCurrency, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}





double OptionForeignPerfBasket::payoff(const PnlMat* simulations) const {
    int idx_max = 0;
    double maxPerf = -1.0;

    double n0 = nbAssetsPerCurrency_[0]; // nombre d'actifs domestiques
    double nb_actifs_tot = std::accumulate(nbAssetsPerCurrency_.begin(), nbAssetsPerCurrency_.end(), 0); // pour avoir l'indice de la première monnaie étrangère
    double sum_nb_actifs = n0;
    double idx_nb_actifs_max = 0; // pour avoir l'indice du premier actif étranger ayant la meilleure performance dans le calcul du payoff

    // boucle sur tous les actifs étrangers
    for (int i = 0; i < nbAssetsPerCurrency_.size() - 1; i++) {
        double sum_t1 = 0.0;  
        double sum_t2 = 0.0;

        double n_i = nbAssetsPerCurrency_[i+1];

        // boucle sur les actifs d'une monnaie étrangère
        for (int j = 0; j < n_i; j++) {
            double SX_t1 = MGET(simulations, 0, sum_nb_actifs + j); // prix de l'actif étranger à la date t_1
            double SX_t2 = MGET(simulations, 1, sum_nb_actifs + j); // ---------------------------------- t_2

            double BX_t1 = MGET(simulations, 0, nb_actifs_tot + i); // prix du ZC étranger à la date t_1
            double BX_t2 = MGET(simulations, 1, nb_actifs_tot + i); // ----------------------------- t_2

            sum_t1 += SX_t1 / BX_t1;
            sum_t2 += SX_t2 / BX_t2;
        }

        // actualisation de la performance par : exp(r_f * (t2 - t1))
        double perf = (sum_t2 / sum_t1) * foreignInterestRates_[i].accumulationFactor(monitoringTimeGrid_->at(0), monitoringTimeGrid_->at(1)); // si problème vérifier l'exp

        // recherche de la meilleure performance parmi les actifs étrangers
        if (perf > maxPerf) {
            maxPerf = perf;
            idx_max = i+1;
            idx_nb_actifs_max = sum_nb_actifs;
        }

        sum_nb_actifs += n_i;
    }



    double n_imax = nbAssetsPerCurrency_[idx_max]; // nombre d'actifs de la monnaie de l'actif étranger ayant la meilleure performance
    double sum_foreign_T = 0.0;
    double sum_domestic_T = 0.0;

    // boucle sur les actifs de la monnaie de l'actif étranger ayant la meilleure performance
    for (int k = 0; k < n_imax; k++) {
        sum_foreign_T += MGET(simulations, simulations->m - 1, idx_nb_actifs_max + k); // ajoute le prix de l'actif étranger à la date T
    }

    // boucle sur les actifs domestiques
    for (int i = 0; i < n0; i++) {
        sum_domestic_T += MGET(simulations, simulations->m - 1, i); // ajoute le prix de l'actif domestique à la date T
    }

    return std::max(sum_foreign_T / n_imax - sum_domestic_T / n0 - strike_, 0.0);
}
