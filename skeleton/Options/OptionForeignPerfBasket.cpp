#include "OptionForeignPerfBasket.hpp"
#include <cmath>

OptionForeignPerfBasket::OptionForeignPerfBasket(const std::vector<int>& assetCurrencyMapping,
                                                 const std::vector<InterestRateModel>& foreignInterestRates,
                                                 const InterestRateModel& domesticInterestRate,
                                                 const ITimeGrid& monitoringTimeGrid,
                                                 double strike, double maturity)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}

double OptionForeignPerfBasket::payoff(const PnlMat* simulation) const {
    // double maxPerf = -1.0;
    // int N = assetPrices->size;

    // // Recherche de la meilleure performance parmi les actifs étrangers
    // for (int i = 0; i < N; ++i) {
    //     double perf = GET(assetPrices, i);
    //     if (perf > maxPerf) {
    //         maxPerf = perf;
    //     }
    // }

    // return std::max(maxPerf - strike_, 0.0);
    return 0;
}
