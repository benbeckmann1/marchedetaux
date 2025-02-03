#include "RiskyAsset.hpp"
#include <cmath>

RiskyAsset::RiskyAsset(double drift, const PnlVect* volatilityVector, const InterestRateModel& domesticInterestRate)
    : RiskyDynamics(drift, volatilityVector), domesticInterestRate(domesticInterestRate) {}

double RiskyAsset::sampleNextDate(double dt, double dW) const {
    double sigma = GET(volatilityVector, 0);  // Supposons que la volatilité est un scalaire
    return exp((drift - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * dW);
}
