#pragma once

#include "Element.h"

class ElementSphere : public Element {
private:
    double RayonSphere;
    Vect Centre;

public:
    PointIntersection CalculIntersection(Rayon* rayon,map<string,double> calculs);
    Vect Normal(PointIntersection point);
    void Affiche();
    
    ElementSphere(double Radius,Vect Center);
    ~ElementSphere();
};
