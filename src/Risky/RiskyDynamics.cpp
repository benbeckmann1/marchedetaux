#include "RiskyDynamics.hpp"


// Constructeur
RiskyDynamics::RiskyDynamics(double drift, PnlVect *volatility) : drift(drift), volatilityVector(pnl_vect_copy(volatility)) {}

// Destructeur : libère la mémoire allouée pour le vecteur de volatilité
RiskyDynamics::~RiskyDynamics() {
    pnl_vect_free(&volatilityVector);
}


double RiskyDynamics::sampleNextDate(PnlVect *G, double step, double currentValue) {
    double volatilityEffect = pnl_vect_scalar_prod(volatilityVector, G) * sqrt(step);
    double norm = pnl_vect_scalar_prod(volatilityVector, volatilityVector);

    double nextValue = currentValue * exp((drift-0.5*norm)*step + volatilityEffect);  // vérifier que le drift envoyé en bien r0

    return nextValue;
}


double RiskyDynamics::getDrift() const {
    return drift;
}

PnlVect* RiskyDynamics::getVolatilityVector() const {
    return pnl_vect_copy(volatilityVector);
}