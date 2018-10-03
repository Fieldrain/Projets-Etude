#pragma once
#include <GL/freeglut.h>
#include <map>
#include "../../Rayon/Rayon.h"

using namespace std;

struct PointIntersection{
    Vect CoordPoint;
    bool Double = false;
    double T = std::numeric_limits<double>::infinity();
    double Distance = std::numeric_limits<double>::infinity();
    int IndexObjet = -1;
    void clear(){
        CoordPoint = Vect(0,0,0);
        T = std::numeric_limits<double>::infinity();
        Distance = std::numeric_limits<double>::infinity();
        IndexObjet = -1;
    }
};

class Element{

public:
    virtual PointIntersection CalculIntersection(Rayon* rayon,map<string,double> calculs) = 0;
    virtual Vect Normal(PointIntersection point) = 0;
    virtual void Affiche() = 0;

    Element(){}
    virtual ~Element(){}
};