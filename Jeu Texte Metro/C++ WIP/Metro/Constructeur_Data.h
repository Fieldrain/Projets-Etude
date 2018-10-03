#pragma once
#include "Constructeur.h"
class ConstructeurData :
	public Constructeur
{
public:
	virtual void* Construit(int nbParam,...) =0;
	ConstructeurData();
	~ConstructeurData();
};

