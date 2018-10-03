#pragma once
#include "Ecran.h"
#include "Layout_Accueil.h"

class EcranAccueil :
	public Ecran
{
private:
	DataEcranAccueil* data;
	LayoutAccueil* layout;

	Retour* Continuer(Retour* ret);
	Retour* NouvellePartie(Retour* ret);
	Retour* Credit(Retour* ret);

public:
	Retour* Runtime(Joueur* Joueur);
	EcranAccueil(DataEcranAccueil* DATA);
	~EcranAccueil();
};

