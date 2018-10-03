#include "ConstructeurPieceI.h"

ConstructeurPieceI::ConstructeurPieceI() : ConstructeurPiece()
{
}


ConstructeurPieceI::~ConstructeurPieceI()
{
}


Piece* ConstructeurPieceI::Construit(int* depart){
    vector<unsigned short> combi;

    combi.push_back(0x0F00);
    combi.push_back(0x2222);
    combi.push_back(0x00F0);
    combi.push_back(0x4444);

    Piece *p = new Piece(combi,I);
    p->Translate(depart);

    return p;
}