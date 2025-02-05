#include "RiskyDynamics.hpp"
#include <iostream>
#include <cmath>

// Constructeur
RiskyDynamics::RiskyDynamics(double drift, PnlVect *volatility) : drift(drift) {
    volatilityVector = pnl_vect_copy(volatility);
}

// Destructeur : libère la mémoire allouée pour le vecteur de volatilité
RiskyDynamics::~RiskyDynamics() {
    if (volatilityVector) {
        pnl_vect_free(&volatilityVector);
    }
}


double RiskyDynamics::sampleNextDate(PnlVect *G, double step, double currentValue) {
    // Calcul de l'impact du mouvement brownien
    double volatilityEffect = pnl_vect_scalar_prod(volatilityVector, G) * sqrt(step);

    // Application du modèle Black-Scholes sous probabilité risque-neutre
    double norm = pnl_vect_scalar_prod(volatilityVector, volatilityVector);

    double nextValue = currentValue * exp((drift-0.5*norm)*step + volatilityEffect);  // vérifier que le drift envoyé en bien r0

    return nextValue;
}


// Getter pour la dérive
double RiskyDynamics::getDrift() const {
    return drift;
}

// Getter pour le vecteur de volatilité
PnlVect* RiskyDynamics::getVolatilityVector() const {
    return pnl_vect_copy(volatilityVector);
}