#pragma once

#include "Englobant.h"

class EnglobantPlan : public Englobant{
private:
    Vect PointC;
    Vect NormalPlan;

public:
    Retour_Calcul In(Rayon* rayon);

    EnglobantPlan(Vect pointC,Vect normalPlan);
    ~EnglobantPlan();
};