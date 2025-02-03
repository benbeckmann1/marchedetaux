#ifndef INTEREST_RATE_MODEL_HPP
#define INTEREST_RATE_MODEL_HPP

class InterestRateModel {
private:
    double rate;  // Taux d'intérêt constant

public:
    // Constructeur
    InterestRateModel(double rate);

    // Renvoie le taux d'intérêt
    double getRate() const;

    // Calcule le facteur d'actualisation entre t1 et t2 : exp(-r * (t2 - t1))
    double discountFactor(double t1, double t2) const;

    // Calcule l'accumulation entre t1 et t2 : exp(r * (t2 - t1))
    double accumulationFactor(double t1, double t2) const;
};

#endif
