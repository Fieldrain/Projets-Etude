#pragma once
#include <vector>
#include "../Object/Object.h"
#include "../Lumiere/Lumiere.h"

using namespace std;

class Scene{

private:
    vector<Object*>* objects;
    vector<Lumiere*>* lumieres;

    Vect LumiereAmbiante;
    Vect CouleurFond;

public:

    void AddObject(Object* NewObject);
    Object* GetObject(int Index);
    int NbObject();

    void AddLumiere(Lumiere* NewLumiere);
    Lumiere* GetLumiere(int Index);
    int NbLumiere();

    Vect GetCouleurAmbiante();
    Vect GetCouleurFond();

    void Affiche();

    Scene(Vect ValueCouleurAmbiante, Vect ValueCouleurFond);
    ~Scene();

};
