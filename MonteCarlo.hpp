// MonteCarlo.hpp
#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include "Option.hpp"
#include "GlobalModel.hpp"

class MonteCarlo {
public:
    Option *option;
    GlobalModel model;
    void priceAndDelta();
};

#endif // MONTECARLO_HPP