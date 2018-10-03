#ifndef ETAT_H
#define ETAT_H

#include "Transition.h"
#include "Object.h"
#include "ResultatIfs.h"

enum TypeAutomate{CLASSIQUE};

class Etat{

private:
    vector<Etat*> etSuivant;
    vector<Transition*> trSuivante;
    Object *forme;

    void ContinueGeometry(Mat<double> multTransformation,int nombreIterationModele, int nombreIterationTangente, ResultatIFS* res);
    void ContinueUv(Mat<double> multTransformationUv,int nombreIterationModele, int nombreIterationTangente, string adresse,ResultatIFS* res);

public:

    int GetDimension();
    void SetEtatSuivant(vector<Etat*> EtatSuivant);
    Etat* GetEtatSuivant();
    Object* GetForme();
    vector<Transition*> GetTransition();
    vector<string> Inverse(Col<double> uv,int profondeur);

    void CalculGeometry(Mat<double> multTransformation,int nombreIterationModele, int nombreIterationTangente, ResultatIFS* res);
    void CalculUv(Mat<double> multTransformationUv,int nombreIterationModele, int nombreIterationTangente, string adresse,ResultatIFS* res);

    Etat(Object *Forme, vector<Transition*> TransitionSuivante = vector<Transition*>(), vector<Etat*> EtatSuivant = vector<Etat*>());
    ~Etat();

};
#endif