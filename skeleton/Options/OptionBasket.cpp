#include "OptionBasket.hpp"
#include <cmath>

OptionBasket::OptionBasket(const std::vector<int>& assetCurrencyMapping,
                           const std::vector<InterestRateModel>& foreignInterestRates,
                           const InterestRateModel& domesticInterestRate,
                           const ITimeGrid& monitoringTimeGrid,
                           const std::vector<double>& weights,
                           double strike, double maturity)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      weights_(weights), strike_(strike), maturity_(maturity) {}

double OptionBasket::payoff(const PnlMat* simulation) const {
    // double weightedSum = 0.0;
    // for (size_t i = 0; i < weights_.size(); ++i) {
    //     weightedSum += weights_[i] * GET(assetPrices, i);
    // }
    // return std::max(weightedSum - strike_, 0.0);
    return 0;
}
