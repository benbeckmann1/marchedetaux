#ifndef OPTION_FOREIGN_ASIAN_HPP
#define OPTION_FOREIGN_ASIAN_HPP

#include "Option.hpp"

class OptionForeignAsian : public Option {
public:
    double maturity_;
    OptionForeignAsian(const std::vector<int>& assetCurrencyMapping,
                       const std::vector<InterestRateModel>& foreignInterestRates,
                       const InterestRateModel& domesticInterestRate,
                       const ITimeGrid& monitoringTimeGrid, double maturity);

    double payoff(const PnlMat* simulation) const override;
};

#endif
