#include "OptionCallCurrency.hpp"
#include <cmath>

OptionCallCurrency::OptionCallCurrency(const std::vector<int>& assetCurrencyMapping,
                                       const std::vector<InterestRateModel>& foreignInterestRates,
                                       const InterestRateModel& domesticInterestRate,
                                       const ITimeGrid& monitoringTimeGrid,
                                       double strike)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, monitoringTimeGrid),
      strike_(strike) {}

double OptionCallCurrency::payoff(const PnlVect* assetPrices) const {
    // double X_foreign = GET(assetPrices, 0);
    // return std::max(X_foreign - strike, 0.0);
    return 0;
}
