#include "ElementSphere.h"
#include <iostream>

using namespace std;

ElementSphere::ElementSphere(double Radius,Vect Center) : RayonSphere(Radius),Centre(Center){

}

ElementSphere::~ElementSphere(){
    
}

PointIntersection ElementSphere::CalculIntersection(Rayon* rayon,map<string,double> calculs){
    double b,c,a,D;

    if(calculs["b"])
        b =  calculs["b"];
    else
        b =  (2*(rayon->GetOrigin()[0] - Centre[0])*rayon->GetDirection()[0]) + (2*(rayon->GetOrigin()[1] - Centre[1])*rayon->GetDirection()[1]) + (2*(rayon->GetOrigin()[2] - Centre[2])*rayon->GetDirection()[2]);

    if(calculs["c"])
        c =  calculs["c"];
    else
        c = pow(rayon->GetOrigin()[0] - Centre[0], 2) + pow(rayon->GetOrigin()[1] - Centre[1], 2) + pow(rayon->GetOrigin()[2] - Centre[2], 2) - (RayonSphere*RayonSphere);

    if(calculs["a"])
        a =  calculs["a"];
    else
        a =  1;

    if(calculs["D"])
        D = calculs["D"];
    else
        D = b*b - 4*a*c ;

    PointIntersection p;

    double t;
    
    if(D==0){
        p.Double = true;
        double t = -b / 2*a;
    }else{
        p.Double = false;

        double temp =  (-b - sqrt(D)) / 2*a;
        double temp2 = (-b + sqrt(D)) / 2*a;
        
        if(temp > 0){
            t = temp;
        }else{
            t = temp2;
        }
    }

    p.T = t;
    p.CoordPoint = rayon->T(t);
    p.Distance = p.CoordPoint.distance(rayon->GetOrigin());

    return p;
} 

Vect ElementSphere::Normal(PointIntersection point){
    return point.CoordPoint;
}

void ElementSphere::Affiche(){
    glTranslated(Centre[0],Centre[1],Centre[2]);
    glutSolidSphere(RayonSphere,50,50);
    
}