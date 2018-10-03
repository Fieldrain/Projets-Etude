#pragma once
#include "Constructeur_Data.h"
#include "DataObjet.h"

class ConstructeurDataObjet :
	public ConstructeurData
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurDataObjet();
	~ConstructeurDataObjet();
};

