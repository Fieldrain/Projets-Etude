#ifndef FORME_H
#define FORME_H

#include "Object.h"

class Forme : public Object
{
public:
    Forme(Vertices* Points);
    ~Forme();

    TypeObject GetType();
    void ShowVBO();
};

#endif

