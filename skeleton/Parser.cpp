#include "Parser.hpp"
#include <iostream>
#include <iostream>
#include <map>
#include <string>
Parser::Parser(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "❌ Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        exit(1);
    }

    file >> dataJson;
    file.close();

    

    // Extraction des paramètres généraux
    NumberOfDaysInOneYear = dataJson["NumberOfDaysInOneYear"].get<double>();
    SampleNb = dataJson["SampleNb"].get<int>();
    RelativeFiniteDifferenceStep = dataJson["RelativeFiniteDifferenceStep"].get<double>();
    domesticCurrencyId = dataJson["DomesticCurrencyId"].get<std::string>();

    

    // Extraction des informations sur l'option
    auto jsonOption = dataJson["Option"];
    optionType = jsonOption["Type"].get<std::string>();
    maturity = jsonOption["MaturityInDays"].get<double>();

    // Extraction des dates de fixing
    auto jsonFixing = jsonOption["FixingDatesInDays"];
    fixingdatesType = jsonFixing["Type"].get<std::string>();

    
    if ( optionType != "foreign_asian") {
        auto dateData = jsonFixing["DatesInDays"].get<std::vector<double>>();
        DatesInDays = pnl_vect_create(dateData.size());
        for (size_t i = 0; i < dateData.size(); i++) {
            LET(DatesInDays, i) = dateData[i];
        }
    }

    // Extraction des paramètres de l'oracle de rebalancement
    auto jsonOracle = dataJson["PortfolioRebalancingOracleDescription"];
    rebalanceType = jsonOracle["Type"].get<std::string>();
    rebalanceperiod = jsonOracle["Period"].get<double>();

    // Extraction de la matrice de corrélation
    auto correlations = dataJson["Correlations"].get<std::vector<std::vector<double>>>();
    int size = correlations.size();
    correlationMatrix = pnl_mat_create(size, size);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            MLET(correlationMatrix, i, j) = correlations[i][j];

    pnl_mat_chol(this->correlationMatrix);
     // **Mapping des devises et des actifs**
    std::map<std::string, int> currenciesOrder;
    int order = 0;
    int nAsset = dataJson["Assets"].size();

    // Extraction des devises
    auto jsonCurrencies = dataJson["Currencies"];
    for (const auto& jsonCurrency : jsonCurrencies) {
        std::string currencyId = jsonCurrency["id"].get<std::string>();

        if (currencyId == domesticCurrencyId) {
            domesticInterest = jsonCurrency["InterestRate"].get<double>();
            currenciesOrder[currencyId] = order;
        } else {
            ForeignInterestRates.push_back(jsonCurrency["InterestRate"].get<double>());
            ForeignCurrencyVols.push_back(jsonCurrency["Volatility"].get<double>());
            currenciesOrder[currencyId] = order;
        }

        // Ajout dans le `std::vector` pour conserver l'ordre d'apparition
        currencyAssetGroups.emplace_back(currencyId, std::vector<int>{});

        order++;
    }

    // **Associer les actifs aux devises**
    auto jsonAssets = dataJson["Assets"];
    int assetIndex = 0;
    for (const auto& jsonAsset : jsonAssets) {
        std::string currencyId = jsonAsset["CurrencyId"].get<std::string>();
        assetsRealVols.push_back(jsonAsset["Volatility"].get<double>());
        assetCurrencyMapping.push_back(currenciesOrder[currencyId]);

        // Recherche de la devise dans le `vector` pour ajouter les actifs au bon endroit
        for (auto& pair : currencyAssetGroups) {
            if (pair.first == currencyId) {
                pair.second.push_back(assetIndex);
                break;
            }
        }
        assetIndex++;
    }
}

// std::vector<Currency*> Parser::generateCurrency() const {
//     std::vector<Currency*> currencyList;
    
//     for (size_t i = 0; i < ForeignInterestRates.size(); i++) {
//         PnlVect* corrRow = pnl_vect_create(correlationMatrix->m);
//         pnl_mat_get_row(corrRow, correlationMatrix, assetMapping.size() + i);

//         currencyList.push_back(new Currency(
//             ForeignInterestRates[i],  // Taux d'intérêt étranger
//             corrRow,                  // Volatilité et corrélation
//             ForeignInterestRates[i],  // Utilisation du même taux pour la devise étrangère
//             domesticInterest          // Taux d'intérêt domestique
//         ));
//     }

//     return currencyList;
// }

// **Affichage du mapping devise -> actifs**
void Parser::displayCurrencyAssetGroups() const {
    std::cout << "\n📌 Mapping des devises et actifs :\n";
    for (const auto& pair : currencyAssetGroups) {
        std::cout << "Devise : " << pair.first << " -> Actifs : ";
        for (int assetIndex : pair.second) {
            std::cout << assetIndex << " ";
        }
        std::cout << std::endl;
    }
}

void Parser::displayAssetMapping() const {
    std::cout << "\n📌 Asset Mapping :\n";
    for (size_t i = 0; i < assetCurrencyMapping.size(); i++) {
        std::cout << "Actif " << i << " -> Devise Index : " << assetCurrencyMapping[i] << std::endl;
    }
}


Parser::~Parser() {
    pnl_mat_free(&correlationMatrix);
    if( optionType != "foreign_asian"){
        pnl_vect_free(&DatesInDays);
    }
}

void Parser::displayData() const {
    std::cout << "📌 Nombre de jours dans une année : " << NumberOfDaysInOneYear << "\n";
    std::cout << "📌 Nombre d'échantillons : " << SampleNb << "\n";
    std::cout << "📌 Pas de différence finie : " << RelativeFiniteDifferenceStep << "\n";
    std::cout << "📌 Devise domestique : " << domesticCurrencyId << "\n\n";

    std::cout << "🎯 **Option** :\n";
    std::cout << "   - Type : " << optionType << "\n";
    std::cout << "   - Maturité (jours) : " << maturity << "\n";
    std::cout << "   - Type de Fixing Dates : " << fixingdatesType << "\n";
    std::cout << "   - Dates de Fixing : ";
    pnl_vect_print(DatesInDays);

    std::cout << "\n🔄 **Oracle de Rebalancement** :\n";
    std::cout << "   - Type : " << rebalanceType << "\n";
    std::cout << "   - Période : " << rebalanceperiod << " jours\n";

    std::cout << "\n🔗 Matrice de Corrélation :\n";
    pnl_mat_print(correlationMatrix);
}
