#pragma once

#include "Carreau.h"

class Grille
{
private:
    vector<Carreau*> carreaux;

public:
    Grille(int Ligne, int Colonne, double Hauteur, double Largeur);
    ~Grille();

    vector<Arrete*> getListArrete(Object* objects);
};