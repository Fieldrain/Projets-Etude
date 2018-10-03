#ifndef BOUNDINDBOX_H
#define BOUNDINDBOX_H

#include "Forme.h"

class BoundingBox
{
private:
    Object* formeOrigine;
    Object* formeRepereST;
    Object* formeDeformer = NULL;

    vector<vector<Vertex*>> pointsControles;

    int colonnes = 4;
    int lignes = 4; 
    Col<double> P0;
    Col<double> S;
    Col<double> T;

    void CreateControlPoint();
    void ComputeST();
    
    Vertex* BezierInterpolation(Vertex* Pst);
    double factorial(int n);
    double bernstein(double n, double i, double t);
    bool TestPoint(Vertex* point, double x,double y);
    void ShowControlPoint();

public:
    BoundingBox(Object* FormeOrigine);
    ~BoundingBox();

    void Deform();
    void Show();
    void MovePointControl(int i,int j, double newX,double newY);
    int* GetIndice(double x,double y);
};

#endif

