#include "Parser.hpp"

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



