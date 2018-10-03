#ifndef SCENE_H
#define SCENE_H

#include <map>
#include "Blob.h"
#include "Marching.h"

using namespace std;


class Scene{
private:
    Blob* blob;
    Marching* marching;

public:
    Object* selectedObject;
    int lignes = 60;
    int colonnes = 80;

    void AddBlob(Blob* o);
    Blob* GetBlob();
    
    void Clear();
    void Affiche();
    void AfficheRepere();
    void Update();

    Scene();
    ~Scene();
};

#endif