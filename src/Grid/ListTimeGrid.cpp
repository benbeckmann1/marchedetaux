#include "ListTimeGrid.hpp"
#include <algorithm> // Pour std::find

ListTimeGrid::ListTimeGrid(const std::vector<int>& dates) : timePoints(dates) {}

int ListTimeGrid::at(int index) const {
    return timePoints[index];
}

int ListTimeGrid::len() const {
    return timePoints.size();
}

bool ListTimeGrid::has(int nDays) const {
    return std::find(timePoints.begin(), timePoints.end(), nDays) != timePoints.end();
}
