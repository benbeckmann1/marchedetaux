#include "Currency.hpp"
#include <cmath>  // Pour exp()
#include <iostream>

// Constructeur
Currency::Currency(double drift, PnlVect *volatility, InterestRateModel foreignRate, InterestRateModel domesticRate)
    : RiskyDynamics(drift, volatility), foreignInterestRate(foreignRate), domesticInterestRate(domesticRate) {}

// Destructeur
Currency::~Currency() {}

