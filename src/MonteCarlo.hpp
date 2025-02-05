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

    // Initialise la matrice de simulation
    PnlMat* initPath(PnlMat* market, int date, int& idx_lastDate) const;

    // Copie la matrice de marché et la colle à la fin de la matrice de simulation
    void copyPast(PnlMat* simulations, int& idx_pastDate, int nb_assets, int nb_currencies, PnlMat* market, int date) const;

    // Génère un vecteur gaussien
    PnlVect* vectGaussian(int sizeRisky) const;

    // Calcule les deltas
    void computeDeltas(PnlMat* simulations, PnlVect* delta, PnlVect* deltasStdDev) const;


};

#endif // MONTECARLO_HPP
