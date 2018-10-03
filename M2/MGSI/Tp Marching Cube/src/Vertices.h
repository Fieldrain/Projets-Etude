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

	vector<Vertex*> getList() const;
	pair<int,double*> getDataList(int dimension) const;
	pair<int,double*> getColorList(int dimension) const;

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

