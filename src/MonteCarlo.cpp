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

    // Variables
    int nb_dates = model.getTimeGrid()->len();
    int nb_tot_assets = model.getAssets().size() + model.getCurrencies().size();

    // Création matrice past
    PnlMat* past = pnl_mat_create_from_zero(1, nb_tot_assets);
    createPast(past, nb_tot_assets, market, date);

    // Ligne de spots
    PnlVect* spots = pnl_vect_create(nb_tot_assets);
    pnl_mat_get_row(spots, market, date);

    // Initialise la matrice de simulation
    PnlMat* simulations = pnl_mat_create(nb_dates, nb_tot_assets);

    // Crée des matrices pour stocker les simulations shiftées
    PnlMat *shift_moins = pnl_mat_create_from_zero(simulations->m, simulations->n);
    PnlMat *shift_plus = pnl_mat_create_from_zero(simulations->m, simulations->n);

    // Crée un vecteur gaussien
    PnlRng* rng = pnl_rng_create(PNL_RNG_MERSENNE);
    pnl_rng_sseed(rng, time(NULL));
    PnlVect* G = pnl_vect_create(simulations->n);
   
    // Boucle sur le nombre de tirages Monte Carlo
    for (int i = 0; i < sampleNb; i++) {
        model.simulatePaths(simulations, past, G, rng, date); 

        computeSumPrice(simulations, price, priceStdDev); 
        computeSumDeltas(simulations, shift_plus, shift_moins, spots, date, past->m-1, delta, deltasStdDev); 
    }

    finalPrice(price, priceStdDev, date);
    finalDelta(delta, deltasStdDev, date);

    pnl_mat_free(&simulations);
    pnl_mat_free(&shift_plus);
    pnl_mat_free(&shift_moins);
    pnl_vect_free(&spots);
    pnl_vect_free(&G);
    std::cout << "Simulation terminée." << std::endl;
}




void MonteCarlo::createPast(PnlMat* past, int nb_tot_assets, PnlMat* market, int date) const {
    int t = 0;
    int pastDate = model.getTimeGrid()->at(t);
    PnlVect* row = pnl_vect_create(nb_tot_assets);

    pnl_mat_get_row(row, market, date);                    
    pnl_mat_set_row(past, row, t);

    while (pastDate < date) {               
        pnl_mat_get_row(row, market, pastDate);                    
        pnl_mat_add_row(past, t, row);
        pastDate = model.getTimeGrid()->at(++t);
    }
    pnl_vect_free(&row);
}


// void MonteCarlo::initPath(PnlMat* simulations, PnlMat* market, int date, int& idx_lastDate) const {
//     // Crée une matrice pour stocker les tirages Monte Carlo
//     int nb_assets = model.getAssets().size();
//     int nb_currencies = model.getCurrencies().size();

//     createPast(simulations, idx_lastDate, nb_assets, nb_currencies, market, date);

//     // Remplir la ligne de la matrice avec les valeurs initiales
//     for (int i = 0; i < nb_assets; i++) {
//         pnl_mat_set(simulations, idx_lastDate, i, pnl_mat_get(market, date, i));
//     }
//     for (int i = 0; i < nb_currencies; i++) {
//         pnl_mat_set(simulations, idx_lastDate, nb_assets + i, pnl_mat_get(market, date, nb_assets + i));
//     }
// }


void MonteCarlo::computeSumPrice(PnlMat* simulations, double& price, double& priceStdDev) const {

        double payoff = option->payoff(simulations);        // Calcul du payoff de l'option
        price += payoff;                     
        priceStdDev += payoff * payoff;
}



void MonteCarlo::computeSumDeltas(PnlMat* simulations, PnlMat* shift_plus, PnlMat* shift_moins, PnlVect* spots, int date, int idx_lastDate, PnlVect* delta, PnlVect* deltasStdDev) const {

    for (int d = 0; d < simulations->n; d++) {
        pnl_mat_clone(shift_moins, simulations);
        pnl_mat_clone(shift_plus, simulations);
        model.shift_asset(shift_plus, d, model.getFdStep(), idx_lastDate);
        model.shift_asset(shift_moins, d, -model.getFdStep(), idx_lastDate);
        double payoff_plus = option->payoff(shift_plus);
        double payoff_minus = option->payoff(shift_moins);

        LET(delta, d) += (payoff_plus - payoff_minus) / GET(spots, d);
        // LET(deltasStdDev, d) += pow((payoff_plus - payoff_minus), 2) / (2*model.getFdStep()) - pow((payoff_plus - payoff_minus)/(2*model.getFdStep()), 2);
    }
}

void MonteCarlo::finalPrice(double& price, double& priceStdDev, int date) const {
    price /= sampleNb;
    double var_payoff = (priceStdDev / sampleNb) - (price * price);

    price *= model.getDomesticInterestRate().discountFactor(date, option->getMaturity());
    priceStdDev = model.getDomesticInterestRate().discountFactor(date, option->getMaturity()) * sqrt(var_payoff) / sqrt(sampleNb);
}

void MonteCarlo::finalDelta(PnlVect* delta, PnlVect* deltasStdDev, int date) const {
    pnl_vect_mult_scalar(delta, option->getDomesticInterestRate().discountFactor(date, option->getMaturity()) / (2 * model.getFdStep() * sampleNb));
    // pnl_vect_mult_scalar(deltasStdDev, option->getDomesticInterestRate().discountFactor(date, option->getMaturity()) / (2 * model.getFdStep() * sampleNb));
}