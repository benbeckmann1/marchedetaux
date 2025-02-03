#include "OptionForeignPerfBasket.hpp"
#include <cmath>

OptionForeignPerfBasket::OptionForeignPerfBasket(const std::vector<int>& assetCurrencyMapping,
                                                 const std::vector<InterestRateModel>& foreignInterestRates,
                                                 const InterestRateModel& domesticInterestRate,
                                                 const ITimeGrid& monitoringTimeGrid,
                                                 double strike)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, monitoringTimeGrid),
      strike_(strike) {}

double OptionForeignPerfBasket::payoff(const PnlVect* assetPrices) const {
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
