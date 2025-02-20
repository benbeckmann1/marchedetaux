#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <pnl/pnl_matrix.h>
#include <pnl/pnl_vector.h>
#include "Risky/Currency.hpp"
#include "Risky/RiskyAsset.hpp"
#include "InterestRateModel.hpp"
#include "Options/Option.hpp"
#include "Options/OptionBasket.hpp"
#include "Options/OptionCallCurrency.hpp"
#include "Options/OptionCallQuanto.hpp"
#include "Options/OptionForeignAsian.hpp"
#include "Options/OptionForeignPerfBasket.hpp"
#include "Options/OptionQuantoExchange.hpp"
#include "Grid/FixedTimeGrid.hpp"
#include "Grid/ListTimeGrid.hpp"
#include <unordered_map>
#include "GlobalModel.hpp"
#include "MonteCarlo.hpp"

class Parser {
private:
    nlohmann::json dataJson;
    
    PnlMat* correlationMatrix;
    int SampleNb;
    double RelativeFiniteDifferenceStep;
    std::string domesticCurrencyId;
    int NumberOfDaysInOneYear;

    //Option
    std::string optionType;
    // double strike;
    int maturity;
    // PnlVect* weights;
    std::string fixingdatesType;
    PnlVect* DatesInDays;

    //Oracle
    std::string rebalanceType;
    int rebalanceperiod;

    // Asset & Currencies
    InterestRateModel domesticInterest;
    std::vector<InterestRateModel> ForeignInterestRates;

    std::vector<double> ForeignCurrencyVols;
    std::vector<double> assetsRealVols;
    std::vector<double> assetDrift;
    std::vector<int> assetCurrencyMapping;
    // std::vector<std::pair<std::string, std::vector<int>>> currencyAssetGroups;

    ITimeGrid* monitoringTimeGrid;
    

public:
    explicit Parser(const std::string& filename);
    ~Parser();

    std::vector<Currency*> generateCurrency() const;
    std::vector<RiskyAsset*> generateRiskyAssets() const;
    Option* CreateOption();
    GlobalModel CreateGlobalModel();
    std::vector<int> computeNbAssetsPerCurrency() const;

    // Getter pour sampleNb
    int getSampleNb() const;



};

#endif
