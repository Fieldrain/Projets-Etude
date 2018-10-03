#pragma once
#include "DataEcran.h"
class DataEcranAccueil :
	public DataEcran
{
private:
	string texte;
	S_ListChoix menu;
public:
	string GetCodeEcranSuivant(uint8_t choix);
	DataEcranAccueil(string code);
	~DataEcranAccueil();
};

