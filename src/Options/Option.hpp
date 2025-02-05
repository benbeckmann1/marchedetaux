#ifndef OPTION_HPP
#define OPTION_HPP

#include <vector>
#include <pnl/pnl_vector.h>
#include "../InterestRateModel.hpp"
#include "../Grid/ITimeGrid.hpp"

class Option {
protected:
    std::vector<int> nbAssetsPerCurrency_;   
    std::vector<InterestRateModel> foreignInterestRates_;
    InterestRateModel domesticInterestRate_;
    ITimeGrid* monitoringTimeGrid_;
    double maturity_;

public:
    Option(const std::vector<int>& nbAssetsPerCurrency,
           const std::vector<InterestRateModel>& foreignInterestRates,
           const InterestRateModel& domesticInterestRate,
           ITimeGrid* monitoringTimeGrid,
           double maturity)
        : nbAssetsPerCurrency_(nbAssetsPerCurrency), 
          foreignInterestRates_(foreignInterestRates),
          domesticInterestRate_(domesticInterestRate), 
          monitoringTimeGrid_(monitoringTimeGrid),
          maturity_(maturity) {}  // Ajout de maturity_

    virtual ~Option() {}  // Destructeur virtuel

    // Méthode virtuelle pure pour le calcul du payoff
    virtual double payoff(const PnlMat* simulations) const = 0;

    // Getter pour obtenir la maturité
    double getMaturity() const { return maturity_; }

    // Getter pour obtenir le InterestRateModel domestique
    InterestRateModel getDomesticInterestRate() const { return domesticInterestRate_; }
};

#endif
