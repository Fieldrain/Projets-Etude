#ifndef CONSTRUCTEURAUTOMATE_H
#define CONSTRUCTEURAUTOMATE_H

#include "Etat.h"

class ConstructeurAutomate
{
public:
	
	virtual Etat* Construit(Object *Forme, vector<Transition *> Transitions) = 0;
};

#endif

