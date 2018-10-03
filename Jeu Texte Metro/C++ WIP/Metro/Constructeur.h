#pragma once

class Constructeur
{
public:
	
	virtual void* Construit(int nbParam,...) = 0;

	Constructeur();
	~Constructeur();
};

