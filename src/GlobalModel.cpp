#include "GlobalModel.hpp"

// Constructeur
GlobalModel::GlobalModel(std::vector<RiskyAsset*> assets, std::vector<Currency*> currencies, 
                         ITimeGrid* timeGrid, InterestRateModel domesticRate)
    : assets(std::move(assets)), currencies(std::move(currencies)), 
      monitoringTimeGrid(timeGrid), domesticInterestRate(domesticRate) {}

// Destructeur
GlobalModel::~GlobalModel() {
    delete monitoringTimeGrid; // Libère la mémoire de la grille de temps
}

// Accesseurs
const std::vector<RiskyAsset*>& GlobalModel::getAssets() const {
    return assets;
}

const std::vector<Currency*>& GlobalModel::getCurrencies() const {
    return currencies;
}

const ITimeGrid* GlobalModel::getTimeGrid() const {
    return monitoringTimeGrid;
}

const InterestRateModel& GlobalModel::getDomesticInterestRate() const {
    return domesticInterestRate;
}

const double GlobalModel::getFdStep() const {
    return fdStep;
}



// Méthodes
void GlobalModel::asset(PnlMat* simulations, PnlVect* G, int date, int idx_lastDate) const {
    int nb_assets = assets.size();
    int nb_currencies = currencies.size();
    int N = monitoringTimeGrid->len();
    int currentDate = date;

    if (monitoringTimeGrid->at(N-1) == date) {            // si on est à la date de maturité, on n'a pas besoin de simuler, la matrice est déjà remplie
        return;
    }

    int t = idx_lastDate;

    // Pour la première date si ce n'est pas une date de la grille de temps
    if (!monitoringTimeGrid->has(date)) {
        updateSim(simulations, G, date, t, nb_assets, nb_currencies);     // on écrase la valeur d'aujourd'hui par la nouvelle valeur
    }

    // Boucle sur les dates restantes
    while (t < N-1) {
        updateSim(simulations, G, date, t+1, nb_assets, nb_currencies);   // on remplit la ligne d'après
        t++;
    }
}


void GlobalModel::updateSim(PnlMat* simulations, PnlVect* G, int date, int t, int nb_assets, int nb_currencies) const {
    for (int j = 0; j < nb_assets; j++) {   // Boucle sur les actifs
        RiskyAsset* asset = assets[j];
        double step = (monitoringTimeGrid->at(t) - date) / domesticInterestRate.getNumberOfDaysInOneYear();
        double newValue = asset->sampleNextDate(G, step, MGET(simulations, t, j));
        MLET(simulations, t, j) = newValue;
    }
    for (int j = 0; j < nb_currencies; j++) {   // Boucle sur les devises
        Currency* currency = currencies[j];
        double step = (monitoringTimeGrid->at(t) - date) / domesticInterestRate.getNumberOfDaysInOneYear();
        double newValue = currency->sampleNextDate(G, step, MGET(simulations, t, nb_assets+j));
        MLET(simulations, t, nb_assets+j) = newValue;
    }
}


void GlobalModel::shift_asset(PnlMat* shift_mat, int d, double fdStep, int idx_lastDate) const {
    for (int i = idx_lastDate; i < shift_mat->m; i++) {
        double original_value = pnl_mat_get(shift_mat, i, d);
        double bumped_value = original_value * (1 + fdStep);
        pnl_mat_set(shift_mat, i, d, bumped_value);
    }
}
