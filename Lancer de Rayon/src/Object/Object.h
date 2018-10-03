#pragma once
#include "Englobant/Englobant.h"
#include "Element/Element.h"
#include "../Materiel/Materiel.h"
#include <vector>

using namespace std;

class Object{

private:
    Englobant* englobant;
    Element* element;
    Materiel* materiel;

public:
    Retour_Calcul In(Rayon* rayon);
    PointIntersection CalculIntersection(Rayon* rayon,map<string,double> calculs);
    Vect Normal(PointIntersection point);
    void Affiche();
    
    Materiel* GetMateriel() const;

    Object(Element* ElementObject, Englobant* EnglobantObject, Materiel* MaterielObject);
    ~Object();
};