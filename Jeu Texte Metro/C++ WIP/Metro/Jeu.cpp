#include "stdafx.h"
#include "Jeu.h"


void Jeu::Runtime()
{
	bool gameover = false;
	while (!gameover) {

		string type = chapitreCourant->GetEcranCourant()->GetTypeEcran();

		Ecran* ecran = fabriqueEc->Get(type, chapitreCourant->GetEcranCourant());

		Retour* retour = ecran->Runtime(joueur);

		switch (retour->code) {
		case 1: case 2: case 3: case 4:
			chapitreCourant->EcranSuivant(retour->code);
			break;
		}
	}

}

Jeu::Jeu()
{
	chapitreCourant = new Chapitre();
	fabriqueEc = new FabriqueEcran();
	joueur = new Joueur();
}


Jeu::~Jeu()
{
	delete joueur;
	delete chapitreCourant;
	delete fabriqueEc;
}
