#ifndef RISKYASSET_HPP
#define RISKYASSET_HPP

#include "RiskyDynamics.hpp"
#include "../InterestRateModel.hpp"

class RiskyAsset : public RiskyDynamics {
private:
    InterestRateModel domesticInterestRate; // Modèle de taux domestique

public:
    // Constructeur et destructeur
    RiskyAsset(double drift, PnlVect *volatility, InterestRateModel domesticRate);
    ~RiskyAsset() override = default;

    // Getter pour le taux d'intérêt domestique
    InterestRateModel getDomesticInterestRate() const;
};

#endif // RISKYASSET_HPP
