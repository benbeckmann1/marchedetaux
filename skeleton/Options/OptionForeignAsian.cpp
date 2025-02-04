#include "OptionForeignAsian.hpp"
#include <cmath>

OptionForeignAsian::OptionForeignAsian(const std::vector<int>& assetCurrencyMapping,
                                       const std::vector<InterestRateModel>& foreignInterestRates,
                                       const InterestRateModel& domesticInterestRate,
                                       const ITimeGrid& monitoringTimeGrid, double maturity)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity) {}

double OptionForeignAsian::payoff(const PnlMat* simulation) const {
    // int N = assetPrices->size;
    // double sum = 0.0;

    // for (int j = 0; j < N; ++j) {
    //     sum += GET(assetPrices, j);
    // }

    // return std::max(sum / N, 0.0);
    return 0;
}
