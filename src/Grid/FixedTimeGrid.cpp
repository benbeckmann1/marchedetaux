#include "FixedTimeGrid.hpp"
#include <algorithm>  // Pour std::find

// Constructeur : génère automatiquement les dates
FixedTimeGrid::FixedTimeGrid(int start, int end, int step) 
    : start(start), end(end), step(step) {
    for (int t = start; t <= end; t += step) {
        timePoints.push_back(t);
    }
}

// Renvoie la valeur du temps à l'index donné
int FixedTimeGrid::at(int index) const {
    return timePoints[index];
}

// Renvoie le nombre total de points de la grille
int FixedTimeGrid::len() const {
    return timePoints.size();
}

// Vérifie si une date spécifique existe dans la grille
bool FixedTimeGrid::has(int nDays) const {
    return std::find(timePoints.begin(), timePoints.end(), nDays) != timePoints.end();
}
