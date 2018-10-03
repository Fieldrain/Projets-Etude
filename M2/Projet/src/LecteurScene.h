#ifndef LECTEURSCENE_H
#define LECTEURSCENE_H

#include "GestionRegex.h"
#include "Scene.h"
#include "FabriqueObject.h"
#include "FabriqueAutomate.h"

using namespace std;

class LecteurScene{
private:
    string chemin;
    ifstream fichier;

    map<string, Object*> LireObject(string ensemble, map<string, Object *> formes);
    map<string, Etat*> LireAutomate(string ensemble, map<string,Object*> formes,map<string, Etat *> etats);
    Mat<double> GetValTransition(string Matrice,map<string,Mat<double>> matrices = map<string,Mat<double>>());

public:
    LecteurScene(string CheminFichier);
    ~LecteurScene();

    void Ouvrir();
    void Lire(Scene* scene);
    void Fermer();
};

#endif