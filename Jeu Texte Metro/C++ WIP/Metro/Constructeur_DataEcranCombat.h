#pragma once
#include "Constructeur.h"
#include "DataEcranCombat.h"

class ConstructeurDataEcranCombat :
	public Constructeur
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurDataEcranCombat();
	~ConstructeurDataEcranCombat();
};

