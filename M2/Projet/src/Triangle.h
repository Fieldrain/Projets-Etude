#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object.h"

class Triangle: public Object {

public:
    Triangle(Vertices* Sommet);
    Triangle(Vertices* Sommet,vector<int> Indices);
    ~Triangle();

    void Show();
	void ShowVBO();
    vector<int> GetIndices(int numeroDepart);
    TypeObject GetType();
};

#endif