#pragma once
#include "Joueur.h"
#include "Chapitre.h"
#include "Fabrique_Ecran.h"
#include "Fabrique_Entite.h"

class Jeu
{
private:
	Joueur* joueur;
	Chapitre* chapitreCourant;
	FabriqueEcran* fabriqueEc;

public:

	void Runtime();

	Jeu();
	~Jeu();
};

