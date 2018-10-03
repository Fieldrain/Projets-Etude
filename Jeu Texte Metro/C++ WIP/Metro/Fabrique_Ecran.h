#pragma once
#include "Fabrique.h"
#include "Constructeur_EcranAccueil.h"
#include "Constructeur_EcranCombat.h"
#include "Constructeur_EcranHistoire.h"

class FabriqueEcran:
	public Fabrique
{
public:
	FabriqueEcran();
	Ecran* Get(string Type, DataEcran* data);
	~FabriqueEcran();
};

