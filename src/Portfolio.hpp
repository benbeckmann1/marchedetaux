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
    int numberOfDayYear_;
    PnlMat* market_;
    PnlVect* delta_;
    PnlVect* deltaStdev_;
    double nonRiskyAsset_;
    double portfolioValue_;
    double price_;
    double priceStdev_;
    double rate_;
    ITimeGrid* monitoringTimeGrid;

    // Constructor
    Portfolio(int date, int numberOfDayYear, PnlMat* market, PnlVect* delta, PnlVect* deltaStdev, double price,
     double priceStdev, double rate, ITimeGrid* monitoringTimeGrid);

    ~Portfolio();

    double UpdatePortfolioValue(int CurrentDate, PnlVect* CurrentDelta, PnlMat* marketdata);
};
