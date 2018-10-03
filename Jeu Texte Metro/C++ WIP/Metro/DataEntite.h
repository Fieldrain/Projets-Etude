#pragma once
#include "Data.h"
class DataEntite :
	public Data
{
private:
	S_Stat* Statistique;
	string Nom;
	S_ListObjet* LootTable;

public:
	DataEntite(string nom);
	~DataEntite();
};

