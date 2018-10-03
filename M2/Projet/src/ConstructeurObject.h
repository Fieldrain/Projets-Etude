#ifndef CONSTRUCTEUROBJECT_H
#define CONSTRUCTEUROBJECT_H

#include "GestionRegex.h"
#include "Object.h"

class ConstructeurObject
{
public:
	virtual Object* Construit(string description) = 0;
	virtual Object* Construit(Vertices* Sommet, vector<int> Indices) = 0;
};

#endif

