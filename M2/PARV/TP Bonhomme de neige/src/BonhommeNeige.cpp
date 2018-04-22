#include "BonhommeNeige.h"

BonhommeNeige::BonhommeNeige(){

    double * posTete = new double[3];
    posTete[0] = 0.0;
    posTete[1] = 1.0/2.0 + 0.5/2.0;
    posTete[2] = 0.0;
    MorceauBonhommeNeige * tete = new MorceauBonhommeNeige(0.5f,posTete,2,NULL);

    double * posCorps = new double[3];
    posCorps[0] = 0.0;
    posCorps[1] = 1.5/2.0 + 1.0/2.0;
    posCorps[2] = 0.0;
    MorceauBonhommeNeige * corps = new MorceauBonhommeNeige(1.f,posCorps,1,tete);

    double * posbas = new double[3];
    posbas[0] = 0.0;
    posbas[1] = 0.0;
    posbas[2] = 0.0;
    root = new MorceauBonhommeNeige(1.5f,posbas,0,corps);
    root->Selected(abs(selectionCourante));
}

BonhommeNeige::~BonhommeNeige(){
    delete root;
}

void BonhommeNeige::Init(Shader* shader){
    root->Init(shader);
}

void BonhommeNeige::Show(Shader* shader){
    root->Animate(shader,t);
}

void BonhommeNeige::Up(){
    t = 1.0;
}

void BonhommeNeige::Down(){
    t = -1.0;
}

void BonhommeNeige::SelectionUp(){
    selectionCourante = (selectionCourante + 1) % 3;
    root->Selected(abs(selectionCourante));
}

void BonhommeNeige::SelectionDown(){
    selectionCourante = (selectionCourante - 1) % 3;
    root->Selected(abs(selectionCourante));
}