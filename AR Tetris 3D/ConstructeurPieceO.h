#pragma once

#include "ConstructeurPiece.h"

class ConstructeurPieceO : public ConstructeurPiece
{
public:
	
	Piece* Construit(int* depart);

	ConstructeurPieceO();
	~ConstructeurPieceO();
};

