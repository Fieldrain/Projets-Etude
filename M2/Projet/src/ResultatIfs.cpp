#include "ResultatIfs.h"

void ResultatIFS::Append(Vertices* newPoints){
    if(points == nullptr){
        points = new Vertices();
    }
    points->appendVertices(newPoints);
}

void ResultatIFS::Append(vector<int> newIndices){
    indices.insert(indices.end(), newIndices.begin(), newIndices.end());
}

void ResultatIFS::Append(string nom,vector<pair<Col<double>,Col<double>>> newVec){
    if(nom=="tangentes")
        tangentes.insert(tangentes.end(), newVec.begin(), newVec.end());
    else
        tangentesInit.insert(tangentesInit.end(), newVec.begin(), newVec.end());
}

void ResultatIFS::Append(string nom,vector<Col<double>> newUv){
    if(nom=="uv")
        uv.insert(uv.end(), newUv.begin(), newUv.end());
    else
        uvTangentes.insert(uvTangentes.end(), newUv.begin(), newUv.end());
}

void ResultatIFS::Append(vector<string> newAdresse){
    adresseTangentes.insert(adresseTangentes.end(), newAdresse.begin(), newAdresse.end());
}

void ResultatIFS::Append(ResultatIFS* r){
    Append(r->points);
    Append(r->indices);
    Append("tangentes",r->tangentes);
    Append("tangentesInit",r->tangentesInit);
    Append("uv",r->uv);
    Append("uvTangentes",r->uvTangentes);
    Append(r->adresseTangentes);

    delete r;
}