#ifndef OPTION_BASKET_HPP
#define OPTION_BASKET_HPP

#include "Option.hpp"

class OptionBasket : public Option {
private:
    std::vector<double> weights_;
    double strike_;

public:
    OptionBasket(const std::vector<int>& assetCurrencyMapping,
                 const std::vector<InterestRateModel>& foreignInterestRates,
                 const InterestRateModel& domesticInterestRate,
                 const ITimeGrid& monitoringTimeGrid,
                 const std::vector<double>& weights,
                 double strike);

    double payoff(const PnlVect* assetPrices) const override;
};

#endif
