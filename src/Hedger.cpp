#include "Parser.hpp"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage : " << argv[0] << " <fichier_json>" << std::endl;
        return 1;
    }

    // Création du parser et extraction des données
    Parser parser(argv[1]);

    
    // Affichage des données pour vérifier que tout fonctionne
    //parser.displayData();
    // parser.displayCurrencyAssetGroups();
    // parser.displayAssetMapping();


   // Génération des RiskyAssets
    // std::vector<RiskyAsset*> riskyAssets = parser.generateRiskyAssets();

    // // Affichage des RiskyAssets
    // std::cout << "\n📌 Liste des RiskyAssets générés :\n";
    // for (size_t i = 0; i < riskyAssets.size(); i++) {
    //     std::cout << "RiskyAsset " << i << " : " << std::endl;
    //     std::cout << "   - Drift : " << riskyAssets[i]->drift << std::endl;
    //     std::cout << "   - Domestic Interest Rate : " << riskyAssets[i]->domesticInterestRate.getRate() << std::endl;

    //     std::cout << "   - Volatility Vector : \n";
    //     pnl_vect_print(riskyAssets[i]->volatilityVector);
    // }

    // // Nettoyage mémoire
    // for (auto asset : riskyAssets) {
    //     delete asset;
    // }


    // std::cout << " ##############################################################" << std::endl;
    // std::cout << " ##############################################################" << std::endl;
    // // Génération du vecteur de Currency
    // std::vector<Currency*> currencies = parser.generateCurrency();

    // // Affichage du vecteur de Currency
    // std::cout << "\n📌 Liste des devises générées :\n";
    // for (size_t i = 0; i < currencies.size(); i++) {
    //     std::cout << "Devise " << i << " : " << std::endl;
    //     std::cout << "   - Foreign Interest Rate : " << currencies[i]->foreignInterestRate.getRate() << std::endl;
    //     std::cout << "   - Domestic Interest Rate : " << currencies[i]->domesticInterestRate.getRate() << std::endl;
        
    //     std::cout << "   - Volatility Vector : ";
    //     pnl_vect_print(currencies[i]->volatilityVector);
    // }

    // Nettoyage mémoire
    // for (auto currency : currencies) {
    //     delete currency;
    // }

    return 0;
}


void MarketDomestic(PnlMat* market, std::vector<int> nbAssetsPerCurrency, std::vector<InterestRateModel> foreignInterestRates) {
    int idx_sumAsset = nbAssetsPerCurrency[0];
    int nbRiskyAssets = std::accumulate(nbAssetsPerCurrency.begin(), nbAssetsPerCurrency.end(), 0); // pour avoir l'indice de la première monnaie étrangère

    PnlVect* colAsset = pnl_vect_create_from_zero(market->m);
    PnlVect* colCurrency = pnl_vect_create_from_zero(market->m);
    for (int idx_currency = 0; idx_currency<foreignInterestRates.size(); idx_currency++) {
        int n_i = nbAssetsPerCurrency[idx_currency + 1];
        for (int idx_asset = 0; idx_asset<n_i; idx_asset++) {
            // Multiplier la colone de l'actif par la colonne du taux de change
            pnl_mat_get_col(colAsset, market, idx_sumAsset + idx_asset);
            pnl_mat_get_col(colCurrency, market, nbRiskyAssets + idx_currency);
            pnl_vect_mult_vect_term(colAsset, colCurrency);
            pnl_mat_set_col(market, colAsset, idx_sumAsset + idx_asset);
        }
        idx_sumAsset += n_i;

        // Pour chaque date (t) de la colonne currency on multiplie par exp(r_f * t) terme à terme
        for (int t = 0; t<market->m; t++) {
            LET(colCurrency, t) = GET(colCurrency, t) * foreignInterestRates[idx_currency].accumulationFactor(0, t);
        }
        pnl_mat_set_col(market, colCurrency, nbRiskyAssets + idx_currency);
    }
}