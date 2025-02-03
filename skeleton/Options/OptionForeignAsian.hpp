#ifndef OPTION_FOREIGN_ASIAN_HPP
#define OPTION_FOREIGN_ASIAN_HPP

#include "Option.hpp"

class OptionForeignAsian : public Option {
public:
    OptionForeignAsian(const std::vector<int>& assetCurrencyMapping,
                       const std::vector<InterestRateModel>& foreignInterestRates,
                       const InterestRateModel& domesticInterestRate,
                       const ITimeGrid& monitoringTimeGrid);

    double payoff(const PnlVect* assetPrices) const override;
};

#endif
