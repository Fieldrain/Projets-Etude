#pragma once

#include "ConstructeurPiece.h"

class ConstructeurPieceL : public ConstructeurPiece
{
public:
	
	Piece* Construit(int* depart);

	ConstructeurPieceL();
	~ConstructeurPieceL();
};

