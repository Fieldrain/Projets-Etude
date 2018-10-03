#pragma once
#include "Entite.h"
#include "Constructeur.h"

class ConstructeurEntite:
	public Constructeur
{
public:
	void* Construit(int nbParam, ...);
	ConstructeurEntite();
	~ConstructeurEntite();
};

