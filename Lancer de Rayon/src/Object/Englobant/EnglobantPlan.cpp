#include "EnglobantPlan.h"

EnglobantPlan::EnglobantPlan(Vect pointC,Vect normalPlan) : PointC(pointC), NormalPlan(normalPlan){

}

EnglobantPlan::~EnglobantPlan(){

}

Retour_Calcul EnglobantPlan::In(Rayon* rayon){
    Retour_Calcul r_c;
    r_c.dedans = false;

    float t;
    // verifie pas parallele et que le rayon ne demarre pas dans le plan
    Vect OC = (rayon->GetOrigin() - PointC);

    if( rayon->GetDirection().dot(NormalPlan) != 0 && OC.dot(NormalPlan) != 0){

        t = -(OC.dot(NormalPlan)) / rayon->GetDirection().dot(NormalPlan);
        
        if(t>=0){
            r_c.calculs["t"] = t;
            r_c.dedans = true;
        }

    }

    return r_c;
}