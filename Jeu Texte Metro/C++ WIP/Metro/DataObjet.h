#pragma once
#include "Data.h"
class DataObjet:
	public Data
{
private:
	string Categorie;
	string Nom;

public:
	DataObjet(string nom);
	~DataObjet();
};

