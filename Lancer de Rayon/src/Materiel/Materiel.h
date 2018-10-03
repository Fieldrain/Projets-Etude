#pragma once
#include "../Couleur/Couleur.h"
enum Type{Reflechissant,Transparent,Opaque};

class Materiel{
private: 
    Couleur* couleur;
    double shininess;
    Vect emission;
    Type typeObject;
public:
    Materiel(Couleur* CouleurParameter,Vect CouleurEmise,double Shininess, Type TypeObject);
    ~Materiel();

    Couleur* GetCouleurParameter() const;
    double GetShininess() const;
    Vect GetCouleurEmission() const;
    Type GetType() const;
};