#include "Vertex.h"

Vertex::Vertex(int dimension) : 
	data(dvec(dimension)), 
	color(dvec(3)){
	color[0] = 1;
	color[1] = 0.5;
	color[2] = 0; 
}

Vertex::Vertex(Col<double> Data, Col<double> Color) : 
	data(Data), 
	color(Color)
{
}

Vertex::Vertex(Vertex* vertex) :
	data(vertex->getData()),
	color(vertex->getColor()){
}

Vertex::Vertex(Vertex &vertex) :
	data(vertex.getData()),
	color(vertex.getColor()){
}

Vertex::~Vertex()
{
}

Col<double> Vertex::getData() const{
	return data;
}

Col<double> Vertex::getColor() const{
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
	return (int) data.size();
}

int Vertex::lengthColor() const{
	return (int) color.size();
}


int Vertex::length() const{
	return (int)(data.size() + color.size());
}

int Vertex::size() const{
	return (int)(data.size() * sizeof(double) + color.size() * sizeof(double));
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

void Vertex::operator+=(const Vertex* v){
	data += v->data;
}

Vertex* Vertex::operator*(double s){
	return new Vertex(data*s,color);
}

Vertex* Vertex::operator*(const Vertex* v){
	return new Vertex(data*v->data,color);
}

Vertex* Vertex::operator*(const Mat<double> m){
    return new Vertex(m*data,color);
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
	os << "Data : "<< endl  << v->data <<endl; //"Color : " << v->color <<endl;
    return os; 
}

