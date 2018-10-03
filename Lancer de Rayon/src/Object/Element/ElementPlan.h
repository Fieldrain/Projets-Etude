#pragma once

#include "Element.h"

class ElementPlan : public Element {
private:
    Vect PointC;
    Vect NormalPlan;

public:
    PointIntersection CalculIntersection(Rayon* rayon,map<string,double> calculs);
    Vect Normal(PointIntersection point);
    void Affiche();
    
    ElementPlan(Vect pointC,Vect normalPlan);
    ~ElementPlan();
};
