#include "stdafx.h"
#include "Fabrique_Data.h"

FabriqueData::FabriqueData() : Fabrique()
{
	constructeurs["Histoire"] = new ConstructeurDataEcranHistoire();
	constructeurs["Combat"] = new ConstructeurDataEcranCombat();
	constructeurs["Accueil"] = new ConstructeurDataEcranAccueil();
	constructeurs["Objet"] = new ConstructeurDataObjet();
}

Data * FabriqueData::Get(string Type, string code)
{
	return (Data*)constructeurs[Type]->Construit(1,code);
}


FabriqueData::~FabriqueData()
{
}
