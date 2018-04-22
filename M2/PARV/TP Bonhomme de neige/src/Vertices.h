#ifndef VERTICES_H
#define VERTICES_H

#include "Vertex.h"
#include <vector>
using namespace std;

class Vertices
{
private:
	vector<Vertex*> listVertex;

public:
	Vertices();
	Vertices(int nbElement);
	Vertices(vector<Vertex*> ListVertex);
	~Vertices();

	int length() const;
	int size() const;

	void append(Vertex* vertex);
	void add(Vertex* vertex,int index);
	void appendVertices(Vertices* newVertices);

	vector<Vertex*> getList() const;
	pair<int,double*> getDataList(int dimension) const;
	pair<int,double*> getColorList(int dimension) const;

	Vertex* operator[](int i) const;
	/*void operator+=(const Vertices* v);
    Vertices* operator*(double s);
    Vertices* operator/(double s);
    Vertices* operator/(const Vertices* v);
    Vertices* operator*(const Vertices* v);
    
    
	Vertices* operator+(const Vertices* second);
    Vertices* operator-(const Vertices* second);
    friend ostream& operator<<(ostream& os, const Vertices* v);*/
	
};

#endif

