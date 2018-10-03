#pragma once
#include "Constructeur.h"
#include "Ecran_Combat.h"

class ConstructeurEcranCombat :
	public Constructeur
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurEcranCombat();
	~ConstructeurEcranCombat();
};

