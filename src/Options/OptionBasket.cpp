#include "OptionBasket.hpp"


OptionBasket::OptionBasket(const std::vector<int>& assetCurrencyMapping,
                           const std::vector<InterestRateModel>& foreignInterestRates,
                           const InterestRateModel& domesticInterestRate,
                           const ITimeGrid& monitoringTimeGrid,
                           const std::vector<double>& weights,
                           double strike, double maturity)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      weights_(weights), strike_(strike), maturity_(maturity) {}




double OptionBasket::payoff(const PnlMat* simulations) const {
    double weightedSum = 0.0;

    for (int i = 0; i < weights_.size(); i++) {
        weightedSum += weights_[i] * MGET(simulations, simulations->m - 1, i);
    }
    
    return std::max(weightedSum - strike_, 0.0);
}
