#include "Piece.h"
#include <iostream>

Piece::Piece() : Objet("Piece")
{
    
}

Piece::Piece(Piece* p) : Objet("Piece"), type(p->GetType())
{
}

Piece::Piece(vector<unsigned short> Combinaison,TypePiece Type) : Objet("Piece"), combinaison(Combinaison), type(Type), direction(0)
{
}


Piece::~Piece()
{
}


void Piece::Affiche(){
    glPushMatrix();

    vector<vector<int>> * shape = GetShape();

    for(int i=0;i<shape->size();i++)
        {
            vector<int> p = shape->at(i);
            float x = 0.01 * p[0];
            float y = 0.01 * p[1];
            float z = 0.01 * p[2];

            glPushMatrix();
                glColor3f(0,0,1);
                glTranslatef(x, z, y);
                glutSolidCube(0.01);
            glPopMatrix();

        }

    glPopMatrix();
}

void Piece::Translate(float x, float y, float z){

}

void Piece::Translate(int *pos){
    originX += pos[0];
    originY += pos[1];
    originZ += pos[2];
}

void Piece::Rotate(int type){
    if(type == 0){
        direction = (direction + 1) % combinaison.size();
    }else
        direction = (direction - 1) % combinaison.size(); 
}

void Piece::Scale(){

}

vector<vector<int>>* Piece::GetShape(){
    
    int ligne = 0 ;
    int colonne = 0;
    unsigned short combi = combinaison[direction];

    vector<vector<int>>* shape = new vector<vector<int>>();

    for(unsigned short bit = 0x8000;bit > 0; bit = bit >> 1){
        if(combi & bit){
            vector<int> p(3);
            p[0] = (int)originX+colonne;
            p[1] = (int)originY+ligne;
            p[2] = (int)originZ;

            shape->push_back(p);
        }

        if(++colonne == 4){
            colonne = 0;
            ligne++;
        }
    }

    return shape;

}

TypePiece Piece::GetType(){
    return type;
}