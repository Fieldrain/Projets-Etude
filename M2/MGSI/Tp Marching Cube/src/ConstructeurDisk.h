#ifndef CONSTRUCTEURDISK_H
#define CONSTRUCTEURDISK_H

#include "ConstructeurObject.h"
#include "Disk.h"

class ConstructeurDisk : public ConstructeurObject
{
public:
    ConstructeurDisk();
	Object* Construit(Vertex* position, double length);
    Object* Construit(vector<Object*> disques);
};

#endif

