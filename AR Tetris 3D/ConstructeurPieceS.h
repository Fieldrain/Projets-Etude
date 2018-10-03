#pragma once

#include "ConstructeurPiece.h"

class ConstructeurPieceS : public ConstructeurPiece
{
public:
	
	Piece* Construit(int* depart);

	ConstructeurPieceS();
	~ConstructeurPieceS();
};

