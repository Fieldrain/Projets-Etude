#ifndef CONSTRUCTEURTRIANGLE_H
#define CONSTRUCTEURTRIANGLE_H

#include "ConstructeurObject.h"
#include "Triangle.h"

class ConstructeurTriangle : public ConstructeurObject{
public:
    Object* Construit(string description);
    Object* Construit(Vertices* Sommet, vector<int> Indices);
    
    ConstructeurTriangle();
    ~ConstructeurTriangle();
};

#endif