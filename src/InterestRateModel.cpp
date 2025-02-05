// InterestRateModel.cpp
#include "InterestRateModel.hpp"
#include <cmath>  // Pour exp()

// Constructeur
InterestRateModel::InterestRateModel(double rate, int numberOfDaysInOneYear) : rate(rate), numberOfDaysInOneYear(numberOfDaysInOneYear) {}

// Renvoie le taux d'intérêt
double InterestRateModel::getRate() const {
    return rate;
}

// Calcule le facteur d'actualisation : exp(-r * (t2 - t1))
double InterestRateModel::discountFactor(double t1, double t2) const {
    return std::exp(-rate * (t2 - t1)/numberOfDaysInOneYear);
}

// Calcule l'accumulation entre t1 et t2 : exp(r * (t2 - t1))
double InterestRateModel::accumulationFactor(double t1, double t2) const {
    return std::exp(rate * (t2 - t1)/numberOfDaysInOneYear);
}

// Getter pour le nombre de jours ouvrés dans une année
int InterestRateModel::getNumberOfDaysInOneYear() const {
    return numberOfDaysInOneYear;
}
