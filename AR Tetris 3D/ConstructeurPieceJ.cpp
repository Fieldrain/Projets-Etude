#include "ConstructeurPieceJ.h"


ConstructeurPieceJ::ConstructeurPieceJ() : ConstructeurPiece()
{
}


ConstructeurPieceJ::~ConstructeurPieceJ()
{
}


Piece* ConstructeurPieceJ::Construit(int* depart){
    vector<unsigned short> combi;

    combi.push_back(0x44C0);
    combi.push_back(0x8E00);
    combi.push_back(0x6440);
    combi.push_back(0x0E20);

    Piece *p = new Piece(combi,J);
    p->Translate(depart);

    return p;
}