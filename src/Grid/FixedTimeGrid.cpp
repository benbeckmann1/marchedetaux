#include "FixedTimeGrid.hpp"
#include <iostream>

// Constructeur : génère automatiquement les dates
FixedTimeGrid::FixedTimeGrid(int period, int maturity) : period_(period), maturity_(maturity) {
}

// Renvoie la valeur du temps à l'index donné
int FixedTimeGrid::at(int index) const {
    if (index < 0 || index >= len()) {
        throw std::out_of_range("Index " + std::to_string(index) + " hors limites dans FixedTimeGrid::at (max : " + std::to_string(len() - 1) + ")");
    }
    return (index)*period_;
}

// Renvoie le nombre total de points de la grille
int FixedTimeGrid::len() const {
    return int(maturity_ / period_) + 1;
}

// Vérifie si une date spécifique existe dans la grille
bool FixedTimeGrid::has(int nDays) const {
    // if (nDays == 0) {
    //     return false;
    // }   
    return nDays % period_ == 0 && nDays <= maturity_;
}
