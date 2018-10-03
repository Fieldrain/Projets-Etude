#include "stdafx.h"
#include "Constructeur_DataEcranCombat.h"

void* ConstructeurDataEcranCombat::Construit(int nbParam,...)
{
	va_list args;
	va_start(args, nbParam);
	string code = va_arg(args, string);
	va_end(args);
	return new DataEcranCombat(code);
}

ConstructeurDataEcranCombat::ConstructeurDataEcranCombat()
{
}


ConstructeurDataEcranCombat::~ConstructeurDataEcranCombat()
{
}
