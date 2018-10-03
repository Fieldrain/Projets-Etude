#ifndef TRANSITION_H
#define TRANSITION_H

#include <armadillo>
#include <vector>
using namespace std;
using namespace arma;

class Transition{

private:
    
    Mat<double> matTransition;

public:
    Transition(Mat<double> matriceTransition);
    Transition(vector<vector<double>> matriceTransition);
    ~Transition();

    Mat<double> GetMatTransition();
    int GetDimension();
};


#endif