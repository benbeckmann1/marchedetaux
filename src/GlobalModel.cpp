#include "GlobalModel.hpp"

// Constructeur
GlobalModel::GlobalModel(std::vector<RiskyAsset*> assets, std::vector<Currency*> currencies, 
                         ITimeGrid* timeGrid, InterestRateModel domesticRate, double fdStep)
    : assets(std::move(assets)), currencies(std::move(currencies)), 
      monitoringTimeGrid(timeGrid), domesticInterestRate(domesticRate), fdStep(fdStep) {}

// Destructeur
GlobalModel::~GlobalModel() {               // on n'arrive pas à libérer la mémoire de tous les objets, il faudrait utiliser des std_unique_ptr...
    // delete monitoringTimeGrid;
    // for (RiskyAsset* asset : assets) {
    //     delete asset;
    // }
    // for (Currency* currency : currencies) {
    //     delete currency;
    // }
}


// Méthodes
void GlobalModel::simulatePaths(PnlMat* simulations, PnlMat* past, PnlVect* row, PnlVect* G, PnlRng* rng, int date) const {
    int nb_assets = assets.size();
    int nb_currencies = currencies.size();
    int N = monitoringTimeGrid->len();
    int currentDate = date;

    // Copie les valeurs passées dans simulations
    copyPast(simulations, past, row);

    if (monitoringTimeGrid->at(N-1) == date) { return;} // Si on est déjà à la dernière date, on ne fait rien

    int t = past->m - 1;    // Dernière date de la matrice past

    // Pour la première date si ce n'est pas une date de la grille de temps
    if (!monitoringTimeGrid->has(date)) {
        updateSim(simulations, G, rng, currentDate, t, nb_assets, nb_currencies, true);     // on écrase la valeur d'aujourd'hui par la nouvelle valeur
        currentDate = monitoringTimeGrid->at(t);                                            // on met à jour la date courante
    }
    

    // Boucle sur les dates restantes
    while (t < N-1) {
        updateSim(simulations, G, rng, currentDate, t, nb_assets, nb_currencies, false);   // on remplit la ligne d'après
        currentDate = monitoringTimeGrid->at(t+1);
        t++;
    }
}



void GlobalModel::copyPast(PnlMat* simulations, PnlMat* past, PnlVect* row) const { 
    for (int i = 0; i < past->m; i++) {
        pnl_mat_get_row(row, past, i);
        pnl_mat_set_row(simulations, row, i);
    }
}


void GlobalModel::updateSim(PnlMat* simulations, PnlVect* G, PnlRng* rng, int date, int t, int nb_assets, int nb_currencies, bool isFirstDate) const {
    int idx_nextDate = t + (isFirstDate ? 0 : 1);
    double step = static_cast<double>((monitoringTimeGrid->at(idx_nextDate) - date)) / static_cast<double>(domesticInterestRate.getNumberOfDaysInOneYear());
    pnl_vect_rng_normal(G, G->size, rng);
    for (int j = 0; j < nb_assets; j++) {   // Boucle sur les actifs
        RiskyAsset* asset = assets[j];
        double newValue = asset->sampleNextDate(G, step, MGET(simulations, t, j));
        MLET(simulations, idx_nextDate, j) = newValue;
    }
    for (int j = 0; j < nb_currencies; j++) {   // Boucle sur les devises
        Currency* currency = currencies[j];
        double newValue = currency->sampleNextDate(G, step, MGET(simulations, t, nb_assets+j));
        MLET(simulations, idx_nextDate, nb_assets + j) = newValue;
    }
}


void GlobalModel::shift_asset(PnlMat* shift_mat, int d, double fdStep, int idx_lastDate) const {
    for (int i = idx_lastDate; i < shift_mat->m; i++) {
        double original_value = pnl_mat_get(shift_mat, i, d);
        double bumped_value = original_value * (1 + fdStep);
        MLET(shift_mat, i, d) = bumped_value;
    }
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
