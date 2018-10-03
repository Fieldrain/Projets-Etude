#pragma once

#include "Englobant.h"

class EnglobantSphere : public Englobant{
private:
    float RayonSphere;
    Vect Centre;

public:
    Retour_Calcul In(Rayon* rayon);

    EnglobantSphere(double Radius,Vect Center);
    ~EnglobantSphere();
};