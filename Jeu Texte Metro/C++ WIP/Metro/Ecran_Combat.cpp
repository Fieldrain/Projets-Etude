#include "stdafx.h"
#include "Ecran_Combat.h"


Retour * EcranCombat::Runtime(Joueur * Joueur)
{
	Retour* ret = new Retour();
	ret->code = -1;


	while (ret->code == -1) {



	}

	return ret;
}

EcranCombat::EcranCombat(DataEcranCombat* DATA) : data(DATA)
{
	layout = new LayoutCombat(DATA);


	FabriqueEntite* fabriqueE = new FabriqueEntite();

	for each (S_Adversaire* ennemi in data->GetAdversaires())
	{

	}

}


EcranCombat::~EcranCombat()
{
	delete layout;

	delete data;
}
