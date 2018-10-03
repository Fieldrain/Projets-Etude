#include "ConstructeurBlob.h"

ConstructeurBlob::ConstructeurBlob()
{
}

Object* ConstructeurBlob::Construit(vector<Object*> disques){
    return new Blob(disques);
}

Object* ConstructeurBlob::Construit(Vertex* position, double length){
    Blob* b = new Blob();
    
    b->AddDisk(new Disk(position,length));

    return b;
}