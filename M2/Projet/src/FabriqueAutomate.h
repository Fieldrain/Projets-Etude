#ifndef FABRIQUEAUTOMATE_H
#define FABRIQUEAUTOMATE_H

#include "ConstructeurAutomateClassique.h"
#include <set>
#include <map>


class FabriqueAutomate
{
private:
	map<string,TypeAutomate> StringToTypeAutomate;
	map<TypeAutomate, ConstructeurAutomate*> constructeurs;

	FabriqueAutomate(const FabriqueAutomate&);
	void operator=(const FabriqueAutomate&) {};
	
public:
	set<TypeAutomate> Types() const;
	Etat* ConstruitAutomate(TypeAutomate type, Object *Forme, vector<Transition *> Transitions);
	TypeAutomate StringToType(string type);
	FabriqueAutomate();
	~FabriqueAutomate();
};

#endif
