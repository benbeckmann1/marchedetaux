#ifndef RISKYDYNAMICS_HPP
#define RISKYDYNAMICS_HPP

#include "pnl/pnl_vector.h"
#include <iostream>
#include <cmath>


class RiskyDynamics {
protected:
    double drift;             
    PnlVect* volatilityVector; 

public:
    // Constructeur et destructeur
    RiskyDynamics(double drift, PnlVect *volatility);
    virtual ~RiskyDynamics();

    // Méthode de simulation du prochain prix
    double sampleNextDate(PnlVect *G, double step, double currentValue);

    // Getters
    double getDrift() const;
    PnlVect* getVolatilityVector() const;
};

#endif // RISKYDYNAMICS_HPP
