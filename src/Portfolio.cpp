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

Portfolio::Portfolio(int date, const MonteCarlo& monteCarlo, ITimeGrid* monitoringTimeGrid, PnlMat* marketdata) // enlever le paramètre monitoringTimeGrid ?
    : date_(date), monteCarlo_(monteCarlo), rebalancingTimeGrid_(monitoringTimeGrid) {
    
    double price;
    double priceStdDev;

    // Création des vecteurs delta et deltaStdev
    PnlVect* delta = pnl_vect_create(marketdata->n);
    PnlVect* deltasStdDev = pnl_vect_create(marketdata->n);
    
    // Création du vecteur delta_
    delta_ = pnl_vect_create(marketdata->n);
    
    // Calcul du prix et des deltas avec MonteCarlo
    monteCarlo.priceAndDelta(price, priceStdDev, delta, deltasStdDev, marketdata, 0);

    // Récupérer le spot initial (première ligne du marché)
    PnlVect* spot = pnl_vect_create(marketdata->n);
    pnl_mat_get_row(spot, marketdata, 0);

    pnl_vect_clone(delta_, delta); 

    cash_ = price - pnl_vect_scalar_prod(delta, spot);

    // Ajouter la première position au portefeuille
    positions_.emplace_back(Position(date, price, priceStdDev, delta, deltasStdDev, price));
 
    // std::cout << price << std::endl;
    // std::cout << priceStdDev << std::endl;
    // pnl_vect_print_asrow(delta);
    // pnl_vect_print_asrow(deltasStdDev);


    // Nettoyage des objets temporaires
    pnl_vect_free(&spot);
    pnl_vect_free(&delta);
    pnl_vect_free(&deltasStdDev);
}


// Destructeur
Portfolio::~Portfolio() {
    for (auto position : positions_) {
        pnl_vect_free(&position.deltas);
        pnl_vect_free(&position.deltasStdDev);
    }
}

double Portfolio::GetPortfolioValue(int CurrentDate, PnlVect* spot) {
    double cash = cash_ * monteCarlo_.getOption()->getDomesticInterestRate().discountFactor(date_, CurrentDate);
    double portfolioValue = pnl_vect_scalar_prod(delta_, spot) + cash;

    return portfolioValue;
}


void Portfolio::UpdatePortfolio(int CurrentDate, PnlVect* CurrentDelta, PnlVect* spot) {
    cash_ = GetPortfolioValue(CurrentDate, spot) - pnl_vect_scalar_prod(CurrentDelta, spot);
    pnl_vect_clone(delta_, CurrentDelta);
    date_ = CurrentDate;
}

// double Portfolio::UpdatePortfolioValue(int CurrentDate, PnlVect* CurrentDelta, PnlMat* marketData) {
//     //Calcul de la variation des poids des actifs risqués
    
//     pnl_vect_minus_vect(delta, CurrentDelta);

//     PnlVect* spot = pnl_vect_create(marketData->n);
//     pnl_mat_get_row(spot, marketData, CurrentDate);

//     // Mise à jour de la quantité sans risque en tenant compte de l'évolution des actifs risqués et du taux d'intérêt
//     cash += pnl_vect_scalar_prod(delta, spot);
//     cash *= exp(rate_ * (CurrentDate - date) / numberOfDayYear_);

//     // Mise à jour des poids des actifs risqués
//     pnl_vect_clone(delta_, CurrentDelta);

//     // Mise à jour de la date du portefeuille
//     date = CurrentDate;

//     // Calcul de la nouvelle valeur du portefeuille
//     portfolioValue = pnl_vect_scalar_prod(delta_, spot) + cash;

//     return portfolioValue;
// }
