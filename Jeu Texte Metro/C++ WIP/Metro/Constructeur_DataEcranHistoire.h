#pragma once
#include "Constructeur.h"
#include "DataEcranHistoire.h"

class ConstructeurDataEcranHistoire :
	public Constructeur
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurDataEcranHistoire();
	~ConstructeurDataEcranHistoire();
};

