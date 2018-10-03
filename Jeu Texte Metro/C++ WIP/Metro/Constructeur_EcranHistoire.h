#pragma once
#include "Constructeur.h"
#include "Ecran_Histoire.h"

class ConstructeurEcranHistoire :
	public Constructeur
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurEcranHistoire();
	~ConstructeurEcranHistoire();
};

