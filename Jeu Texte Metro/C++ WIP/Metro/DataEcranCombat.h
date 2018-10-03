#pragma once
#include "DataEcran.h"

class DataEcranCombat :
	public DataEcran
{
private:
	S_Victoire* victoire;
	S_Defaite* defaite;
	set<S_Adversaire*> listAdversaire;
public:
	string GetCodeEcranSuivant(uint8_t choix);
	set<S_Adversaire*> GetAdversaires();

	DataEcranCombat(string code);
	~DataEcranCombat();
};

