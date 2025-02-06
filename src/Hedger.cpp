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
    if (argc != 4) {
        std::cerr << "Usage : " << argv[0] << " <fichier_json>   <fichier_csv>   <fichier_out> "  << std::endl;
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
    montecarlo.priceAndDelta(price, priceStdDev, delta, deltasStdDev, market, 0);
    
    std::cout << "Je suis la 0 " << std::endl;
    // Constructeur du Portfolio
    Portfolio* portfolio = new Portfolio(0, parser.getNumberOfDaysInOneYear(), market, delta,
     deltasStdDev, price, priceStdDev, parser.getInterestRateModel().getRate(), parser.getRebTimeGrid());
    
    std::cout << "Je suis la 1 " << std::endl;
    // calculer le portefeuille de couverture
    for(int date = 1; date < market->m; date++) {
            std::cout << "Je suis la 1.01 " << std::endl;
            if(portfolio->monitoringTimeGrid->has(date)){
                std::cout << "Je suis la 1.02 " << std::endl;
                PnlVect* deltaPortfolio = pnl_vect_create(market->n);
                PnlVect* deltaPortfolioStdDev = pnl_vect_create(market->n);
                std::cout << "Je suis la 1.1 " << std::endl;
                
                montecarlo.priceAndDelta(price, priceStdDev, deltaPortfolio, deltaPortfolioStdDev, market, date);
                std::cout << "Je suis la 1.2 " << std::endl;
                portfolio->positions.emplace_back(Position(date, price, priceStdDev,deltaPortfolio, deltaPortfolioStdDev, 
                portfolio->UpdatePortfolioValue(date, delta, market)));
                std::cout << "Je suis la 1.3 " << std::endl;
                pnl_vect_free(&deltaPortfolio);
                pnl_vect_free(&deltaPortfolioStdDev);
            }
    }
    std::cout << "Je suis la 2 " << std::endl;
    nlohmann::json jsonPortfolio = portfolio->positions;
    std::ofstream ifout(argv[3], std::ios_base::out);
    if (!ifout.is_open()) {
        std::cout << "Unable to open file " << argv[3] << std::endl;
        std::exit(1);
    }
    ifout << jsonPortfolio.dump(4);
    ifout.close();
    std::cout << "Je suis la 3" << std::endl;

    pnl_mat_free(&market);
    pnl_vect_free(&delta);
    pnl_vect_free(&deltasStdDev);
    return 0;
}