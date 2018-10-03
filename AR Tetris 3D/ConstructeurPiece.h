#pragma once
#include "Piece.h"

class ConstructeurPiece
{
public:
	
	virtual Piece* Construit(int* depart) = 0;

	ConstructeurPiece();
	~ConstructeurPiece();
};

