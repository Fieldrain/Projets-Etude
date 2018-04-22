#include "Vertices.h"

Vertices::Vertices(){

}

Vertices::Vertices(int nbElement){
	for(int i=0;i<nbElement;i++){
		listVertex.push_back(new Vertex());
	}
}

Vertices::Vertices(vector<Vertex*> ListVertex) :
	listVertex(ListVertex){
}

Vertices::~Vertices(){
	listVertex.clear();
}

int Vertices::length() const{
	return (int)listVertex.size();
}

int Vertices::size() const{
	return length()*sizeof(double)*P_SIZE;
}

void Vertices::append(Vertex* vertex){
	listVertex.push_back(vertex);
}

void Vertices::add(Vertex* vertex,int index){
	Vertex* old = listVertex[index];
	listVertex[index] = vertex;
	delete old;
}

void Vertices::appendVertices(Vertices* newVertices){
	vector<Vertex*> b = newVertices->listVertex;
	listVertex.insert(listVertex.end(), b.begin(), b.end());
}

vector<Vertex*> Vertices::getList() const{
	return listVertex;
}

pair<int,double*> Vertices::getDataList(int dimension) const{
	double* dataList = new double[length() * dimension];

	int index = 0;
	for(int i=0;i<listVertex.size();i++){
		Vertex* v = listVertex[i];
		double * data = v->getData();

		for(int i=0;i<dimension;i++){
			dataList[index++] = data[i];
		}
	}

	return pair<int,double*>(length() * dimension * sizeof(double),dataList);
}

pair<int,double*> Vertices::getColorList(int dimension) const{
	double* colorList = new double[length() * dimension];

	int index = 0;
	for(int i=0;i<listVertex.size();i++){
		Vertex* v = listVertex[i];
		double * color = v->getColor();

		for(int i=0;i<dimension;i++){
			colorList[index++] = color[i];
		}
	}

	return pair<int,double*>(length() * dimension * sizeof(double),colorList);
}

Vertex* Vertices::operator[](int i) const{
	if(i<=length()){
		return listVertex[i];
	}else{
		return new Vertex();
	}
}

/*
void Vertices::operator+=(const Vertices* v){

	for(int i=0;i<length();i++){

		Vertex * vert= (*v)[i];
		*listVertex[i] += vert;
	}

}

Vertices* Vertices::operator*(double s){
	vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];

		newList.push_back(new Vertex(*v1*s));
	}

    return new Vertices(newList);
}

Vertices* Vertices::operator*(const Vertices* v){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = (*v)[i];

		newList.push_back(new Vertex(*v1*v2));
	}

    return new Vertices(newList);
}

Vertices* Vertices::operator/(double s){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];

		newList.push_back(new Vertex(*v1/s));
	}

    return new Vertices(newList);
}

Vertices* Vertices::operator/(const Vertices* v){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = (*v)[i];

		newList.push_back(new Vertex(*v1/v2));
	}

    return new Vertices(newList);
}


Vertices* Vertices::operator-( const Vertices* second){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = second->listVertex[i];
		
		newList.push_back(new Vertex(*v1-v2));
	}

    return new Vertices(newList);
}
Vertices* Vertices::operator+(const Vertices* second){
    vector<Vertex*> newList = vector<Vertex*>();

	for(int i=0;i<length();i++){
		Vertex * v1 = listVertex[i];
		Vertex * v2 = second->listVertex[i];
		
		newList.push_back(new Vertex(*v1+v2));
	}

    return new Vertices(newList);
}
ostream& operator<<(ostream& os, const Vertices* v){

	os << "Taille du tabeau : " << v->length() <<endl;
	for(Vertex * v : v->listVertex){
		os << '\t' << v <<endl;
	}
    
    return os; 
}*/