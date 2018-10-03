#include "Triangle.h"

Triangle::Triangle(Vertices *Sommet):Object(Sommet){
    
}

Triangle::Triangle(Vertices* Sommet,vector<int> Indices):Object(Sommet,Indices){

}

Triangle::~Triangle(){

    
}

void Triangle::Show(){
    Object::ShowDefault(GL_TRIANGLES,3);
}

void Triangle::ShowVBO(){

    Object::ShowVBODefault(GL_TRIANGLES);
}

vector<int> Triangle::GetIndices(int numeroDepart){
    int j = numeroDepart*3;
    vector<int> ind;
    ind.push_back(j);
    ind.push_back(j+1);
    ind.push_back(j+2);

    return ind;
}

TypeObject Triangle::GetType(){
    return TRIANGLE;
}
