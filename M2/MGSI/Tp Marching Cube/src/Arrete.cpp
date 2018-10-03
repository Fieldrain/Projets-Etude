#include "Arrete.h"

Arrete::Arrete(Vertex* Debut, Vertex* Fin):
    debut(Debut),
    fin(Fin)
{
}

Arrete::~Arrete()
{
    delete debut;
    delete fin;
}

Vertex* Arrete::getDebut(){
    return debut;
}

Vertex* Arrete::getFin(){
    return fin;
}


