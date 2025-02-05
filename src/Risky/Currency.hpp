#ifndef CURRENCY_HPP
#define CURRENCY_HPP

#include "RiskyDynamics.hpp"
#include "../InterestRateModel.hpp"

class Currency : public RiskyDynamics {
private:
    InterestRateModel foreignInterestRate;  // Taux d'intérêt de la devise étrangère
    InterestRateModel domesticInterestRate; // Taux d'intérêt de la devise domestique

public:
    // Constructeur et destructeur
    Currency(double drift, PnlVect *volatility, InterestRateModel foreignRate, InterestRateModel domesticRate);
    ~Currency();

};

#endif // CURRENCY_HPP
