#include "ConstructeurTriangle.h"

ConstructeurTriangle::ConstructeurTriangle(){

}

ConstructeurTriangle::~ConstructeurTriangle(){

}

Object* ConstructeurTriangle::Construit(string description){
    
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

    /*map<string, string> attributs;
    for (string attribut : gestReg->ApplyRegex(description, "CoupleNomValeur"))
    {
        string nomAttribut = gestReg->ApplyRegex(attribut, "ValCote")[0];
        gestReg->SupprimeChar(nomAttribut, '\'');

        string valAttribut = gestReg->ApplyRegex(attribut, "ValDoublePoint")[0];
        valAttribut = gestReg->SupprimeChar(valAttribut, ':');
        valAttribut = gestReg->SupprimeChar(valAttribut, ',');

        attributs[nomAttribut] = valAttribut;
    }*/

    return new Triangle(vertices);
}

Object* ConstructeurTriangle::Construit(Vertices* Sommet, vector<int> Indices){
    return new Triangle(Sommet,Indices);
}

