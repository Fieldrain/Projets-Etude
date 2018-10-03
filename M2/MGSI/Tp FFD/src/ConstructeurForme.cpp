#include "ConstructeurForme.h"

ConstructeurForme::ConstructeurForme()
{
}

Object* ConstructeurForme::Construit(Vertices* points){
    return new Forme(points);
}