#ifndef RESULTATIFS_H
#define RESULTATIFS_H

#include <string>
#include "Vertices.h"

class ResultatIFS{

public:
    Vertices* points;
    int nbEtape = 0;
    vector<int> indices;

    vector<string> adresseTangentes;
    vector<Col<double>> uv;
    vector<Col<double>> uvTangentes;
    vector<pair<Col<double>,Col<double>>> tangentes;
    vector<pair<Col<double>,Col<double>>> tangentesInit;

    void Append(Vertices* newPoints);
    void Append(vector<int> newIndices);
    void Append(string nom,vector<pair<Col<double>,Col<double>>> newVec);
    void Append(string nom,vector<Col<double>> newUv);
    void Append(vector<string> newAdresse);

    void Append(ResultatIFS* r);

};

#endif