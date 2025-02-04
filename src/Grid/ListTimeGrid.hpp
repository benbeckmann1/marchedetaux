#ifndef LISTTIMEGRID_HPP
#define LISTTIMEGRID_HPP

#include "ITimeGrid.hpp"
#include <vector>

class ListTimeGrid : public ITimeGrid {
private:
    std::vector<int> timePoints;
public:
    ListTimeGrid(const std::vector<int>& dates);
    int at(int index) const override;
    int len() const override;
    bool has(int nDays) const override;
};

#endif // LISTTIMEGRID_HPP
