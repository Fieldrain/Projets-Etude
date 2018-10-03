#pragma once
#include "../../Rayon/Rayon.h"
#include <map>

using namespace std;

struct Retour_Calcul{
    bool dedans = false;
    map<string,double> calculs;
    void clear(){
        dedans = false;
        calculs.clear();
    }
};

class Englobant{

public:
    virtual Retour_Calcul In(Rayon* rayon) = 0;

    Englobant(){}
    virtual ~Englobant(){}
};
