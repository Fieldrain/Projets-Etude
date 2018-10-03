#ifndef CARRE_H
#define CARRE_H

#include "Object.h"

class Carre: public Object {

private:
    bool ChargeVBO(Vertices * newVertices);
public:
    Carre(Vertices* Sommet);
    Carre(Vertices* Sommet,vector<int> Indices);
    ~Carre();

    void Show();
	void ShowVBO();
    vector<int> GetIndices(int numeroDepart);
    TypeObject GetType();
    
};

#endif