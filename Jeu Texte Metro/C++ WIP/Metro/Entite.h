#pragma once
#include "Inventaire.h"

struct Stat {
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

struct Level {
	uint8_t level;
	uint8_t xp;
	uint8_t xpNextLevel;
};

class Entite
{
private:
	string nom;
	Stat* statistique;
	Inventaire* inventaire;

public:
	Entite();
	~Entite();
};

