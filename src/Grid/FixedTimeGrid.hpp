#ifndef FIXEDTIMEGRID_HPP
#define FIXEDTIMEGRID_HPP

#include "ITimeGrid.hpp"
#include <vector>

class FixedTimeGrid : public ITimeGrid {
private:
    int start;                 // Premier jour de la grille
    int end;                   // Dernier jour de la grille
    int step;                  // Pas entre les points de la grille
    std::vector<int> timePoints; // Liste générée des dates

public:
    FixedTimeGrid(int start, int end, int step);
    
    int at(int index) const override;
    int len() const override;
    bool has(int nDays) const override;
};

#endif // FIXEDTIMEGRID_HPP
