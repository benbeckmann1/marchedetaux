#pragma once

#include <list>
#include "MonteCarlo.hpp"
#include "Grid/FixedTimeGrid.hpp"
#include "Grid/ListTimeGrid.hpp"
#include <nlohmann/json.hpp>

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
    std::list<Position> positions;

    int date_;
    const MonteCarlo& monteCarlo;
    ITimeGrid* rebalancingTimeGrid;
    double cash;              // Montant en cash du portefeuille
    double portfolioValue;    // Valeur totale du portefeuille
    PnlMat* marketdata;

    // Constructor
    Portfolio(int date, const MonteCarlo& monteCarlo, ITimeGrid* monitoringTimeGrid, PnlMat* marketdata);

    ~Portfolio();

    double UpdatePortfolioValue(int CurrentDate, PnlVect* CurrentDelta, PnlMat* marketdata);
};