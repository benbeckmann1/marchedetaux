#include "RiskyDynamics.hpp"
#include <pnl/pnl_vector.h>

RiskyDynamics::RiskyDynamics(double drift, const PnlVect* volatilityVector) 
    : drift(drift) {
    this->volatilityVector = pnl_vect_copy(volatilityVector);
}

RiskyDynamics::~RiskyDynamics() {
    pnl_vect_free(&volatilityVector);
}

double RiskyDynamics::getDrift() const {
    return drift;
}

const PnlVect* RiskyDynamics::getVolatilityVector() const {
    return volatilityVector;
}
