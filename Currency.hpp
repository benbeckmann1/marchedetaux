// Currency.hpp
#ifndef CURRENCY_HPP
#define CURRENCY_HPP

#include "InterestRateModel.hpp"

class Currency {
public:
    InterestRateModel foreignInterestRate;
    InterestRateModel domesticInterestRate;
};

#endif // CURRENCY_HPP