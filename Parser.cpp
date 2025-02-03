#include "Parser.hpp"

Parser::Parser(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier JSON." << std::endl;
        exit(1);
    }

    nlohmann::json jsonData;
    file >> jsonData;
    file.close();

    // Extraction de la devise domestique
    domesticCurrencyId = jsonData.at("DomesticCurrencyId").get<std::string>();

    // Extraction des devises
    for (const auto& currencyJson : jsonData.at("Currencies")) {
        Currency currency;
        currency.id = currencyJson.at("id").get<std::string>();
        currency.interestRate = currencyJson.at("InterestRate").get<double>();
        currency.volatility = currencyJson.value("Volatility", 0.0);
        currency.spot = currencyJson.value("Spot", 0.0);
        currency.drift = currencyJson.value("Drift", 0.0);
        currencies.push_back(currency);
    }

    // Extraction des actifs
    for (const auto& assetJson : jsonData.at("Assets")) {
        Asset asset;
        asset.currencyId = assetJson.at("CurrencyId").get<std::string>();
        asset.volatility = assetJson.at("Volatility").get<double>();
        asset.spot = assetJson.value("Spot", 0.0);
        asset.drift = assetJson.value("Drift", 0.0);
        assets.push_back(asset);
    }

    // Extraction de l'option
    option.type = jsonData.at("Option").at("Type").get<std::string>();
    option.fixingDates.type = jsonData.at("Option").at("FixingDatesInDays").at("Type").get<std::string>();
    option.fixingDates.dates = jsonData.at("Option").at("FixingDatesInDays").value("DatesInDays", std::vector<int>());
    option.strike = jsonData.at("Option").value("Strike", 0.0);
    option.maturityDays = jsonData.at("Option").at("MaturityInDays").get<int>();
    option.weights = jsonData.at("Option").value("Weights", std::vector<double>());

    // Extraction du rebalancement
    rebalancing.type = jsonData.at("PortfolioRebalancingOracleDescription").at("Type").get<std::string>();
    rebalancing.period = jsonData.at("PortfolioRebalancingOracleDescription").at("Period").get<int>();

    // Extraction de la matrice de corrélation sous format PnlMat
    std::vector<std::vector<double>> correlationData = jsonData.at("Correlations").get<std::vector<std::vector<double>>>();
    int size = correlationData.size();
    correlations = pnl_mat_create(size, size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            MLET(correlations, i, j) = correlationData[i][j];
        }
    }

    // Extraction des paramètres de simulation
    numberOfDaysInYear = jsonData.at("NumberOfDaysInOneYear").get<int>();  // Ajouté
    sampleNb = jsonData.at("SampleNb").get<int>();
    relativeFiniteDifferenceStep = jsonData.at("RelativeFiniteDifferenceStep").get<double>();
}

// Destructeur pour libérer la mémoire de PnlMat
Parser::~Parser() {
    pnl_mat_free(&correlations);
}

// Fonction pour afficher les données
void Parser::printData() const {
    std::cout << "📌 Devise domestique : " << domesticCurrencyId << "\n\n";

    std::cout << "📌 Devises :\n";
    for (const auto& c : currencies) {
        std::cout << "- " << c.id << " | r = " << c.interestRate 
                  << " | Vol = " << c.volatility << " | Spot = " << c.spot 
                  << " | Drift = " << c.drift << "\n";
    }

    std::cout << "\n📌 Actifs Risqués :\n";
    for (const auto& a : assets) {
        std::cout << "- Devise : " << a.currencyId << " | Vol = " << a.volatility 
                  << " | Spot = " << a.spot << " | Drift = " << a.drift << "\n";
    }

    std::cout << "\n📌 Option :\n";
    std::cout << "- Type : " << option.type << "\n";
    std::cout << "- Fixing Dates Type : " << option.fixingDates.type << "\n";
    std::cout << "- Fixing Dates : ";
    for (int date : option.fixingDates.dates) std::cout << date << " ";
    std::cout << "\n- Strike : " << option.strike << "\n";
    std::cout << "- Maturité : " << option.maturityDays << " jours\n";
    std::cout << "- Weights : ";
    for (double w : option.weights) std::cout << w << " ";
    std::cout << "\n";

    std::cout << "\n📌 Rebalancing :\n";
    std::cout << "- Type : " << rebalancing.type << "\n";
    std::cout << "- Période : " << rebalancing.period << " jours\n";

    std::cout << "\n📌 Corrélations :\n";
    pnl_mat_print(correlations);

    std::cout << "\n📌 Simulation :\n";
    std::cout << "- Nombre de jours dans une année : " << numberOfDaysInYear << "\n";
    std::cout << "- Échantillons Monte Carlo : " << sampleNb << "\n";
    std::cout << "- Pas de différences finies : " << relativeFiniteDifferenceStep << "\n";
}
