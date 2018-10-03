#pragma once
#include "Fabrique_Data.h"

class Chapitre
{
private:
	uint8_t numeroChapitre;
	DataEcran* ecranCourant;
	FabriqueData* fabrique;

public:
	DataEcran* GetEcranCourant();
	uint8_t GetNumeroChapitre();

	bool EcranSuivant(uint8_t choix);
	bool ChangerChapitre(uint8_t numeroAncienChapitre, string codeEcran = "null");

	Chapitre();
	Chapitre(uint8_t numero, string ecran);
	~Chapitre();
};

