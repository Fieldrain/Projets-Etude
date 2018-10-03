#ifndef FABRIQUEOBJECT_H
#define FABRIQUEOBJECT_H

#include "ConstructeurTriangle.h"
#include "ConstructeurCarre.h"
#include "ConstructeurLigne.h"
#include <set>
#include <map>


class FabriqueObject
{
private:
	map<string,TypeObject> StringToTypeObject;
	map<TypeObject, ConstructeurObject*> constructeurs;

	FabriqueObject(const FabriqueObject&);
	void operator=(const FabriqueObject&) {};
	
public:
	set<TypeObject> Types() const;
	Object* ConstruitObject(TypeObject type, string description);
	Object* ConstruitObject(TypeObject type, Vertices* Sommet, vector<int> Indices);
	TypeObject StringToType(string type);
	FabriqueObject();
	~FabriqueObject();
};

#endif

