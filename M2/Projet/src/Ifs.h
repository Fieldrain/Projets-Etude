#ifndef IFS_H
#define IFS_H

#include <thread>
#include "Etat.h"
#include "FabriqueObject.h"

class Ifs{
private:
    Etat* geometry = NULL;
    Etat* uv = NULL;
    Object* fractal = NULL;
    vector<vector<vector<int>>> uvToAdresse;
    double pas = 0.0;

    void CalculTangentesInitial(ResultatIFS *res);
    void CalculAdresseUV(int iterationModele,int iterationTangente,ResultatIFS *res);
public:

    void Make(int iterationModele,int iterationTangente,Shader* shader,string cheminTextures);
    void RequestUpdate(int iterationModele,int iterationTangente,Shader* shader,string cheminTextures);
    void Render(int repere,bool showTangente);
    double GetPas();

    Ifs(Etat* Geometry,Etat* Uv);
    Ifs(Etat* Geometry);
    ~Ifs();
};

#endif