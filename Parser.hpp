#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <pnl/pnl_matrix.h>

struct Currency {
    std::string id;
    double interestRate;
    double volatility;
    double spot;
    double drift;
};

struct Asset {
    std::string currencyId;
    double volatility;
    double spot;
    double drift;
};

struct FixingDates {
    std::string type;
    std::vector<int> dates;
};

struct Option {
    std::string type;
    FixingDates fixingDates;
    double strike;
    std::vector<double> weights;
    int maturityDays;
};

struct Rebalancing {
    std::string type;
    int period;
};

class Parser {
public:
    std::string domesticCurrencyId;
    std::vector<Currency> currencies;
    std::vector<Asset> assets;
    Option option;
    Rebalancing rebalancing;
    PnlMat* correlations;
    int numberOfDaysInYear;
    int sampleNb;
    double relativeFiniteDifferenceStep;
    
    Parser(const std::string& filename);
    ~Parser();
    void printData() const;
};

#endif
