#ifndef VERTICES_H
#define VERTICES_H

#define C_SIZE 3 // taille d'une couleur
#define P_SIZE 3 // taille d'un point

#include <iostream>
#include <math.h>
#include <limits>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

class Vertices
{
private:
	double* listVertex;
	double* color;
	int nbElement;
	int dimension;

public:
	Vertices();
	Vertices(int NbElement, int dimensionElement);
	~Vertices();

	int length() const;
	int size() const;

	void print() const;

	pair<int,double*> getDataList() const;
	pair<int,double*> getColorList() const;
	void set(int indice, double* point,double* couleur);
	void set(int indice, double* point);

	double operator[](int i) const;
	
};

#endif

