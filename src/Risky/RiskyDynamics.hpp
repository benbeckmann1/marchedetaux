#ifndef RISKYDYNAMICS_HPP
#define RISKYDYNAMICS_HPP

#include "pnl/pnl_vector.h"

class RiskyDynamics {
protected:
    double drift;              // Dérive du processus
    PnlVect* volatilityVector; // Vecteur des volatilités

public:
    // Constructeur et destructeur
    RiskyDynamics(double drift, PnlVect *volatility);
    virtual ~RiskyDynamics();

    // Méthode virtuelle pour générer la prochaine valeur du processus
    double sampleNextDate(PnlVect *G, double step, double currentValue);

    // Getters
    double getDrift() const;
    PnlVect* getVolatilityVector() const;
};

#endif // RISKYDYNAMICS_HPP
