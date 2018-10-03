#pragma once
#include "Ecran.h"
#include "Layout_Combat.h"
#include "Fabrique_Entite.h"

class EcranCombat :
	public Ecran
{
private:
	DataEcranCombat* data;
	LayoutCombat* layout;

	set<Entite> Ennemis;

public:
	Retour* Runtime(Joueur* Joueur);

	EcranCombat(DataEcranCombat* DATA);
	~EcranCombat();
};

