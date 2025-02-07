#pragma once

#include <list>
#include "MonteCarlo.hpp"
#include "Grid/FixedTimeGrid.hpp"
#include "Grid/ListTimeGrid.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include "json_reader.hpp"

class Position {
public:
    int date;
    PnlVect *deltas;
    PnlVect *deltasStdDev;
    double price;
    double priceStdDev;
    double portfolioValue;

    Position(int date, double price, double priceStdDev, PnlVect* deltas, PnlVect* deltasStdDev, double portfolioValue);
    friend void to_json(nlohmann::json &j, const Position &positions);
    void print() const;
};

class Portfolio {
public:
    const MonteCarlo& monteCarlo_;
    ITimeGrid* rebalancingTimeGrid_;
    std::list<Position> positions_;
    PnlVect* delta_;           // Vecteur de deltas
    double cash_;              // Montant en cash du portefeuille
    int date_;                 // Date du portefeuille
    
    // Constructor
    Portfolio(int date, const MonteCarlo& monteCarlo, ITimeGrid* monitoringTimeGrid, PnlMat* marketdata);

    ~Portfolio();

    void UpdatePortfolio(int CurrentDate, PnlVect* CurrentDelta, PnlVect* spot);
    double GetPortfolioValue(int CurrentDate, PnlVect* spot);
};