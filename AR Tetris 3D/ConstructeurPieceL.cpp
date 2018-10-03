#include "ConstructeurPieceL.h"


ConstructeurPieceL::ConstructeurPieceL() : ConstructeurPiece()
{
}


ConstructeurPieceL::~ConstructeurPieceL()
{
}


Piece* ConstructeurPieceL::Construit(int* depart){
    vector<unsigned short> combi;

    combi.push_back(0x4460);
    combi.push_back(0x0E80);
    combi.push_back(0xC440);
    combi.push_back(0x2E00);

    Piece *p = new Piece(combi,L);
    p->Translate(depart);

    return p;
}