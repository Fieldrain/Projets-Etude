#ifndef SCENE_H
#define SCENE_H

#include <map>
#include "FabriqueObject.h"
#include "BoundingBox.h"

using namespace std;

class Scene{
private:
    Vertices* pointSouris;
    vector<BoundingBox*> boundingBoxs;
    
public:
    int* currentIndice;

    void AddPointSouris(double x,double y);
    void AddObject(Object * o);
    BoundingBox* GetBoundingBox(int i);
    Vertices* GetPointSouris();

    void Clear();
    void Affiche();
    void AfficheRepere();
    void AffichePoint();
    void Update();

    Scene();
    ~Scene();
};

#endif