#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

using namespace std;

class Sphere : public Object
{
private:
	int parallele;
	int meridien;
	float diametre;
    double* origin;

    void initSommet();
    void initIndice();

public:
    Sphere(double* Origin,float Diametre = 1.f,int Parallele = 10, int Meridien = 10);
	~Sphere();

    void ShowVBO();
    void Show();
    float getDiametre();
};
#endif
