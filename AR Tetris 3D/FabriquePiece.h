#pragma once
#include "ConstructeurPieceI.h"
#include "ConstructeurPieceO.h"
#include "ConstructeurPieceT.h"
#include "ConstructeurPieceL.h"
#include "ConstructeurPieceJ.h"
#include "ConstructeurPieceZ.h"
#include "ConstructeurPieceS.h"
#include <set>
#include <map>

class FabriquePiece
{
private:
	map<TypePiece, ConstructeurPiece*> constructeurs;

	FabriquePiece(const FabriquePiece&);
	void operator=(const FabriquePiece&) {};
	
public:
	set<TypePiece> Types() const;
	Piece* ConstruitPiece(TypePiece type, int* depart);
	FabriquePiece();
	~FabriquePiece();
};

