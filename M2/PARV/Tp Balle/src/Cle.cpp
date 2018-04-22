#include "Cle.h"

Cle::Cle(int NumeroFrame, glm::vec3 RotationInit, glm::vec3 RotationObj, glm::vec3 Position,bool Modifie) : 
    numFrame(NumeroFrame),
    rotationInit(RotationInit),
    rotationObj(RotationObj),
    position(Position),
    modifie(Modifie)
{}

Cle::~Cle()
{}

int Cle::getNumFrame(){
    return numFrame;
}

glm::vec3 Cle::getAngleInit(){
    return rotationInit;
}

glm::vec3 Cle::getAngleObj(){
    return rotationObj;
}

glm::vec3 Cle::getPosition(){
    return position;
}

bool Cle::change(){
    return modifie;
}