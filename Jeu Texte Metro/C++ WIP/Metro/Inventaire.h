#pragma once
#include "Objet.h"

class Inventaire
{
private:
	uint8_t poids;
	uint8_t poidsMax;
	set<Objet*> listObjets;

public:
	uint8_t AjouterObjet(Objet* ob);
	uint8_t EnleverObjet(Objet* ob);
	Objet* GetObjet(uint8_t ob);
	Inventaire();
	~Inventaire();
};

