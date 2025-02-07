#include "RiskyAsset.hpp"


// Constructeur
RiskyAsset::RiskyAsset(double drift, PnlVect *volatility, InterestRateModel domesticRate)
    : RiskyDynamics(drift, volatility), domesticInterestRate(domesticRate) {}


// Getter pour le taux d'intérêt domestique
InterestRateModel RiskyAsset::getDomesticInterestRate() const {
    return domesticInterestRate;
}

