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

    // Initialise la matrice de simulation
    int idx_lastDate = 0;
    PnlMat* simulations = initPath(market, date, idx_lastDate);

    // Crée des matrices pour stocker les simulations shiftées
    PnlMat *shift_moins = pnl_mat_create_from_zero(simulations->m, simulations->n);
    PnlMat *shift_plus = pnl_mat_create_from_zero(simulations->m, simulations->n);
    PnlVect* spots = pnl_vect_create(simulations->n);
    pnl_mat_get_row(spots, market, date);

    // Crée un vecteur gaussien
    PnlVect* G = vectGaussian(simulations->n);  // pas sur de ce que je fais !!
   
    // Boucle sur le nombre de tirages Monte Carlo
    for (int i = 0; i < sampleNb; i++) {
        computeSumPrice(simulations, G, date, idx_lastDate, price, priceStdDev); 
        computeSumDeltas(simulations, shift_plus, shift_moins, spots, date, idx_lastDate, delta, deltasStdDev); // implem,eter le bon spot frr
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



void MonteCarlo::computeSumPrice(PnlMat* simulations, PnlVect* G, int date, int idx_lastDate, double& price, double& priceStdDev) const {

        model.asset(simulations, G, date, idx_lastDate);    // Simulation d'une trajectoire
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