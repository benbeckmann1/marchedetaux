// InterestRateModel.hpp
#ifndef INTERESTRATEMODEL_HPP
#define INTERESTRATEMODEL_HPP

class InterestRateModel {
public:
    double discount(double t1, double t2);
    double account(double t1, double t2);
};

#endif // INTERESTRATEMODEL_HPP