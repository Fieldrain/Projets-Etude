#ifndef FABRIQUEOBJECT_H
#define FABRIQUEOBJECT_H

#include <set>
#include <map>

#include "ConstructeurForme.h"

class FabriqueObject
{
private:
	map<string,TypeObject> StringToTypeObject;
	map<TypeObject, ConstructeurObject*> constructeurs;

	FabriqueObject(const FabriqueObject&);
	void operator=(const FabriqueObject&) {};
	
public:
	set<TypeObject> Types() const;
	Object* ConstruitObject(TypeObject type,Vertices* Points);
	TypeObject StringToType(string type);
	FabriqueObject();
	~FabriqueObject();
};

#endif

