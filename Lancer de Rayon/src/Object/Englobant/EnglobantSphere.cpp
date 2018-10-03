#include "EnglobantSphere.h"

EnglobantSphere::EnglobantSphere(double Radius,Vect Center) : RayonSphere(Radius),Centre(Center){

}

EnglobantSphere::~EnglobantSphere(){

}

Retour_Calcul EnglobantSphere::In(Rayon* rayon){
    Retour_Calcul r_c;

    double a =  1;

    double b = (2*(rayon->GetOrigin()[0] - Centre[0])*rayon->GetDirection()[0]) + (2*(rayon->GetOrigin()[1] - Centre[1])*rayon->GetDirection()[1]) + (2*(rayon->GetOrigin()[2] - Centre[2])*rayon->GetDirection()[2]);

    double c = pow(rayon->GetOrigin()[0] - Centre[0], 2) + pow(rayon->GetOrigin()[1] - Centre[1], 2) + pow(rayon->GetOrigin()[2] - Centre[2], 2) - (RayonSphere*RayonSphere);

    double D = b*b - 4*a*c;

    r_c.dedans = D>=0;
    r_c.calculs["c"] = c;
    r_c.calculs["a"] = a;
    r_c.calculs["b"] = b;
    r_c.calculs["D"] = D;

    return r_c;
}