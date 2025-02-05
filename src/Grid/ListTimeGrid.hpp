#ifndef LISTTIMEGRID_HPP
#define LISTTIMEGRID_HPP

#include "ITimeGrid.hpp"
#include <vector>
#include "pnl/pnl_vector.h"

class ListTimeGrid : public ITimeGrid {
private:
    PnlVect* datesInDays_;

public:
    ListTimeGrid(const PnlVect* datesInDays);

    ~ListTimeGrid();

    int at(int index) const override;
    int len() const override;
    bool has(int nDays) const override;
};

#endif // LISTTIMEGRID_HPP
