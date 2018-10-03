#pragma once
#include "DataEcran.h"

class DataEcranHistoire:
	public DataEcran
{
private:
	S_Script* script;
	S_ListChoix* listChoix;
	S_ListObjet* loot;

public:
	S_Script* GetScript();
	S_Choix* GetChoix(uint8_t choix);
	string GetCodeEcranSuivant(uint8_t choix);

	DataEcranHistoire(string code);
	~DataEcranHistoire();
};

