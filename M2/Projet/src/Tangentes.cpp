#include "Tangentes.h"


Tangentes::Tangentes(vector<pair<Col<double>,Col<double>>> Tangentes):
    tangentes(Tangentes)
{}

Tangentes::~Tangentes(){
    tangentes.clear();
}

pair<int,pair<double*,double*>> Tangentes::getList(int dimension) const{
    double *tang1 = new double[length() * dimension];
    double *tang2 = new double[length() * dimension];

    int index =0;
    for(int i=0;i<length();i++){
        pair<Col<double>,Col<double>> tang = tangentes[i];
        for(int j=0;j<dimension;j++){
			tang1[index] = tang.first[j];
            tang2[index] = tang.second[j];
            index++;
		}
    }

    pair<double*,double*> tang(tang1,tang2);
    return pair<int,pair<double*,double*>>(size(),tang);
}

int Tangentes::size() const{
    return (int) length() *sizeof(double)* 3;
}

int Tangentes::length() const{
    return (int) tangentes.size();
}

pair<Col<double>,Col<double>> Tangentes::operator[](int i) const{
    return tangentes[i];
}

ostream& operator<<(ostream& os, const Tangentes* Tang){

    for(int i=0;i<Tang->length();i++){
        pair<Col<double>,Col<double>> tang = (*Tang)[i];
        os << "Tangente indice : " << i << " Tangente 1 : " << tang.first << " Tangente 2 : " << tang.second << endl << "--------------------" <<endl;
    }
    return os; 
}
