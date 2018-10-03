#pragma once
#include "XmlReader.h"

struct S_Choix {
	uint8_t numero;
	uint8_t position;
	string text;
	string codeSuivant;
};

struct S_ListChoix {
	uint8_t nbChoix;
	set<S_Choix*> choices;
};

struct S_Script {
	string text;
	set<string> variable;
};

struct S_Objet {
	string nom;
	uint8_t quantite;
	uint8_t drop = -1;
};

struct S_ListObjet {
	set<S_Objet*> objets;
};

struct S_Adversaire {
	string nom;
	uint8_t nombre;
};

struct S_Victoire {
	string codeSuivant;
};

struct S_Defaite {
	string codeSuivant;
};

struct S_Stat {
	uint8_t vie;
	uint8_t maxVie;

	uint8_t energie;
	uint8_t maxEnergie;

	uint8_t esquive;
	uint8_t resistance;
	uint8_t force;
	uint8_t concentration;
	uint8_t vitesse;
	uint8_t precision;
	uint8_t discretion;
};

class Data
{
public:
	Data();
	~Data();
};

