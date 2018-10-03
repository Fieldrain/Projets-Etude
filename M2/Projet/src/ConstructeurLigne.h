#ifndef CONSTRUCTEURLIGNE_H
#define CONSTRUCTEURLIGNE_H

#include "ConstructeurObject.h"
#include "Ligne.h"

class ConstructeurLigne : public ConstructeurObject{
public:
    Object* Construit(string description);
    Object* Construit(Vertices* Sommet, vector<int> Indices);
    
    ConstructeurLigne();
    ~ConstructeurLigne();
};

#endif