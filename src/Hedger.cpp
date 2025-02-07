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
    // if (argc != 4) {
    //     std::cerr << "Usage : " << argv[0] << " <fichier_json>   <fichier_csv>   <fichier_out> "  << std::endl;
    //     return 1;
    // }
    Parser parser(argv[1]);
    PnlMat *market = pnl_mat_create_from_file(argv[2]);

    Option* opt = parser.CreateOption();
    GlobalModel model = parser.CreateGlobalModel();
    MonteCarlo montecarlo = MonteCarlo(opt, model, parser.getSampleNb());
    MarketDomestic(market, parser.computeNbAssetsPerCurrency(), opt->getForeignInterestRates());
    PnlVect* spot = pnl_vect_create(market->n);

    Portfolio* portfolio = new Portfolio(0, montecarlo, parser.getRebTimeGrid(), market);

    double price;
    double priceStdDev;

    std::vector<PnlVect*> deltaVector;
    std::vector<PnlVect*> deltaStdDevVector;
    //calculer le portefeuille de couverture
    for(int date = 1; date < market->m; date++) {

        if(portfolio->rebalancingTimeGrid_->has(date)){
            
            PnlVect* deltaPortfolio = pnl_vect_create(market->n);
            PnlVect* deltaPortfolioStdDev = pnl_vect_create(market->n);
            
            montecarlo.priceAndDelta(price, priceStdDev, deltaPortfolio, deltaPortfolioStdDev, market, date);  
            pnl_mat_get_row(spot, market, date);
            portfolio->UpdatePortfolio(date, deltaPortfolio, spot);
            double portfolioValue = portfolio->GetPortfolioValue(date, spot);
            portfolio->positions_.emplace_back(Position(date, price, priceStdDev,deltaPortfolio, deltaPortfolioStdDev, portfolioValue));

            // pnl_vect_free(&deltaPortfolio);
            // pnl_vect_free(&deltaPortfolioStdDev);
            deltaVector.push_back(deltaPortfolio);
            deltaStdDevVector.push_back(deltaPortfolioStdDev);
        }
    }

    // for (Position position : portfolio->positions_) {
    //     position.print();
    // }
    // nlohmann::json jsonPortfolio = portfolio->positions_;
    // std::ofstream ifout(argv[3], std::ios_base::out);
    // if (!ifout.is_open()) {
    //     std::cout << "Unable to open file " << argv[3] << std::endl;
    //     std::exit(1);
    // }
    // ifout << jsonPortfolio.dump(4);
    // ifout.close();

    pnl_mat_free(&market);
    pnl_vect_free(&spot);
    for (PnlVect* vect : deltaVector) {
        pnl_vect_free(&vect);
    }   
    for (PnlVect* vect : deltaStdDevVector) {
        pnl_vect_free(&vect);
    }
    return 0;
}