// ITimeGrid.hpp
#ifndef ITIMEGRID_HPP
#define ITIMEGRID_HPP

class ITimeGrid {
public:
    virtual int at(int index) = 0;
    virtual int len() = 0;
    virtual bool has(int nDays) = 0;
};

#endif // ITIMEGRID_HPP