#pragma once
#include "../Couleur/Couleur.h"

class Lumiere{
    Couleur* couleur;
    Vect position;
    Vect attenuation;

public:
    Lumiere(Couleur* CouleurLumiere,Vect LumierePosition,Vect Attenuation);
    ~Lumiere();

    Couleur* GetCouleur() const;
    Vect GetPosition() const;
    Vect GetAttenuation() const;
};