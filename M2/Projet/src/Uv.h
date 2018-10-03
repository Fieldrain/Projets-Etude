#ifndef UV_H
#define UV_H

#include <armadillo>
#include <vector>

using namespace std;
using namespace arma;

class Uv{
    private:
        vector<Col<double>> uv;
        vector<vector<vector<int>>> indice;
    public:
        Uv(vector<Col<double>> Uv,vector<vector<vector<int>>> Indice);
        ~Uv();

        vector<Col<double>> getUv() const;
        vector<vector<vector<int>>> getIndice() const;
        pair<int,double*> getListUv(int dimension) const;
        pair<int,double*> getListIndice(int dimension) const;
        int sizeIndice() const;
        int sizeUv() const;
        int lengthIndice() const;
        int lengthUv() const;
        friend ostream& operator<<(ostream& os, const Uv* uv);
        /*vector<double*> operator[](int i) const;
        Col<double> operator[](int i) const;*/
};

#endif