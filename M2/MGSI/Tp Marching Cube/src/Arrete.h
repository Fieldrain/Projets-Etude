#pragma once

#include "Vertex.h"

class Arrete{
    private:
        Vertex* debut;
        Vertex* fin;
    public:
        Arrete(Vertex* Debut, Vertex* Fin);
        ~Arrete();
        Vertex* getDebut();
        Vertex* getFin();
};