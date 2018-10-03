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
	StringToTypeObject["TRIANGLE"] = TypeObject::TRIANGLE;
	StringToTypeObject["LIGNE"] = TypeObject::LIGNE;
	StringToTypeObject["CARRE"] = TypeObject::CARRE;

	constructeurs[TypeObject::TRIANGLE] = new ConstructeurTriangle();
	constructeurs[TypeObject::LIGNE] = new ConstructeurLigne();
	constructeurs[TypeObject::CARRE] = new ConstructeurCarre();
}


FabriqueObject::~FabriqueObject()
{
	for (auto p : constructeurs)
		delete p.second;
}

Object* FabriqueObject::ConstruitObject(TypeObject type, string description){
	return constructeurs[type]->Construit(description);
}

Object* FabriqueObject::ConstruitObject(TypeObject type, Vertices* Sommet, vector<int> Indices){
	return constructeurs[type]->Construit(Sommet,Indices);
}

TypeObject FabriqueObject::StringToType(string type){
	return StringToTypeObject[type];
}