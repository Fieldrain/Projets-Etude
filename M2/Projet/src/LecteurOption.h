#ifndef LECTEUROPTION_H
#define LECTEUROPTION_H

#include "GestionRegex.h"

enum Repere{DEUXD,TROISD};

struct OptionScene{
    string cheminFichier;
    int iterationModele;
    int iterationTangente;
    Repere repere;
    bool showTangente = false;
    string fragShader;
    string vertShader;
    string cheminTextures;
};

using namespace std;

class LecteurOption{
private:
    ifstream fichier;

public:
    LecteurOption();
    ~LecteurOption();

    void Ouvrir();
    OptionScene Lire();
    void Fermer();
};

#endif