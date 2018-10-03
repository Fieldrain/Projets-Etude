#include "Uv.h"

Uv::Uv(vector<Col<double>> Uv,vector<vector<vector<int>>> Indice):
indice(Indice),
uv(Uv)
{}

Uv::~Uv(){
    indice.clear();
    uv.clear();
}

pair<int,double*> Uv::getListUv(int dimension) const{
    double *coordUv = new double[lengthUv() * dimension];

    int index =0;
    for(int i=0;i<lengthUv();i++){
        Col<double> val = uv[i];

        for(int j=0;j<dimension;j++){
			coordUv[index] = val[j];
            index++;
		}
    }

    return pair<int,double*>(sizeUv(),coordUv);
}

pair<int,double*> Uv::getListIndice(int dimension) const{
    double *coordUv = new double[lengthIndice() * dimension];
    int index =0;

    for(int i=0;i<indice.size();i++){
        vector<vector<int>> val = indice[i];

        for(int j=0;j<val.size();j++){
            vector<int> v = val[j];

            for(int c=0;c<dimension;c++){
                if(c<v.size()){
                    coordUv[index] = (double)v[c];
                }else{
                    coordUv[index] = -1.0;
                }
                index++;
		    }
        }
    }

    return pair<int,double*>(sizeIndice(),coordUv);
}

int Uv::sizeIndice() const{
    return (int) lengthIndice() *sizeof(int)* 3;
}

int Uv::sizeUv() const{
    return (int) lengthUv() *sizeof(double)* 2;
}

int Uv::lengthIndice() const{
    return (int) indice.size()*(int) indice[0].size();
}

int Uv::lengthUv() const{
    return (int) uv.size();
}

vector<Col<double>> Uv::getUv() const{
    return uv;
}

vector<vector<vector<int>>> Uv::getIndice() const{
    return indice;
}

ostream& operator<<(ostream& os, const Uv* uv){

    /*os << "Valeur UV : " <<endl;
    for(int i=0;i<uv->lengthUv();i++){
        Col<double> val = uv->getUv()[i];
        os << "Numero : " << i << " Valeur : " << val << endl << "--------------------" <<endl;
    }*/

    os << "Indice UV : " <<endl;
    for(int i=0;i<uv->getIndice().size();i++){
        vector<vector<int>> val = uv->getIndice()[i];

        for(int j=0;j<val.size();j++){
            vector<int> v = val[j];
            os << "Indice : " << i << "|" << j << " Valeur : " ;

            for(int c=0;c<v.size();c++){
			    os << v[c] << " ";
            }

            os << endl << "--------------------" <<endl;
        }
    }

    return os; 
}