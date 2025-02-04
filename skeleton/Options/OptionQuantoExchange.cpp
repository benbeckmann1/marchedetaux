#include "OptionQuantoExchange.hpp"
#include <cmath>

OptionQuantoExchange::OptionQuantoExchange(const std::vector<int>& assetCurrencyMapping,
                                           const std::vector<InterestRateModel>& foreignInterestRates,
                                           const InterestRateModel& domesticInterestRate,
                                           const ITimeGrid& monitoringTimeGrid,
                                           double strike, double maturity)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}

double OptionQuantoExchange::payoff(const PnlMat* simulation) const {
    // double S_domestic = GET(assetPrices, 0);
    // double S_foreign = GET(assetPrices, 1);
    // double X_foreign = GET(assetPrices, 2);
    // return std::max(S_domestic - S_foreign * X_foreign - strike, 0.0);
    return 0;
}
