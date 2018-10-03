#ifndef CONSTRUCTEURBLOB_H
#define CONSTRUCTEURBLOB_H

#include "ConstructeurObject.h"
#include "Blob.h"

class ConstructeurBlob : public ConstructeurObject
{
public:
    ConstructeurBlob();
	Object* Construit(vector<Object*> disques);
    Object* Construit(Vertex* position, double length);
};

#endif

