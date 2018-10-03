#ifndef CONSTRUCTEURFORME_H
#define CONSTRUCTEURFORME_H

#include "Forme.h"
#include "ConstructeurObject.h"

class ConstructeurForme : public ConstructeurObject
{
public:
    ConstructeurForme();
	Object* Construit(Vertices* points);
};

#endif

