#ifndef OPTION_FOREIGN_PERF_BASKET_HPP
#define OPTION_FOREIGN_PERF_BASKET_HPP

#include "Option.hpp"

class OptionForeignPerfBasket : public Option {
private:
    double strike_;
    double maturity_;
    PnlVect* nb_assets_;  // vecteur contenant le nombre d'actifs de chaque monnaie étrangère

public:
    OptionForeignPerfBasket(const std::vector<int>& assetCurrencyMapping,
                            const std::vector<InterestRateModel>& foreignInterestRates,
                            const InterestRateModel& domesticInterestRate,
                            const ITimeGrid& monitoringTimeGrid,
                            double strike, double maturity, 
                            PnlVect* nb_assets);

    double payoff(const PnlMat* simulations) const override;
};

#endif
