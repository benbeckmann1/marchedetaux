#include "OptionCallQuanto.hpp"
#include <cmath>

OptionCallQuanto::OptionCallQuanto(const std::vector<int>& assetCurrencyMapping,
                                   const std::vector<InterestRateModel>& foreignInterestRates,
                                   const InterestRateModel& domesticInterestRate,
                                   const ITimeGrid& monitoringTimeGrid,
                                   double strike)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, monitoringTimeGrid),
      strike_(strike) {}

double OptionCallQuanto::payoff(const PnlVect* assetPrices) const {
    // double S_foreign = GET(assetPrices, 0);  // Prix de l'actif étranger
    // double X_foreign = GET(assetPrices, 1);  // Taux de change
    // return std::max(S_foreign * X_foreign - strike, 0.0);
    return 0;
}
