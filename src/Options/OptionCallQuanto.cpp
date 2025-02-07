#include "OptionCallQuanto.hpp"


OptionCallQuanto::OptionCallQuanto(const std::vector<int>& nbAssetsPerCurrency,
                                   const std::vector<InterestRateModel>& foreignInterestRates,
                                   const InterestRateModel& domesticInterestRate,
                                   const ITimeGrid& monitoringTimeGrid,
                                   double strike, double maturity)
    : Option(nbAssetsPerCurrency, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}



double OptionCallQuanto::payoff(const PnlMat* simulations) const {
    double S_foreign = MGET(simulations, simulations->m - 1, 0);  // Prix de l'actif étranger

    return std::max(S_foreign - strike_, 0.0);
}
