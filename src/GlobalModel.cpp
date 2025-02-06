#include "GlobalModel.hpp"

// Constructeur
GlobalModel::GlobalModel(std::vector<RiskyAsset*> assets, std::vector<Currency*> currencies, 
                         ITimeGrid* timeGrid, InterestRateModel domesticRate)
    : assets(std::move(assets)), currencies(std::move(currencies)), 
      monitoringTimeGrid(timeGrid), domesticInterestRate(domesticRate) {}

// Destructeur
GlobalModel::~GlobalModel() {
    // // Libération des actifs risqués
    // for (RiskyAsset* asset : assets) {
    //     if (asset) {
    //         delete asset;
    //     }
    // }
    // assets.clear(); // Nettoie le vecteur

    // // Libération des devises
    // for (Currency* currency : currencies) {
    //     delete currency;
    // }
    // currencies.clear(); // Nettoie le vecteur

    // // Libération de la grille de temps si elle a été allouée dynamiquement
    // if (monitoringTimeGrid) {
    //     delete monitoringTimeGrid;
    //     monitoringTimeGrid = nullptr;
    // }
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
void GlobalModel::simulatePaths(PnlMat* simulations, PnlMat* past, PnlVect* G, PnlRng* rng, int date) const {
    int nb_assets = assets.size();
    int nb_currencies = currencies.size();
    int N = monitoringTimeGrid->len();
    int currentDate = date;

    // Copie les valeurs passées dans simulations
    copyPast(simulations, past);

    if (monitoringTimeGrid->at(N-1) == date) { return;} // Si on est déjà à la dernière date, on ne fait rien

    int t = past->m - 1;    // Dernière date de la matrice past

    // Pour la première date si ce n'est pas une date de la grille de temps
    if (!monitoringTimeGrid->has(date)) {
        updateSim(simulations, G, rng, date, t, nb_assets, nb_currencies);     // on écrase la valeur d'aujourd'hui par la nouvelle valeur
    }

    // Boucle sur les dates restantes
    while (t < N-1) {
        updateSim(simulations, G, rng, date, t+1, nb_assets, nb_currencies);   // on remplit la ligne d'après
        t++;
    }
}



void GlobalModel::copyPast(PnlMat* simulations, PnlMat* past) const { // mieux de faire des copies de PnlVect ou copier chaque élément avec des boucles ?
    PnlVect* row = pnl_vect_create(simulations->n);
    for (int i = 0; i < past->m; i++) {
        pnl_mat_get_row(row, past, i);
        pnl_mat_set_row(simulations, row, i);
    }
    pnl_vect_free(&row);
}


void GlobalModel::updateSim(PnlMat* simulations, PnlVect* G, PnlRng* rng, int date, int t, int nb_assets, int nb_currencies) const {
    double step = static_cast<double>((monitoringTimeGrid->at(t) - date)) / static_cast<double>(domesticInterestRate.getNumberOfDaysInOneYear());
    pnl_vect_rng_normal(G, G->size, rng);

    for (int j = 0; j < nb_assets; j++) {   // Boucle sur les actifs
        RiskyAsset* asset = assets[j];
        double newValue = asset->sampleNextDate(G, step, MGET(simulations, t, j));
        MLET(simulations, t, j) = newValue;
    }
    for (int j = 0; j < nb_currencies; j++) {   // Boucle sur les devises
        Currency* currency = currencies[j];
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
