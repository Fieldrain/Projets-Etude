#include "FabriquePiece.h"

set<TypePiece> FabriquePiece::Types() const
{
	set<TypePiece> types;

	for (auto cons : constructeurs)
	{
		types.insert(cons.first);
	}

	return types;
}

FabriquePiece::FabriquePiece()
{
	constructeurs[I] = new ConstructeurPieceI();
	constructeurs[O] = new ConstructeurPieceO();
	constructeurs[T] = new ConstructeurPieceT();
	constructeurs[L] = new ConstructeurPieceL();
	constructeurs[J] = new ConstructeurPieceJ();
	constructeurs[Z] = new ConstructeurPieceZ();
	constructeurs[S] = new ConstructeurPieceS();
}


FabriquePiece::~FabriquePiece()
{
	for (auto p : constructeurs)
		delete p.second;
}

Piece* FabriquePiece::ConstruitPiece(TypePiece type, int* depart){
	return constructeurs[type]->Construit(depart);
}
