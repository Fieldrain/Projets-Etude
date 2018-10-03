#include "ConstructeurAutomateClassique.h"

ConstructeurAutomateClassique::ConstructeurAutomateClassique(){

}

ConstructeurAutomateClassique::~ConstructeurAutomateClassique(){

}

Etat* ConstructeurAutomateClassique::Construit(Object *Forme, vector<Transition *> Transitions){
    return new Etat(Forme,Transitions);
}

