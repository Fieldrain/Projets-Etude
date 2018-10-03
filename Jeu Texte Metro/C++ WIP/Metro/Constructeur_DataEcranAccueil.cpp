#include "stdafx.h"
#include "Constructeur_DataEcranAccueil.h"


void* ConstructeurDataEcranAccueil::Construit(int nbParam, ...)
{
	va_list args;
	va_start(args, nbParam);
	string code = va_arg(args,string);
	va_end(args);
	return new DataEcranAccueil(code);
}

ConstructeurDataEcranAccueil::ConstructeurDataEcranAccueil()
{
}


ConstructeurDataEcranAccueil::~ConstructeurDataEcranAccueil()
{
}
