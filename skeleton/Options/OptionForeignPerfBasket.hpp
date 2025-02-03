#ifndef OPTION_FOREIGN_PERF_BASKET_HPP
#define OPTION_FOREIGN_PERF_BASKET_HPP

#include "Option.hpp"

class OptionForeignPerfBasket : public Option {
private:
    double strike_;

public:
    OptionForeignPerfBasket(const std::vector<int>& assetCurrencyMapping,
                            const std::vector<InterestRateModel>& foreignInterestRates,
                            const InterestRateModel& domesticInterestRate,
                            const ITimeGrid& monitoringTimeGrid,
                            double strike);

    double payoff(const PnlVect* assetPrices) const override;
};

#endif
