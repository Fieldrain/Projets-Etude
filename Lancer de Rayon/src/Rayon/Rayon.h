#pragma once
#include "../Vecteur/Vecteur.h"

class Rayon{
private: 
    Vect Origin;
    Vect Direction;
    bool RayonSecondaire;

public:
    Vect GetOrigin();
    Vect GetDirection();
    bool IsSecondaire();

    Vect T(double t);

    Rayon(Vect OriginRayon,Vect DirectionRayon,bool Secondaire=false);
    ~Rayon();
};