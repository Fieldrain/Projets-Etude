#include "ConstructeurCarre.h"

ConstructeurCarre::ConstructeurCarre(){

}

ConstructeurCarre::~ConstructeurCarre(){

}

Object* ConstructeurCarre::Construit(string description){
    
    GestionRegex* gestReg = GestionRegex::Instance();

    string descPoint = gestReg->ApplyRegex(description, "Point")[0]; // recupere la ligne qui contient les point exemple : point : (1,1,1)(2,2,2)(3.0,3.0,3.0),
    vector<vector<string>> points;

    // recupere les differents valeur des points (1,1,1) (2,2,2) (3.0,3.0,3.0)
    for (string point : gestReg->ApplyRegex(descPoint, "EnsemblePoint"))
    {
        points.push_back(gestReg->ApplyRegex(point, "ValPoint"));
    }

    Vertices* vertices = new Vertices();
    for(vector<string> point : points){
        Vertex* vert = new Vertex((int)point.size());

        for(int i=0;i<point.size();i++){
            vert->setData(i,stof(point[i]));
        }
        vertices->append(vert);
    }

    return new Carre(vertices);
}

Object* ConstructeurCarre::Construit(Vertices* Sommet, vector<int> Indices){
    return new Carre(Sommet,Indices);
}

