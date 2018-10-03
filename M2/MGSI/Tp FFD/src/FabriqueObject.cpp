#include "FabriqueObject.h"

set<TypeObject> FabriqueObject::Types() const
{
	set<TypeObject> types;

	for (auto cons : constructeurs)
	{
		types.insert(cons.first);
	}

	return types;
}

FabriqueObject::FabriqueObject()
{
	StringToTypeObject["FORME"] = TypeObject::FORME;

	constructeurs[TypeObject::FORME] = new ConstructeurForme();
}


FabriqueObject::~FabriqueObject()
{
	for (auto p : constructeurs)
		delete p.second;
}

Object* FabriqueObject::ConstruitObject(TypeObject type,Vertices* Points){
	return constructeurs[type]->Construit(Points);
}

TypeObject FabriqueObject::StringToType(string type){
	return StringToTypeObject[type];
}