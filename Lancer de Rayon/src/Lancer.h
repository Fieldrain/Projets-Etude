#pragma once

#include "Scene/Scene.h"
#include "Rayon/Rayon.h"
#include "Camera/Camera.h"
#include <fstream>
#include <iostream>

struct RGBType {
	double r;
	double g;
	double b;
};

class Lancer{
private:
    Scene* scene;

    Vect Trace(int Profondeur,Rayon* NewRayon);
    Vect Colorier(Rayon* RayonCourant, PointIntersection Point, Vect Normal, int Profondeur);
    void Savebmp(const char *filename, int w, int h, int dpi, RGBType *data); 
    PointIntersection TestIntersection(Rayon* Rayon);

    Vect Phong(Vect Normal,Lumiere* lumiere,PointIntersection Point,Rayon* rayon);

public:
    void Main(int Profondeur,Camera* camera);

    Lancer(Scene* RenderScene);
    ~Lancer();
};
