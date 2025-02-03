#ifndef CURRENCY_HPP
#define CURRENCY_HPP

#include "RiskyDynamics.hpp"
#include "InterestRateModel.hpp"

class Currency : public RiskyDynamics {
private:
    InterestRateModel foreignInterestRate;   // Taux d'intérêt étranger
    InterestRateModel domesticInterestRate;  // Taux d'intérêt domestique

public:
    Currency(double drift, const PnlVect* volatilityVector, const InterestRateModel& foreignInterestRate, const InterestRateModel& domesticInterestRate);
    
    double sampleNextDate(double dt, double dW) const override;
};

#endif
