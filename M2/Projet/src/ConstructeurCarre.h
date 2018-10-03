#ifndef CONSTRUCTEURCARRE_H
#define CONSTRUCTEURCAREE_H

#include "ConstructeurObject.h"
#include "Carre.h"

class ConstructeurCarre : public ConstructeurObject{
public:
    Object* Construit(string description);
    Object* Construit(Vertices* Sommet, vector<int> Indices);
    
    ConstructeurCarre();
    ~ConstructeurCarre();
};

#endif