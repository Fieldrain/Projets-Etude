#ifndef VERTEX_H
#define VERTEX_H

#define C_SIZE 3 // taille d'une couleur
#define P_SIZE 2 // taille d'un point

#include <armadillo>
#include <vector>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace arma;
using namespace std;

class Vertex
{
private:
	Col<double> data;
	Col<double> color;

public:
	Vertex(int dimension = P_SIZE);
	Vertex(Col<double> Data);
	Vertex(Col<double> Data, Col<double> Color);
	Vertex(Vertex* vertex);
	Vertex(Vertex &vertex);
	~Vertex();

	Col<double> getData() const;
	Col<double> getColor() const;
	
	void setData(int i,double newVal);
	void setColor(int i,double newVal);

	int lengthData() const;
	int lengthColor() const;
	int length() const;
	int size() const;
	void printGL() const;

    double operator[](int i) const;
	void operator+=(const Vertex* v);
    Vertex* operator*(double s);
	Vertex* operator*(const Vertex* v);
	Vertex* operator*(const Mat<double> m);
    Vertex* operator/(double s);
    Vertex* operator/(const Vertex* v);
	Vertex* operator+(const Vertex* second);
	Vertex* operator-(const Vertex* second);
    friend ostream& operator<<(ostream& os, const Vertex* v);

	
};

#endif
