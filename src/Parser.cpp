#include "Parser.hpp"
#include <iostream>
#include <iostream>
#include <map>
#include <string>

// Constructeur
Parser::Parser(const std::string& filename) : domesticInterest(0.0, 365), monitoringTimeGrid(nullptr) 
 {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << " Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        exit(1);
    }

    file >> dataJson;
    file.close();

    // Extraction des paramètres généraux
    NumberOfDaysInOneYear = dataJson["NumberOfDaysInOneYear"].get<int>();
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

    pnl_mat_chol(correlationMatrix);


     // **Mapping des devises et des actifs**
    std::map<std::string, int> currenciesOrder;
    int order = 0;
    int nAsset = dataJson["Assets"].size();

    // Extraction des devises
    auto jsonCurrencies = dataJson["Currencies"];
    for (const auto& jsonCurrency : jsonCurrencies) {
        std::string currencyId = jsonCurrency["id"].get<std::string>();

        if (currencyId == domesticCurrencyId) {
            double rate = jsonCurrency["InterestRate"].get<double>();
            domesticInterest = InterestRateModel(jsonCurrency["InterestRate"].get<double>(), NumberOfDaysInOneYear);
            currenciesOrder[currencyId] = order;
        } else {
            ForeignInterestRates.emplace_back(jsonCurrency["InterestRate"].get<double>(), NumberOfDaysInOneYear);
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
        assetDrift.push_back(jsonAsset["Drift"].get<double>());
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



// Destructeur 
Parser::~Parser() {
    // Libération de la matrice de corrélation si elle a été allouée
    if (correlationMatrix) {
        pnl_mat_free(&correlationMatrix);
        correlationMatrix = nullptr;
    }

    // // Libération du vecteur de dates si alloué
    // if (DatesInDays) {
    //     pnl_vect_free(&DatesInDays);
    //     DatesInDays = nullptr;
    // }

    // Libération de la grille de temps si allouée
    if (monitoringTimeGrid) {
        delete monitoringTimeGrid;
        monitoringTimeGrid = nullptr;
    }
}




std::vector<Currency*> Parser::generateCurrency() const {
    std::vector<Currency*> currencyList;
    
    PnlVect* corrRow = pnl_vect_create(correlationMatrix->m);
    for (size_t i = 0; i < ForeignInterestRates.size(); i++) {
        pnl_mat_get_row(corrRow, correlationMatrix, assetCurrencyMapping.size() +i);
        pnl_vect_mult_scalar(corrRow,ForeignCurrencyVols[i]);

        currencyList.push_back(new Currency(
            domesticInterest.getRate(),  // Taux d'intérêt étranger
            corrRow,                  // Volatilité et corrélation
            ForeignInterestRates[i],  // Utilisation du même taux pour la devise étrangère
            domesticInterest          // Taux d'intérêt domestique
        ));
    }
    pnl_vect_free(&corrRow);
    return currencyList;
}

std::vector<RiskyAsset*> Parser::generateRiskyAssets() const {
    std::vector<RiskyAsset*> riskyAssets;
    std::vector<Currency*> currencies = generateCurrency();

    PnlVect* corrRow = pnl_vect_create(correlationMatrix->m);
    for (size_t i = 0; i < assetsRealVols.size(); i++) {
        
        pnl_mat_get_row(corrRow, correlationMatrix, i);
        pnl_vect_mult_scalar(corrRow,assetsRealVols[i]);

        if (assetCurrencyMapping[i] != 0){
            pnl_vect_plus_vect(corrRow, currencies[assetCurrencyMapping[i]-1]->getVolatilityVector()); // vérifier l'addition des vects
        }


        // Création de l'actif risqué
        riskyAssets.push_back(new RiskyAsset(
            domesticInterest.getRate(),   // drift de l'actif
            corrRow,             // sigma*L
            domesticInterest    // Taux domestique
        ));
    }
    pnl_vect_free(&corrRow);
    return riskyAssets;
}


Option* Parser::CreateOption() {
    if (optionType.empty()) {
        std::cerr << "❌ Erreur : Type d'option non défini !" << std::endl;
        exit(1);
    }

    double strike = 0.0;
    if (dataJson["Option"].contains("Strike")) {
        strike = dataJson["Option"]["Strike"].get<double>();
    }

    if (fixingdatesType == "Fixed") {
        int period = dataJson["Option"]["FixingDatesInDays"].at("Period").get<int>();
        monitoringTimeGrid = new FixedTimeGrid(period, maturity);
    } else {
        monitoringTimeGrid = new ListTimeGrid(DatesInDays);
    }

    std::vector<int> nbAssetsPerCurrency = computeNbAssetsPerCurrency();

    if (optionType == "basket") {
        std::vector<double> weights = dataJson["Option"]["Weights"].get<std::vector<double>>();

        return new OptionBasket(nbAssetsPerCurrency, ForeignInterestRates, domesticInterest, *monitoringTimeGrid, weights, strike, maturity);
    } 
    else if (optionType == "call_currency") {
        return new OptionCallCurrency(nbAssetsPerCurrency, ForeignInterestRates, domesticInterest, *monitoringTimeGrid, strike, maturity);
    } 
    else if (optionType == "call_quanto") {
        return new OptionCallQuanto(nbAssetsPerCurrency, ForeignInterestRates, domesticInterest, *monitoringTimeGrid, strike, maturity);
    } 
    else if (optionType == "foreign_asian") {
        return new OptionForeignAsian(nbAssetsPerCurrency, ForeignInterestRates, domesticInterest, *monitoringTimeGrid, maturity);
    } 
    else if (optionType == "foreign_perf_basket") {
        return new OptionForeignPerfBasket(nbAssetsPerCurrency, ForeignInterestRates, domesticInterest, *monitoringTimeGrid, strike, maturity);
    } 
    else if (optionType == "quanto_exchange") {
        return new OptionQuantoExchange(nbAssetsPerCurrency, ForeignInterestRates, domesticInterest, *monitoringTimeGrid, strike, maturity);
    } 
    else {
        std::cerr << " Erreur : Type d'option inconnu (" << optionType << ") !" << std::endl;
        exit(1);
    }
}

GlobalModel Parser::CreateGlobalModel() {
    std::vector<RiskyAsset*> assets = generateRiskyAssets();
    std::vector<Currency*> currencies = generateCurrency();
    return GlobalModel(assets, currencies, monitoringTimeGrid, domesticInterest, RelativeFiniteDifferenceStep);
}

void Parser::displayNbAssetsPerCurrency() const {
    std::vector<int> nbAssetsPerCurrency = computeNbAssetsPerCurrency();

    std::cout << "\n📌 Nombre d'actifs par devise : ";
    for (int count : nbAssetsPerCurrency) {
        std::cout << count << " ";
    }
    std::cout << std::endl;
}


std::vector<int> Parser::computeNbAssetsPerCurrency() const {
    if (assetCurrencyMapping.empty()) {
        return {0};
    }

    // Trouver le nombre de devises distinctes (max index + 1)
    int maxCurrencyIndex = *std::max_element(assetCurrencyMapping.begin(), assetCurrencyMapping.end()) + 1;
    std::vector<int> nbAssetsPerCurrency(maxCurrencyIndex, 0);

    // Compter le nombre d'actifs par devise
    for (int currencyIndex : assetCurrencyMapping) {
        nbAssetsPerCurrency[currencyIndex]++;
    }

    return nbAssetsPerCurrency;
}




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

// Getter
int Parser::getSampleNb() const {
    return SampleNb;
}