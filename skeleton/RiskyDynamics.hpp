#ifndef RISKY_DYNAMICS_HPP
#define RISKY_DYNAMICS_HPP

#include <pnl/pnl_vector.h>

class RiskyDynamics {
protected:
    double drift;               // Dérive (taux de rendement)
    PnlVect* volatilityVector;  // Vecteur de volatilités

public:
    RiskyDynamics(double drift, const PnlVect* volatilityVector);
    virtual ~RiskyDynamics();

    virtual double sampleNextDate(double dt, double dW) const = 0;  // Méthode virtuelle pure

    double getDrift() const;
    const PnlVect* getVolatilityVector() const;
};

#endif
