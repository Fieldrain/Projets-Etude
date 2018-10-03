#ifndef CONSTRUCTEURAUTOMATECLASSIQUE_H
#define CONSTRUCTEURAUTOMATECLASSIQUE_H

#include <regex>
#include "ConstructeurAutomate.h"

class ConstructeurAutomateClassique : public ConstructeurAutomate{
public:
    Etat* Construit(Object *Forme, vector<Transition *> Transitions);
    
    ConstructeurAutomateClassique();
    ~ConstructeurAutomateClassique();
};

#endif