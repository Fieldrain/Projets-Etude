#ifndef TANGENTES_H
#define TANGENTES_H

#include <armadillo>
#include <vector>

using namespace std;
using namespace arma;

class Tangentes{
    private:
        vector<pair<Col<double>,Col<double>>> tangentes;
    public:
        Tangentes(vector<pair<Col<double>,Col<double>>> Tangentes);
        ~Tangentes();

        pair<int,pair<double*,double*>> getList(int dimension) const;
        int size() const;
        int length() const;
        pair<Col<double>,Col<double>> operator[](int i) const;
        friend ostream& operator<<(ostream& os, const Tangentes* Tang);
};

#endif