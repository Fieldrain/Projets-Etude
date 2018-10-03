#pragma once
#include "Constructeur.h"
#include "DataEcranAccueil.h"

class ConstructeurDataEcranAccueil :
	public Constructeur
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurDataEcranAccueil();
	~ConstructeurDataEcranAccueil();
};

