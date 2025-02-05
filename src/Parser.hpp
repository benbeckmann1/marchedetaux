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
#include <unordered_map>

class Parser {
private:
    nlohmann::json dataJson;
    
    PnlMat* correlationMatrix;
    int SampleNb;
    double RelativeFiniteDifferenceStep;
    std::string domesticCurrencyId;
    double NumberOfDaysInOneYear;

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
    double domesticInterest;
    std::vector<double> ForeignInterestRates;
    std::vector<double> ForeignCurrencyVols;
    std::vector<double> assetsRealVols;
    std::vector<int> assetDrift;
    std::vector<int> assetCurrencyMapping;
    std::vector<std::pair<std::string, std::vector<int>>> currencyAssetGroups;

    

public:
    explicit Parser(const std::string& filename);
    ~Parser();

    void displayData() const;
    void displayCurrencyAssetGroups() const;
    void displayAssetMapping() const; 
    std::vector<Currency*> generateCurrency() const;
    std::vector<RiskyAsset*> generateRiskyAssets() const;
    //Option* CreateOption();


};

#endif
