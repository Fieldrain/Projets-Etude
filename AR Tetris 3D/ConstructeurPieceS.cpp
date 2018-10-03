#include "ConstructeurPieceS.h"


ConstructeurPieceS::ConstructeurPieceS() : ConstructeurPiece()
{
}


ConstructeurPieceS::~ConstructeurPieceS()
{
}


Piece* ConstructeurPieceS::Construit(int* depart){
    vector<unsigned short> combi;

    combi.push_back(0x06C0);
    combi.push_back(0x8C40);
    combi.push_back(0x6C00);
    combi.push_back(0x4620);

    Piece *p = new Piece(combi,S);
    p->Translate(depart);

    return p;
}