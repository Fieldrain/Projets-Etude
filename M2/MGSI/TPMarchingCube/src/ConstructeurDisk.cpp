#include "ConstructeurDisk.h"

ConstructeurDisk::ConstructeurDisk()
{
}

Object* ConstructeurDisk::Construit(Vertex* position, double length){
    return new Disk(position,length);
}

Object* ConstructeurDisk::Construit(vector<Object*> disques){
    return disques[0];
}