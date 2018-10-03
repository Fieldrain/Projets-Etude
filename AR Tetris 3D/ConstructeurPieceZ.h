#pragma once

#include "ConstructeurPiece.h"

class ConstructeurPieceZ : public ConstructeurPiece
{
public:
	
	Piece* Construit(int* depart);

	ConstructeurPieceZ();
	~ConstructeurPieceZ();
};

