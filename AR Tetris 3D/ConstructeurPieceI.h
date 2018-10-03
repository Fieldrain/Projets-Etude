#pragma once
#include "ConstructeurPiece.h"

class ConstructeurPieceI : public ConstructeurPiece
{
public:
	
	Piece* Construit(int* depart);

	ConstructeurPieceI();
	~ConstructeurPieceI();
};

