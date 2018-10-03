#pragma once
#include "Joueur.h"

class Ecran
{
public:
	virtual Retour* Runtime(Joueur* Joueur) =0;
	Ecran();
	~Ecran();
};

