#include "Vertex.h"

Vertex::Vertex() :
	taille(-1)
{}

Vertex::Vertex(const int dimension) : 
	taille(dimension)
{
	data = new double(dimension);
	color = new double(3);
	color[0] = 1.0;
	color[1] = 1.0;
	color[2] = 1.0;
}

Vertex::Vertex(double* Data, int dimension) : 
	data(Data),
	taille(dimension)
{
	color = new double(3);
	color[0] = 1.0;
	color[1] = 1.0;
	color[2] = 1.0;
}


Vertex::Vertex(double * Data, double * Color) : 
	data(Data), 
	color(Color),
	taille(3)
{}

Vertex::Vertex(Vertex* vertex) :
	data(vertex->getData()),
	color(vertex->getColor()),
	taille(vertex->lengthData())
{}

Vertex::Vertex(Vertex &vertex) :
	data(vertex.getData()),
	color(vertex.getColor()),
	taille(vertex.lengthData())
{}

Vertex::~Vertex()
{
	if(taille!=-1){
		delete data;
		delete color;
	}

}

double * Vertex::getData() const{
	return data;
}

double * Vertex::getColor() const{
	return color;
}

void Vertex::setData(int i,double newVal){
	if(i<=lengthData()){
		data[i] = newVal;
	}
}

void Vertex::setColor(int i,double newVal){
	if(i<=lengthColor()){
		color[i] = newVal;
	}
}

int Vertex::lengthData() const{
	return taille;
}

int Vertex::lengthColor() const{
	return 3;
}

int Vertex::length() const{
	return (int)(taille + 3);
}

int Vertex::size() const{
	return (int)(taille * sizeof(double) + 3 * sizeof(double));
}

void Vertex::printGL() const{
	glColor3d(color[0], color[1], color[2]);
    glVertex3d(data[0], data[1], data[2]);
}

double Vertex::operator[](int i) const{
    if(i<=lengthData()){
		return data[i];
	}else if(i<=length()){
		return color[i-lengthData()];
	}else{
		return numeric_limits<double>::infinity();
	}
}

/*void Vertex::operator+=(const Vertex* v){
	data += v->data;
}

Vertex* Vertex::operator*(double s){
	return new Vertex(data*s,color);
}

Vertex* Vertex::operator*(const Vertex* v){
	return new Vertex(data*v->data,color);
}

Vertex* Vertex::operator/(double s){
	return new Vertex(data/s,color);
}

Vertex* Vertex::operator/(const Vertex* v){
	return new Vertex(data/v->data,color);
}
    
Vertex* Vertex::operator+(const Vertex* second){
	return new Vertex(getData() - second->getData(),getColor());
}

Vertex* Vertex::operator-(const Vertex* second){
	return new Vertex(getData() + second->getData(),getColor());
}

ostream& operator<<(ostream& os, const Vertex* v){
	os << "Data : "<< v->data <<endl << "Color : " << v->color <<endl;
    return os; 
}*/

