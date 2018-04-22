#include "Forme.h"

Forme::Forme(Vertices* Points) : 
    Object(Points)
{
}

Forme::~Forme(){
}

TypeObject Forme::GetType(){
    return TypeObject::FORME;
}

void Forme::ShowVBO(){
    Object::ShowVBODefault(GL_LINE);
}