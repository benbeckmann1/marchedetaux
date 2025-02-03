#include "Parser.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage : " << argv[0] << " <fichier_json>" << std::endl;
        return 1;
    }

    // Création du parser et extraction des données
    Parser parser(argv[1]);
    
    // Affichage des données pour vérifier que tout fonctionne
    parser.printData();

    return 0;
}



