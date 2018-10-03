#ifndef VERTICES_H
#define VERTICES_H

#include "Vertex.h"

using namespace std;

class Vertices
{
private:
	vector<Vertex*> listVertex;

public:
	Vertices();
	Vertices(vector<Vertex*> ListVertex);
	~Vertices();

	int length() const;
	int size() const;

	void append(Vertex* vertex);
	void appendVertices(Vertices* newVertices);
	vector<Col<double>> toVector();

	Mat<double> getMatCovariance() const;
	vector<Vertex*> getList() const;
	pair<int,double*> getDataList(int dimension) const;
	pair<int,double*> getColorList(int dimension) const;
	double getMin(int axe) const;
	double getMax(int axe) const;
	Col<double> getMoyenne() const;

	void operator+=(const Vertices* v);
    Vertices* operator*(double s);
    Vertices* operator/(double s);
    Vertices* operator/(const Vertices* v);
    Vertices* operator*(const Vertices* v);
	Vertices* operator*(const Mat<double> m);
    Vertex* operator[](int i) const;
    
	Vertices* operator+(const Vertices* second);
    Vertices* operator-(const Vertices* second);
    friend ostream& operator<<(ostream& os, const Vertices* v);
	
};

#endif

