#ifndef RISKY_ASSET_HPP
#define RISKY_ASSET_HPP

#include "RiskyDynamics.hpp"
#include "InterestRateModel.hpp"

class RiskyAsset : public RiskyDynamics {
private:
    InterestRateModel domesticInterestRate;  // Taux d'intérêt domestique

public:
    RiskyAsset(double drift, const PnlVect* volatilityVector, const InterestRateModel& domesticInterestRate);
    
    double sampleNextDate(double dt, double dW) const override;
};

#endif
