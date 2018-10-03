#pragma once
#include "DataObjet.h"
class DataObjetArme :
	public DataObjet
{
private:
	uint8_t Degat;
	uint8_t DegatCritique;
	string Munition;

public:
	DataObjetArme(string nom);
	~DataObjetArme();
};

