#include "ConstructeurPieceZ.h"


ConstructeurPieceZ::ConstructeurPieceZ() : ConstructeurPiece()
{
}


ConstructeurPieceZ::~ConstructeurPieceZ()
{
}


Piece* ConstructeurPieceZ::Construit(int* depart){
    vector<unsigned short> combi;

    combi.push_back(0x0C60);
    combi.push_back(0x4C80);
    combi.push_back(0xC600);
    combi.push_back(0x2640);

    Piece *p = new Piece(combi,Z);
    p->Translate(depart);

    return p;
}