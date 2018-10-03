#include "stdafx.h"
#include "Fabrique_Ecran.h"


FabriqueEcran::FabriqueEcran() : Fabrique()
{
	constructeurs["Combat"] = new ConstructeurEcranCombat();
	constructeurs["Histoire"] = new ConstructeurEcranHistoire();
	constructeurs["Accueil"] = new ConstructeurEcranAccueil();
}

Ecran * FabriqueEcran::Get(string Type, DataEcran* data)
{
	return (Ecran*) constructeurs[Type]->Construit(1,data);
}


FabriqueEcran::~FabriqueEcran()
{
}
