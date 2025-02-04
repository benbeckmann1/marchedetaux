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
#include "Currency.hpp"
#include "RiskyAsset.hpp"
#include "InterestRateModel.hpp"
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
    std::vector<int> assetCurrencyMapping;
    std::vector<std::pair<std::string, std::vector<int>>> currencyAssetGroups;

    

public:
    explicit Parser(const std::string& filename);
    ~Parser();

    // std::vector<Currency*> createCurrencyList();
    // std::vector<RiskyAsset*> createRiskyAssetList();
    void displayData() const;
    void displayCurrencyAssetGroups() const;
    void displayAssetMapping() const; 
    std::vector<Currency*> generateCurrency() const;

};

#endif
