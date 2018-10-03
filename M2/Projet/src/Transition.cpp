#include "Transition.h"

Transition::Transition(Mat<double> matriceTransition) : matTransition(matriceTransition){

}

Transition::Transition(vector<vector<double>> matriceTransition){
    matTransition.zeros(3,3);
    int i,j;
    i = 0;
    for(vector<double> ligne : matriceTransition){
        j=0;
        for(double val : ligne){
            matTransition(i,j) = val;
            j++;
        }
        i++;
    }
}

Transition::~Transition(){

}

Mat<double> Transition::GetMatTransition(){
    return matTransition;
} 

int Transition::GetDimension(){
    return (int)matTransition.n_rows;
}