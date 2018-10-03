#pragma once
#include "Data.h"

class DataEcran : public Data
{
private:
	string codeEcranCourant;
	string type;
	string res;

public:
	DataEcran(string code);
	~DataEcran();

	virtual string GetCodeEcranSuivant(uint8_t choix) = 0;
	string GetCodeEcran();
	string GetTypeEcran();
	string GetResEcran();

};

