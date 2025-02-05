#ifndef OPTION_CALL_QUANTO_HPP
#define OPTION_CALL_QUANTO_HPP

#include "Option.hpp"

class OptionCallQuanto : public Option {
private:
    double strike_;
    double maturity_;

public:
    OptionCallQuanto(const std::vector<int>& assetCurrencyMapping,
                     const std::vector<InterestRateModel>& foreignInterestRates,
                     const InterestRateModel& domesticInterestRate,
                     const ITimeGrid& monitoringTimeGrid,
                     double strike, double maturity);

    double payoff(const PnlMat* simulation) const override;
};

#endif
