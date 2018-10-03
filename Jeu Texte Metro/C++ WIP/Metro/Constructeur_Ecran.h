#pragma once
#include "Ecran.h"
#include "Constructeur.h"

class ConstructeurEcran:
	public Constructeur
{
public:
	virtual void* Construit(DataEcran* data) =0;
	ConstructeurEcran();
	~ConstructeurEcran();
};

