#ifndef OPTION_BASKET_HPP
#define OPTION_BASKET_HPP

#include "Option.hpp"
#include <cmath>
#include "pnl/pnl_matrix.h"

class OptionBasket : public Option {
private:
    std::vector<double> weights_;
    double strike_;
    double maturity_;

public:
    OptionBasket(const std::vector<int>& nbAssetsPerCurrency,
                 const std::vector<InterestRateModel>& foreignInterestRates,
                 const InterestRateModel& domesticInterestRate,
                 const ITimeGrid& monitoringTimeGrid,
                 const std::vector<double>& weights,
                 double strike, double maturity);

    double payoff(const PnlMat* simulations) const override;
};

#endif
