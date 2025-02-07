#include "Currency.hpp"


// Constructeur
Currency::Currency(double drift, PnlVect *volatility, InterestRateModel foreignRate, InterestRateModel domesticRate)
    : RiskyDynamics(drift, volatility), foreignInterestRate(foreignRate), domesticInterestRate(domesticRate) {}


// Getters
InterestRateModel Currency::getForeignInterestRate() const {
    return foreignInterestRate;
}

InterestRateModel Currency::getDomesticInterestRate() const {
    return domesticInterestRate;
}