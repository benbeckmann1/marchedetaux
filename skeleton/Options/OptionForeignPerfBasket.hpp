#ifndef OPTION_FOREIGN_PERF_BASKET_HPP
#define OPTION_FOREIGN_PERF_BASKET_HPP

#include "Option.hpp"

class OptionForeignPerfBasket : public Option {
private:
    double strike_;
    double maturity_;

public:
    OptionForeignPerfBasket(const std::vector<int>& assetCurrencyMapping,
                            const std::vector<InterestRateModel>& foreignInterestRates,
                            const InterestRateModel& domesticInterestRate,
                            const ITimeGrid& monitoringTimeGrid,
                            double strike, double maturity);

    double payoff(const PnlMat* simulation) const override;
};

#endif
