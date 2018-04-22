#include "Vertices.h"

Vertices::Vertices(){

}

Vertices::Vertices(int NbElement,int dimensionElement):
	nbElement(NbElement),
	dimension(dimensionElement)
{
	listVertex = new double[NbElement * dimensionElement *sizeof(double)];
	color = new double[NbElement * 3 *sizeof(double)];
}

Vertices::~Vertices(){
	delete listVertex;
	delete color;
}

int Vertices::length() const{
	return nbElement;
}

int Vertices::size() const{
	return length()*dimension*sizeof(double);
}

void Vertices::print() const{
	for(int i=0;i<nbElement;i++){
		cout << "i : "<< i << " # ";
		for(int d=0;d<dimension;d++){
			cout << d << " : " << listVertex[i+d] << " | ";
		}
		cout << endl;
	}
}

void Vertices::set(int indice, double* point,double* couleur){

	for(int i=0;i<dimension;i++){
		listVertex[indice+i] = point[i];
	}
	
	color[indice] = couleur[0];
	color[indice+1] = couleur[1];
	color[indice+2] = couleur[2];
}

void Vertices::set(int indice, double* point){
	for(int i=0;i<dimension;i++){
		listVertex[indice+i] = point[i];
	}
}

pair<int,double*> Vertices::getDataList() const{
	return pair<int,double*>(size(),listVertex);
}

pair<int,double*> Vertices::getColorList() const{
	return pair<int,double*>(length() * 3*sizeof(double),color);
}

double Vertices::operator[](int i) const{
	if(i<=length()){
		return listVertex[i];
	}else{
		return -1;
	}
}