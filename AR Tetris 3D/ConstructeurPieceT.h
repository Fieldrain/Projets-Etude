#pragma once

#include "ConstructeurPiece.h"

class ConstructeurPieceT : public ConstructeurPiece
{
public:
	
	Piece* Construit(int* depart);

	ConstructeurPieceT();
	~ConstructeurPieceT();
};

