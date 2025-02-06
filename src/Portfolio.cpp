#include <iostream>
#include "Portfolio.hpp"
#include "json_reader.hpp"
#include <nlohmann/json.hpp> 

Position::Position(int date, double price, double priceStdDev, PnlVect* deltas, PnlVect* deltasStdDev, double portfolioValue)
    : date(date), price(price), priceStdDev(priceStdDev), portfolioValue(portfolioValue), deltas(deltas), deltasStdDev(deltasStdDev) {

}

void to_json(nlohmann::json &j, const Position &position) {
    j["date"] = position.date;
    j["value"] = position.portfolioValue;
    j["price"] = position.price;
    j["priceStdDev"] = position.priceStdDev;
    j["deltas"] = position.deltas;
    j["deltasStdDev"] = position.deltasStdDev;
}

void Position::print() const {
    nlohmann::json j = *this;
    std::cout << j.dump(4);
}

// Constructor Implementation
Portfolio::Portfolio(int date, int numberOfDayYear, PnlMat* market, PnlVect* delta, PnlVect* deltaStdev,
 double price, double priceStdev, double rate, ITimeGrid* monitoringTimeGrid) {
    
    date_ = 0;
    market_ = market;
    delta_ = delta;
    deltaStdev_ = deltaStdev;
    portfolioValue_ = price;
    rate_ = rate;
    monitoringTimeGrid = monitoringTimeGrid;
    
    PnlVect* spot = pnl_vect_create(market->n);
    pnl_mat_get_row(spot, market, 0);
    nonRiskyAsset_ = price - pnl_vect_scalar_prod(delta, spot);
    
    positions.emplace_back(Position(date, price, priceStdev, delta, deltaStdev, price));
}

double Portfolio::UpdatePortfolioValue(int CurrentDate, PnlVect* CurrentDelta, PnlMat *marketData) {
    // Calcul de la variation des poids des actifs risqués
    pnl_vect_minus_vect(delta_, CurrentDelta);

    PnlVect* spot = pnl_vect_create(marketData->n);
    pnl_mat_get_row(spot, marketData, CurrentDate);

    // Mise à jour de la quantité sans risque en tenant compte de l'évolution des actifs risqués et du taux d'intérêt
    nonRiskyAsset_ += pnl_vect_scalar_prod(delta_, spot);
    nonRiskyAsset_ *= exp(rate_ * (CurrentDate - date_) / numberOfDayYear_);

    // Mise à jour des poids des actifs risqués
    pnl_vect_clone(delta_, CurrentDelta);

    // Mise à jour de la date du portefeuille
    date_ = CurrentDate;

    // Calcul de la nouvelle valeur du portefeuille
    portfolioValue_ = pnl_vect_scalar_prod(delta_, spot) + nonRiskyAsset_;

    return portfolioValue_;
}


Portfolio::~Portfolio() {
}

