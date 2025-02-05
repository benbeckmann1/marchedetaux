#include "OptionCallCurrency.hpp"
#include <cmath>
#include "pnl/pnl_matrix.h"


OptionCallCurrency::OptionCallCurrency(const std::vector<int>& assetCurrencyMapping,
                                       const std::vector<InterestRateModel>& foreignInterestRates,
                                       const InterestRateModel& domesticInterestRate,
                                       const ITimeGrid& monitoringTimeGrid,
                                       double strike,
                                       double maturity)
    : Option(assetCurrencyMapping, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}




double OptionCallCurrency::payoff(const PnlMat* simulations) const {
    double X_foreign = MGET(simulations, simulations->m - 1, 0);  // Prix ZC de l'actif étranger

    return std::max(X_foreign - strike_, 0.0);
}
