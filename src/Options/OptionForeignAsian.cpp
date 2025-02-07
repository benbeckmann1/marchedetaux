#include "OptionForeignAsian.hpp"


OptionForeignAsian::OptionForeignAsian(const std::vector<int>& nbAssetsPerCurrency,
                                       const std::vector<InterestRateModel>& foreignInterestRates,
                                       const InterestRateModel& domesticInterestRate,
                                       const ITimeGrid& monitoringTimeGrid, double maturity)
    : Option(nbAssetsPerCurrency, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity) {}




double OptionForeignAsian::payoff(const PnlMat* simulations) const {
    int N = monitoringTimeGrid_->len();
    double sum = 0.0;

    for (int j = 0; j < N; j++) {
        sum += MGET(simulations, j, 1);
    }

    double S_domestic = MGET(simulations, simulations->m - 1, 0);  // Prix de l'actif domestique

    return std::max(sum / N - S_domestic, 0.0);
}
