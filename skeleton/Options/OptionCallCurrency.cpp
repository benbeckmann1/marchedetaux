#include "OptionCallCurrency.hpp"
#include <cmath>

OptionCallCurrency::OptionCallCurrency(const std::vector<int>& assetCurrencyMapping,
                                       const std::vector<InterestRateModel>& foreignInterestRates,
                                       const InterestRateModel& domesticInterestRate,
                                       const ITimeGrid& monitoringTimeGrid,
                                       double strike,
                                       double maturity)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}

double OptionCallCurrency::payoff(const PnlMat* simulation) const {
    // double X_foreign = GET(assetPrices, 0);
    // return std::max(X_foreign - strike, 0.0);
    return 0;
}
