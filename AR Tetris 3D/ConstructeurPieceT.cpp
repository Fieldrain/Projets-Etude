#include "ConstructeurPieceT.h"


ConstructeurPieceT::ConstructeurPieceT() : ConstructeurPiece()
{
}


ConstructeurPieceT::~ConstructeurPieceT()
{
}


Piece* ConstructeurPieceT::Construit(int* depart){
    vector<unsigned short> combi;

    combi.push_back(0x0E40);
    combi.push_back(0x4C40);
    combi.push_back(0x4E00);
    combi.push_back(0x4640);

    Piece *p = new Piece(combi,T);
    p->Translate(depart);

    return p;
}