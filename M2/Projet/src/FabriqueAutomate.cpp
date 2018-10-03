#include "FabriqueAutomate.h"

set<TypeAutomate> FabriqueAutomate::Types() const
{
	set<TypeAutomate> types;

	for (auto cons : constructeurs)
	{
		types.insert(cons.first);
	}

	return types;
}

FabriqueAutomate::FabriqueAutomate()
{
	StringToTypeAutomate["CLASSIQUE"] = TypeAutomate::CLASSIQUE;
	constructeurs[TypeAutomate::CLASSIQUE] = new ConstructeurAutomateClassique();
}

FabriqueAutomate::~FabriqueAutomate()
{
	for (auto p : constructeurs)
		delete p.second;
}

Etat* FabriqueAutomate::ConstruitAutomate(TypeAutomate type, Object *Forme, vector<Transition *> Transitions){
	return constructeurs[type]->Construit(Forme,Transitions);
}

TypeAutomate FabriqueAutomate::StringToType(string type){
	return StringToTypeAutomate[type];
}