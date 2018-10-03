#include "Disk.h"

Disk::Disk(Vertex* position, double length) : 
    Object(position),
    rayon(length)
{}

Disk::~Disk(){
}

TypeObject Disk::GetType(){
    return TypeObject::DISK;
}

pair<bool,double> Disk::In(Vertex* point){
    double x = (*point)[0];
    double y = (*point)[1];

    double val = pow(rayon,2)/(pow(x-(*centre)[0],2)+pow(y-(*centre)[1],2));
    return make_pair(val >= 1,val);
}

Vertex* Disk::getCentre(){
    return centre;
}

void Disk::Move(Vertex* point){
    centre = point;
}