#ifndef CONSTRUCTEUROBJECT_H
#define CONSTRUCTEUROBJECT_H

#include "Object.h"

class ConstructeurObject
{
public:
	virtual Object* Construit(Vertex* position, double length) = 0;
	virtual Object* Construit(vector<Object*> disques) = 0;
};

#endif

