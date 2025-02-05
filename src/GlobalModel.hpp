#ifndef GLOBALMODEL_HPP
#define GLOBALMODEL_HPP

#include <vector>
#include "Risky/RiskyAsset.hpp"
#include "Risky/Currency.hpp"
#include "Grid/ITimeGrid.hpp"
#include "InterestRateModel.hpp"
#include <pnl/pnl_matrix.h>


class GlobalModel {
private:
    std::vector<RiskyAsset*> assets;         // Liste des actifs risqués
    std::vector<Currency*> currencies;       // Liste des devises
    ITimeGrid* monitoringTimeGrid;          // Grille de temps pour le suivi
    InterestRateModel domesticInterestRate; // Modèle de taux domestique
    double fdStep;                          // Pas de différence finie

public:
    // Constructeur
    GlobalModel(std::vector<RiskyAsset*> assets, std::vector<Currency*> currencies, 
                ITimeGrid* timeGrid, InterestRateModel domesticRate);

    // Destructeur
    ~GlobalModel();

    // Accesseurs
    const std::vector<RiskyAsset*>& getAssets() const;
    const std::vector<Currency*>& getCurrencies() const;
    const ITimeGrid* getTimeGrid() const;
    const InterestRateModel& getDomesticInterestRate() const;
    const double getFdStep() const;

    // Méthodes
    void asset(PnlMat* simulations, PnlVect* G, int date, int idx_lastDate) const;
    void updateSim(PnlMat* simulations, PnlVect* G, int date, int t, int nb_assets, int nb_currencies) const;
    void shift_asset(PnlMat* shift_mat, int d, double fdStep, int idx_lastDate) const;

};

#endif // GLOBALMODEL_HPP
