#ifndef DISK_H
#define DISK_H

#include "Object.h"

class Disk : public Object
{
private:
    double rayon;    
public:
    Disk(Vertex* position, double length);
    ~Disk();

    TypeObject GetType();
    pair<bool,double> In(Vertex* point);
    Vertex* getCentre();
    void Move(Vertex* point);

};

#endif

