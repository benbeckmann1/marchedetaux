#ifndef OPTION_QUANTO_EXCHANGE_HPP
#define OPTION_QUANTO_EXCHANGE_HPP

#include "Option.hpp"

class OptionQuantoExchange : public Option {
private:
    double strike;

public:
    OptionQuantoExchange(const std::vector<int>& assetCurrencyMapping,
                         const std::vector<InterestRateModel>& foreignInterestRates,
                         const InterestRateModel& domesticInterestRate,
                         const ITimeGrid& monitoringTimeGrid,
                         double strike);

    double payoff(const PnlVect* assetPrices) const override;
};

#endif
