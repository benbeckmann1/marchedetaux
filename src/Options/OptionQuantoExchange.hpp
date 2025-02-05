#ifndef OPTION_QUANTO_EXCHANGE_HPP
#define OPTION_QUANTO_EXCHANGE_HPP

#include "Option.hpp"

class OptionQuantoExchange : public Option {
public:
    double strike_;
    double maturity_;

public:
    OptionQuantoExchange(const std::vector<int>& assetCurrencyMapping,
                         const std::vector<InterestRateModel>& foreignInterestRates,
                         const InterestRateModel& domesticInterestRate,
                         const ITimeGrid& monitoringTimeGrid,
                         double strike, double maturity);

    double payoff(const PnlMat* simulations) const override;
};

#endif
