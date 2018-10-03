#ifndef CONSTRUCTEUROBJECT_H
#define CONSTRUCTEUROBJECT_H

#include "Object.h"

class ConstructeurObject
{
public:
	virtual Object* Construit(Vertices* Points) = 0;
};

#endif

