#include "Carre.h"

Carre::Carre(Vertices *Sommet):Object(Sommet){
}

Carre::Carre(Vertices* Sommet,vector<int> Indices):Object(Sommet,Indices){

}

Carre::~Carre(){
    
}

void Carre::Show(){
    Object::ShowDefault(GL_TRIANGLES,3);
}

void Carre::ShowVBO(){
    Object::ShowVBODefault(GL_TRIANGLES);
}

vector<int> Carre::GetIndices(int numeroDepart){
    int j = numeroDepart*4;
    vector<int> ind;
    //premier triangles
    ind.push_back(j);
    ind.push_back(j+2);
    ind.push_back(j+1);

    //deuxieme triangle
    ind.push_back(j+1);
    ind.push_back(j+2);
    ind.push_back(j+3);

    return ind;
}

TypeObject Carre::GetType(){
    return CARRE;
}