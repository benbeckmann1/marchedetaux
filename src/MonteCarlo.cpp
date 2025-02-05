#include "MonteCarlo.hpp"


// Constructeur
MonteCarlo::MonteCarlo(Option* option, const GlobalModel& model, int sampleNb) 
    : option(option), model(model), sampleNb(sampleNb) {}

// Destructeur
MonteCarlo::~MonteCarlo() {
    delete option;  // Libère la mémoire allouée à l'option
}



void MonteCarlo::priceAndDelta(double& price, double& priceStdDev, PnlVect* delta, PnlVect* deltasStdDev, PnlMat* market, int date) { // prednre une position directement en argument ?
    std::cout << "Calcul du prix et des deltas de l'option..." << std::endl;
    
    price = 0.0;
    priceStdDev = 0.0;
    pnl_vect_set_all(delta, 0.0); 
    pnl_vect_set_all(deltasStdDev, 0.0);

    // Initialise les sommes pour le calcul de la moyenne et de la variance
    double sum_payoff = 0.0;
    double sum_payoff_squared = 0.0;

    // Initialise la matrice de simulation
    int idx_lastDate = 0;
    PnlMat* simulations = initPath(market, date, idx_lastDate);

    // Crée un vecteur gaussien
    PnlVect* G = vectGaussian(simulations->n);  // pas sur de ce que je fais !!
   
    // Boucle sur le nombre de tirages Monte Carlo
    for (int i = 0; i < sampleNb; i++) {
        
        model.asset(simulations, G, date, idx_lastDate);    // Simulation d'une trajectoire
        double payoff = option->payoff(simulations);        // Calcul du payoff de l'option
        sum_payoff += payoff;                     
        sum_payoff_squared += payoff * payoff;
        computeDeltas(simulations, delta, deltasStdDev);


        
        // Calcule le delta de l'option
        //option->delta(path, delta);
    }

    double mean_payoff = sum_payoff / sampleNb;
    double var_payoff = (sum_payoff_squared / sampleNb) - (mean_payoff * mean_payoff);

    price = model.getDomesticInterestRate().discountFactor(date, option->getMaturity()) * mean_payoff;
    priceStdDev = model.getDomesticInterestRate().discountFactor(date, option->getMaturity()) * sqrt(var_payoff) / sqrt(sampleNb);


    pnl_mat_free(&simulations);;
    std::cout << "Simulation terminée." << std::endl;
}





PnlMat* MonteCarlo::initPath(PnlMat* market, int date, int& idx_lastDate) const {
    // Crée une matrice pour stocker les tirages Monte Carlo
    int nb_assets = model.getAssets().size();
    int nb_currencies = model.getCurrencies().size();

    int m = model.getTimeGrid()->len();
    int n = nb_assets + nb_currencies;
    

    PnlMat* simulation = pnl_mat_create(m, n);
    copyPast(simulation, idx_lastDate, nb_assets, nb_currencies, market, date);

    // Remplir la ligne de la matrice avec les valeurs initiales
    for (int i = 0; i < nb_assets; i++) {
        pnl_mat_set(simulation, idx_lastDate, i, pnl_mat_get(market, date, i));
    }
    for (int i = 0; i < nb_currencies; i++) {
        pnl_mat_set(simulation, idx_lastDate, nb_assets + i, pnl_mat_get(market, date, nb_assets + i));
    }

    return simulation;
}



void MonteCarlo::copyPast(PnlMat* simulation, int& idx_pastDate, int nb_assets, int nb_currencies, PnlMat* market, int date) const {
    // Remplir les lignes pour les dates passées souhaitées avec les valeurs du marché
    int pastDate = model.getTimeGrid()->at(0);
    while (pastDate < date) {                                      
        for (int i = 0; i < nb_assets; i++) {
            pnl_mat_set(simulation, idx_pastDate, i, pnl_mat_get(market, pastDate, i));
        }
        for (int i = 0; i < nb_currencies; i++) {
            pnl_mat_set(simulation, idx_pastDate, nb_assets + i, pnl_mat_get(market, pastDate, nb_assets + i));
        }
        pastDate = model.getTimeGrid()->at(++idx_pastDate);
    }
}


PnlVect* MonteCarlo::vectGaussian(int sizeRisky) const {
    // Crée un générateur de nombres aléatoires
    PnlRng* rng = pnl_rng_create(PNL_RNG_MERSENNE);
    pnl_rng_sseed(rng, time(NULL));  // Initialise le générateur avec la date actuelle
    PnlVect* G = pnl_vect_create(sizeRisky);
    pnl_vect_rng_normal_d(G, sizeRisky, rng); 

    pnl_rng_free(&rng);
    return G; 
}



void MonteCarlo::computeDeltas(PnlMat* simulations, PnlVect* delta, PnlVect* deltasStdDev) const {

}




// PnlMat* MonteCarlo::initPath(PnlMat* market, int date) const {
//     // Crée une matrice pour stocker les tirages Monte Carlo
//     int nb_assets = model.getAssets().size();
//     int nb_currencies = model.getCurrencies().size();

//     int m = nb_assets + nb_currencies;
//     int n = model.getTimeGrid()->len() + 1;

//     PnlMat* simulation = pnl_mat_create(m, n);

//     // Remplir les lignes pour les dates passées souhaitées avec les valeurs du marché
//     int pastDate = model.getTimeGrid()->at(0);
//     int idx_pastDate = 0;
//     while (pastDate <= date) {                                       // si pastDate = date on ecrira deux fois la même ligne
//         for (int i = 0; i < nb_assets; i++) {
//             pnl_mat_set(simulation, idx_pastDate, i, pnl_mat_get(market, pastDate, i));
//         }
//         for (int i = 0; i < nb_currencies; i++) {
//             pnl_mat_set(simulation, idx_pastDate, nb_assets + i, pnl_mat_get(market, pastDate, nb_assets + i));
//         }
//         pastDate = model.getTimeGrid()->at(++idx_pastDate);
//     }

//     // Remplir la ligne de la matrice avec les valeurs initiales
//     for (int i = 0; i < nb_assets; i++) {
//         pnl_mat_set(simulation, idx_pastDate, i, pnl_mat_get(market, date, i));
//     }
//     for (int i = 0; i < nb_currencies; i++) {
//         pnl_mat_set(simulation, idx_pastDate, nb_assets + i, pnl_mat_get(market, date, nb_assets + i));
//     }

//     return simulation;
// }