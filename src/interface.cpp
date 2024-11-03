#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int playerNb(){
    int a;
    while (true) {
        cout << "Entrez le nombre de joueurs (entre 2 et 9) : ";
        cin >> a;

        if (a >= 2 && a <= 4) {
            cout << "20x20" << endl;
            break;
        } else if (a >= 5 && a <= 9) {
            cout << "30x30" << endl;
            break;
        } else {
            cout << "Nombre invalide. Veuillez réessayer." << endl;
        }
    }
    return a;
}

void start() {
    int a;
    a = playerNb();
}

void afficherCouleursDisponibles(const vector<string>& couleurs) {
    cout << "Couleurs disponibles :\n";
    for (size_t i = 0; i < couleurs.size(); ++i) {
        cout << i + 1 << ". " << couleurs[i] << "\n";
    }
    cout << "Votre choix (entrez le numéro correspondant) : ";
}

int choisirCouleur(const vector<string>& couleurs, unordered_set<int>& couleursChoisies) {
    int choix;
    while (true) {
        afficherCouleursDisponibles(couleurs);
        cin >> choix;
        
        // Vérifie si le choix est valide et si la couleur n'a pas été déjà choisie
        if (choix >= 1 && choix <= static_cast<int>(couleurs.size()) && couleursChoisies.find(choix) == couleursChoisies.end()) {
            couleursChoisies.insert(choix); // Marque la couleur comme choisie
            return choix;
        } else {
            cout << "Choix invalide ou couleur déjà choisie. Veuillez essayer de nouveau.\n";
        }
    }
}

int main() {
    // Liste des couleurs avec leurs codes ANSI
    vector<string> couleurs = {
        "\033[31mRouge\033[0m",   // Rouge
        "\033[34mBleu\033[0m",    // Bleu
        "\033[32mVert\033[0m",    // Vert
        "\033[33mJaune\033[0m",   // Jaune
        "\033[35mMagenta\033[0m", // Magenta
        "\033[36mCyan\033[0m",    // Cyan
        "\033[37mBlanc\033[0m",   // Blanc
        "\033[90mGris\033[0m",    // Gris
        "\033[91mRose\033[0m"     // Rose
    };

    // Ensemble pour garder trace des couleurs déjà choisies
    unordered_set<int> couleursChoisies;

    // Boucle jusqu'à ce que toutes les couleurs aient été choisies
    while (couleursChoisies.size() < couleurs.size()) {
        int choix = choisirCouleur(couleurs, couleursChoisies);

        // Affiche le message avec la couleur choisie
        cout << couleurs[choix - 1] << "Vous avez choisi la couleur : " 
                  << couleurs[choix - 1].substr(5, couleurs[choix - 1].size() - 9) 
                  << "!\033[0m\n";
    }

    cout << "Toutes les couleurs ont été choisies!\n";
    return 0;
}
