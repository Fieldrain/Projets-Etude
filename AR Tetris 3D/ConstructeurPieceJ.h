#pragma once

#include "ConstructeurPiece.h"

class ConstructeurPieceJ : public ConstructeurPiece
{
public:
	
	Piece* Construit(int* depart);

	ConstructeurPieceJ();
	~ConstructeurPieceJ();
};

