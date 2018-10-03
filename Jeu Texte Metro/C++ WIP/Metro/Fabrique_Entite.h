#pragma once
#include "Fabrique.h"
#include "Entite.h"
#include "Constructeur_Entite.h"

class FabriqueEntite:
	public Fabrique
{
public:
	FabriqueEntite();
	Entite* Get(string Type);
	~FabriqueEntite();
};

