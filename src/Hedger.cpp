#include "Parser.hpp"
#include <iostream>
#include <vector>

void MarketDomestic(PnlMat* market, std::vector<int> nbAssetsPerCurrency, std::vector<InterestRateModel> foreignInterestRates) {
    int idx_sumAsset = nbAssetsPerCurrency[0];
    int nbRiskyAssets = std::accumulate(nbAssetsPerCurrency.begin(), nbAssetsPerCurrency.end(), 0); // pour avoir l'indice de la première monnaie étrangère

    PnlVect* colAsset = pnl_vect_create_from_zero(market->m);
    PnlVect* colCurrency = pnl_vect_create_from_zero(market->m);

    for (int idx_currency = 0; idx_currency<foreignInterestRates.size(); idx_currency++) {
        if (nbRiskyAssets != 0) {
            int n_i = nbAssetsPerCurrency[idx_currency + 1];
            for (int idx_asset = 0; idx_asset<n_i; idx_asset++) {
                // Multiplier la colone de l'actif par la colonne du taux de change
                pnl_mat_get_col(colAsset, market, idx_sumAsset + idx_asset);
                pnl_mat_get_col(colCurrency, market, nbRiskyAssets + idx_currency);
                pnl_vect_mult_vect_term(colAsset, colCurrency);
                pnl_mat_set_col(market, colAsset, idx_sumAsset + idx_asset);
            }
            idx_sumAsset += n_i;
        }
        // Pour chaque date (t) de la colonne currency on multiplie par exp(r_f * t) terme à terme
        pnl_mat_get_col(colCurrency, market, nbRiskyAssets + idx_currency);
        for (int t = 0; t<market->m; t++) {
            LET(colCurrency, t) = GET(colCurrency, t) * foreignInterestRates[idx_currency].accumulationFactor(0, t);
        }
        pnl_mat_set_col(market, colCurrency, nbRiskyAssets + idx_currency);
    }
    pnl_vect_free(&colAsset);
    pnl_vect_free(&colCurrency);
}




int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage : " << argv[0] << " <fichier_json>   <fichier_csv" << std::endl;
        return 1;
    }
    Parser parser(argv[1]);
    PnlMat *market = pnl_mat_create_from_file(argv[2]);

    double price;
    double priceStdDev;
    PnlVect* delta = pnl_vect_create(market->n);
    PnlVect* deltasStdDev = pnl_vect_create(market->n);

    Option* opt = parser.CreateOption();
    GlobalModel model = parser.CreateGlobalModel();
    MonteCarlo montecarlo = MonteCarlo(opt, model, parser.getSampleNb());
    MarketDomestic(market, parser.computeNbAssetsPerCurrency(), opt->getForeignInterestRates());
    montecarlo.priceAndDelta(price, priceStdDev, delta, deltasStdDev, market, 52);

    std::cout << "\nPrice : " << price << std::endl;
    std::cout << "\nPrice Std Dev : " << priceStdDev << std::endl;
    std::cout << "\nDelta : ";
    pnl_vect_print_asrow(delta);
    std::cout << "\nDelta Std Dev : ";
    pnl_vect_print_asrow(deltasStdDev);

    pnl_mat_free(&market);
    pnl_vect_free(&delta);
    pnl_vect_free(&deltasStdDev);
    return 0;
}

