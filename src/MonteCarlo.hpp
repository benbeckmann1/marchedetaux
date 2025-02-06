#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include "Options/Option.hpp"
#include "GlobalModel.hpp"
#include <iostream>
#include <cmath>
#include <pnl/pnl_vector.h>
#include <pnl/pnl_matrix.h>
#include <pnl/pnl_random.h>

class MonteCarlo {
private:
    Option* option;     // Pointeur vers l'option à évaluer
    GlobalModel model;  // Modèle global contenant les actifs et taux
    int sampleNb;      // Nombre de tirages Monte Carlo

public:
    // Constructeur
    MonteCarlo(Option* option, const GlobalModel& model, int sampleNb);

    // Destructeur
    ~MonteCarlo();

    // Calcule le prix de l'option et les deltas
    void priceAndDelta(double& price, double& priceStdDev, PnlVect* delta, PnlVect* deltasStdDev, PnlMat* market, int date);

    // Crée la matrice past
    void createPast(PnlMat* past, int nb_tot_assets, PnlMat* market, int date) const;

    // Génère un vecteur gaussien
    void vectGaussian(PnlVect* G) const;

    void computeSumPrice(PnlMat* simulations, double& price, double& priceStdDev) const;
    void computeSumDeltas(PnlMat* simulations, PnlMat* shift_plus, PnlMat* shift_moins, PnlVect* spots, int date, int idx_lastDate, PnlVect* delta, PnlVect* deltasStdDev) const;

    void finalPrice(double& price, double& priceStdDev, int date) const;
    void finalDelta(PnlVect* delta, PnlVect* deltasStdDev, int date) const;


};

#endif // MONTECARLO_HPP
