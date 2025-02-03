// GlobalModel.hpp
#ifndef GLOBALMODEL_HPP
#define GLOBALMODEL_HPP

#include <vector>
#include "RiskyAsset.hpp"
#include "Currency.hpp"
#include "InterestRateModel.hpp"
#include "ITimeGrid.hpp"

class GlobalModel {
public:
    std::vector<RiskyAsset> assets;
    std::vector<Currency> currencies;
    ITimeGrid monitoringTimeGrid;
    InterestRateModel domesticInterestRate;
};

#endif // GLOBALMODEL_HPP