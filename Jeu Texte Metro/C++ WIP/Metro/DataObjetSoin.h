#pragma once
#include "DataObjet.h"
class DataObjetSoin :
	public DataObjet
{
private:
	uint8_t Soin;

public:
	DataObjetSoin(string nom);
	~DataObjetSoin();
};

