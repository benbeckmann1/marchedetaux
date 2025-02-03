#include "Currency.hpp"
#include <cmath>

Currency::Currency(double drift, const PnlVect* volatilityVector, const InterestRateModel& foreignInterestRate, const InterestRateModel& domesticInterestRate)
    : RiskyDynamics(drift, volatilityVector), foreignInterestRate(foreignInterestRate), domesticInterestRate(domesticInterestRate) {}

double Currency::sampleNextDate(double dt, double dW) const {
    double sigma = GET(volatilityVector, 0);  // Supposons que la volatilité est un scalaire
    return exp((drift - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * dW);
}
