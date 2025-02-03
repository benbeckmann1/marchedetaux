#include "ITimeGrid.hpp"

// Constructeur
ITimeGrid::ITimeGrid(const std::vector<double>& timePoints) : timePoints(timePoints) {}

// Renvoie la liste des points temporels
const std::vector<double>& ITimeGrid::getTimePoints() const {
    return timePoints;
}

// Renvoie la maturité
double ITimeGrid::getMaturity() const {
    return timePoints.back();  // Dernier élément de la grille
}

// Renvoie la taille de la grille
int ITimeGrid::size() const {
    return timePoints.size();
}
