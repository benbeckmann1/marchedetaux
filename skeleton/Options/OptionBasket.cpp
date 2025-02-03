#include "OptionBasket.hpp"
#include <cmath>

OptionBasket::OptionBasket(const std::vector<int>& assetCurrencyMapping,
                           const std::vector<InterestRateModel>& foreignInterestRates,
                           const InterestRateModel& domesticInterestRate,
                           const ITimeGrid& monitoringTimeGrid,
                           const std::vector<double>& weights,
                           double strike)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, monitoringTimeGrid),
      weights_(weights), strike_(strike) {}

double OptionBasket::payoff(const PnlVect* assetPrices) const {
    // double weightedSum = 0.0;
    // for (size_t i = 0; i < weights_.size(); ++i) {
    //     weightedSum += weights_[i] * GET(assetPrices, i);
    // }
    // return std::max(weightedSum - strike_, 0.0);
    return 0;
}
