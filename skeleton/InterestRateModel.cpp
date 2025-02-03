#include "InterestRateModel.hpp"
#include <cmath>

// Constructeur
InterestRateModel::InterestRateModel(double rate) : rate(rate) {}

// Renvoie le taux d'intérêt
double InterestRateModel::getRate() const {
    return rate;
}

// Facteur d'actualisation
double InterestRateModel::discountFactor(double t1, double t2) const {
    return std::exp(-rate * (t2 - t1));
}

// Facteur d'accumulation
double InterestRateModel::accumulationFactor(double t1, double t2) const {
    return std::exp(rate * (t2 - t1));
}
