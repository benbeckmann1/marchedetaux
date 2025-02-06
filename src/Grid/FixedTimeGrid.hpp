#ifndef FIXEDTIMEGRID_HPP
#define FIXEDTIMEGRID_HPP

#include "ITimeGrid.hpp"
#include <vector>

class FixedTimeGrid : public ITimeGrid {
private:
    int period_; 
    int maturity_;

public:
    FixedTimeGrid(int period, int maturity);
    
    int at(int index) const override;
    int len() const override;
    bool has(int nDays) const override;
};

#endif // FIXEDTIMEGRID_HPP
