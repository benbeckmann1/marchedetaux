// Option.hpp
#ifndef OPTION_HPP
#define OPTION_HPP

#include <vector>
#include "InterestRateModel.hpp"
#include "ITimeGrid.hpp"

class Option {
public:
    std::vector<int> assetCurrencyMapping;
    std::vector<InterestRateModel> foreignInterestRates;
    InterestRateModel domesticInterestRate;
    ITimeGrid monitoringTimeGrid;
    virtual double payoff() = 0;
};

#endif // OPTION_HPP