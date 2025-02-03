#ifndef OPTION_CALL_QUANTO_HPP
#define OPTION_CALL_QUANTO_HPP

#include "Option.hpp"

class OptionCallQuanto : public Option {
private:
    double strike_;

public:
    OptionCallQuanto(const std::vector<int>& assetCurrencyMapping,
                     const std::vector<InterestRateModel>& foreignInterestRates,
                     const InterestRateModel& domesticInterestRate,
                     const ITimeGrid& monitoringTimeGrid,
                     double strike);

    double payoff(const PnlVect* assetPrices) const override;
};

#endif
