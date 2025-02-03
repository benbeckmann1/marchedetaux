#ifndef OPTION_HPP
#define OPTION_HPP

#include <vector>
#include <pnl/pnl_vector.h>
#include "../InterestRateModel.hpp"
#include "../ITimeGrid.hpp"

class Option {
public:
    std::vector<int> assetCurrencyMapping_;   
    std::vector<InterestRateModel> foreignInterestRates_;
    InterestRateModel domesticInterestRate_;
    ITimeGrid monitoringTimeGrid_;

public:

    Option(const std::vector<int>& assetCurrencyMapping,
           const std::vector<InterestRateModel>& foreignInterestRates,
           const InterestRateModel& domesticInterestRate,
           const ITimeGrid& monitoringTimeGrid)
        : assetCurrencyMapping_(assetCurrencyMapping), foreignInterestRates_(foreignInterestRates)
        , domesticInterestRate_(domesticInterestRate), monitoringTimeGrid_(monitoringTimeGrid) {}

    // Constructeur supprimé, les classes filles doivent gérer leurs propres attributs
    virtual ~Option() {}  // Destructeur virtuel

    // Méthode virtuelle pure pour le calcul du payoff
    virtual double payoff(const PnlVect* assetPrices) const = 0;
};

#endif
