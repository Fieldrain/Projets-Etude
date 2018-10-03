#pragma once
#include "Fabrique.h"
#include "Constructeur_DataEcranHistoire.h"
#include "Constructeur_DataEcranCombat.h"
#include "Constructeur_DataEcranAccueil.h"
#include "Constructeur_DataObjet.h"

class FabriqueData :
	public Fabrique
{
public:
	Data* Get(string Type,string code);
	~FabriqueData();
	FabriqueData();
};

