#include "Ligne.h"

Ligne::Ligne(Vertices *Sommet):Object(Sommet){
    
}

Ligne::Ligne(Vertices* Sommet,vector<int> Indices):Object(Sommet,Indices){

}

Ligne::~Ligne(){

}

void Ligne::Show(){
    Object::ShowDefault(GL_LINES,2);
}

void Ligne::ShowVBO(){

    Object::ShowVBODefault(GL_LINES);
}

vector<int> Ligne::GetIndices(int numeroDepart){
    int j = numeroDepart*2;

    vector<int> ind;
    ind.push_back(j);
    ind.push_back(j+1);

    return ind;
}

TypeObject Ligne::GetType(){
    return LIGNE;
}
