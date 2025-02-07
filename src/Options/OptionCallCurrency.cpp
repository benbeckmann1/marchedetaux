#include "OptionCallCurrency.hpp"


OptionCallCurrency::OptionCallCurrency(const std::vector<int>& nbAssetsPerCurrency,
                                       const std::vector<InterestRateModel>& foreignInterestRates,
                                       const InterestRateModel& domesticInterestRate,
                                       const ITimeGrid& monitoringTimeGrid,
                                       double strike,
                                       double maturity)
    : Option(nbAssetsPerCurrency, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}




double OptionCallCurrency::payoff(const PnlMat* simulations) const {
    double X_foreign = MGET(simulations, simulations->m - 1, 0); 

    return std::max(X_foreign - strike_, 0.0);
}
