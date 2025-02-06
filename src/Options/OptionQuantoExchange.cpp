#include "OptionQuantoExchange.hpp"
#include <cmath>
#include "pnl/pnl_matrix.h"

OptionQuantoExchange::OptionQuantoExchange(const std::vector<int>& nbAssetsPerCurrency,
                                           const std::vector<InterestRateModel>& foreignInterestRates,
                                           const InterestRateModel& domesticInterestRate,
                                           const ITimeGrid& monitoringTimeGrid,
                                           double strike, double maturity)
    : Option(nbAssetsPerCurrency, foreignInterestRates, domesticInterestRate, const_cast<ITimeGrid*>(&monitoringTimeGrid), maturity),
      strike_(strike), maturity_(maturity) {}



double OptionQuantoExchange::payoff(const PnlMat* simulations) const {
    double S_domestic = MGET(simulations,  simulations->m - 1, 0);   // Prix de l'actif domestique
    double S_foreign = MGET(simulations, simulations->m - 1, 1);   // Prix de l'actif étranger

    return std::max(S_domestic - S_foreign - strike_, 0.0);
}
