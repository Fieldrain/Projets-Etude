#include "Blob.h"

Blob::Blob(){

}

Blob::Blob(vector<Object*> Disques)
{
    for(Object* o : Disques){
        disques.push_back((Disk*)o);
    }
}

Blob::~Blob(){
    disques.clear();
}

void Blob::AddDisk(Disk* d){
    disques.push_back(d);
}

TypeObject Blob::GetType(){
    return TypeObject::BLOB;
}

pair<bool,double> Blob::In(Vertex* point){
    double somme = 0;

    for(Disk* d : disques){
        somme += d->In(point).second;
    }

    return make_pair(somme>=1,somme);
}

Vertex* Blob::getCentre(){
    return disques[0]->getCentre();
}

void Blob::Move(Vertex* point){
    disques[0]->Move(point);
}

Disk* Blob::GetDisk(Vertex* point){

    for(Disk* d : disques){
        if(d->In(point).first)
            return d;
    }
    return NULL;
}
