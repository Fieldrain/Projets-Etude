#ifndef VERTEX_H
#define VERTEX_H

#define C_SIZE 3 // taille d'une couleur
#define P_SIZE 3 // taille d'un point

#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

class Vertex
{
private:
	double* data;
	double* color;
	int taille;

public:
	Vertex(const int dimension);
	Vertex(double* Data, double* Color);
	Vertex(double* Data,int dimension);
	Vertex();
	Vertex(Vertex* vertex);
	Vertex(Vertex &vertex);
	~Vertex();

	double* getData() const;
	double* getColor() const;
	
	void setData(int i,double newVal);
	void setColor(int i,double newVal);

	int lengthData() const;
	int lengthColor() const;

	int length() const;
	int size() const;
	void printGL() const;

    double operator[](int i) const;
	/*void operator+=(const Vertex* v);
    Vertex* operator*(double s);
	Vertex* operator*(const Vertex* v);
    Vertex* operator/(double s);
    Vertex* operator/(const Vertex* v);
	Vertex* operator+(const Vertex* second);
	Vertex* operator-(const Vertex* second);
    friend ostream& operator<<(ostream& os, const Vertex* v);*/

	
};

#endif
