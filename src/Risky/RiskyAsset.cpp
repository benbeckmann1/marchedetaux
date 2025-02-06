#include "RiskyAsset.hpp"
#include <cmath>  // Pour exp()
#include <iostream>
#include "pnl/pnl_vector.h"

// Constructeur
RiskyAsset::RiskyAsset(double drift, PnlVect *volatility, InterestRateModel domesticRate)
    : RiskyDynamics(drift, volatility), domesticInterestRate(domesticRate) {}


// Getter pour le taux d'intérêt domestique
InterestRateModel RiskyAsset::getDomesticInterestRate() const {
    return domesticInterestRate;
}

