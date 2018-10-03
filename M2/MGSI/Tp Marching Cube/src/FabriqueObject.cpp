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
	StringToTypeObject["Disk"] = TypeObject::DISK;
	StringToTypeObject["Blob"] = TypeObject::BLOB;

	constructeurs[TypeObject::DISK] = new ConstructeurDisk();
	constructeurs[TypeObject::BLOB] = new ConstructeurBlob();
}


FabriqueObject::~FabriqueObject()
{
	for (auto p : constructeurs)
		delete p.second;
}

Object* FabriqueObject::ConstruitObject(TypeObject type,Vertex* position, double length){
	return constructeurs[type]->Construit(position,length);
}

Object* FabriqueObject::ConstruitObject(TypeObject type,vector<Object*> disques){
	return constructeurs[type]->Construit(disques);
}


TypeObject FabriqueObject::StringToType(string type){
	return StringToTypeObject[type];
}