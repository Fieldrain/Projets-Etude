#include "stdafx.h"
#include "Constructeur_EcranCombat.h"


void* ConstructeurEcranCombat::Construit(int nbParam, ...) {

	va_list args;
	va_start(args, nbParam);
	DataEcranCombat* data = (DataEcranCombat*)va_arg(args, DataEcran*);
	va_end(args);
	return new EcranCombat(data);
}

ConstructeurEcranCombat::ConstructeurEcranCombat()
{
}


ConstructeurEcranCombat::~ConstructeurEcranCombat()
{
}
