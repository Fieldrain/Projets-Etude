#pragma once
#include "Constructeur.h"
#include "Ecran_Accueil.h"

class ConstructeurEcranAccueil :
	public Constructeur
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurEcranAccueil();
	~ConstructeurEcranAccueil();
};

