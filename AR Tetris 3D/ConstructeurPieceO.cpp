#include "ConstructeurPieceO.h"


ConstructeurPieceO::ConstructeurPieceO() : ConstructeurPiece()
{
}


ConstructeurPieceO::~ConstructeurPieceO()
{
}


Piece* ConstructeurPieceO::Construit(int* depart){
    vector<unsigned short> combi;

    combi.push_back(0xCC00);
    combi.push_back(0xCC00);
    combi.push_back(0xCC00);
    combi.push_back(0xCC00);

    Piece *p = new Piece(combi,O);
    p->Translate(depart);

    return p;
}