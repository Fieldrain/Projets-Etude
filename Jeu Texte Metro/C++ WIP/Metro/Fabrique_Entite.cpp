#include "stdafx.h"
#include "Fabrique_Entite.h"


FabriqueEntite::FabriqueEntite() : Fabrique()
{
}


Entite * FabriqueEntite::Get(string Type)
{
	return constructeurs[Type]->Construit();
}


FabriqueEntite::~FabriqueEntite()
{

}