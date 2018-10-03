#pragma once
#include "../Vecteur/Vecteur.h"

enum TypeCouleur{Diffuse,Speculaire,Ambient};

class Couleur{
private: 
    Vect V_Speculaire;
    Vect V_Diffuse;
    Vect V_Ambient;

public:
    Couleur(Vect couleurSpeculaire, Vect couleurDiffuse, Vect couleurAmbient);
    ~Couleur();

    Vect GetValue(TypeCouleur type) const;
    Vect GetSum() const;

    Couleur operator+(const Couleur c);
    void operator+=(const Couleur c);

    friend ostream& operator<<(ostream& os, const Couleur& c);
};