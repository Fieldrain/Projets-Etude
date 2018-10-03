#ifndef LIGNE_H
#define LIGNE_H

#include "Object.h"

class Ligne: public Object {

public:
    Ligne(Vertices* Sommet);
    Ligne(Vertices* Sommet,vector<int> Indices);
    ~Ligne();

    void Show();
	void ShowVBO();
    vector<int> GetIndices(int numeroDepart);
    TypeObject GetType();
};

#endif