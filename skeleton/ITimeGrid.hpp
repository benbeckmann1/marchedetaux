#ifndef ITIMEGRID_HPP
#define ITIMEGRID_HPP

#include <vector>
#include <cstddef>

class ITimeGrid {
private:
    std::vector<double> timePoints;  // Stocke les points de la grille temporelle

public:
    // Constructeur prenant une liste de dates
    ITimeGrid(const std::vector<double>& timePoints);

    // Renvoie la liste des dates
    const std::vector<double>& getTimePoints() const;

    // Renvoie la maturité (dernier point de la grille)
    double getMaturity() const;

    // Renvoie le nombre de points dans la grille
    int size() const;
};

#endif
