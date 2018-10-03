#include "stdafx.h"
#include "Constructeur_EcranAccueil.h"


void * ConstructeurEcranAccueil::Construit(int nbParam, ...)
{
	va_list args;
	va_start(args, nbParam);
	DataEcranAccueil* data = (DataEcranAccueil*) va_arg(args, DataEcran*);
	va_end(args);
	return new EcranAccueil(data);
}

ConstructeurEcranAccueil::ConstructeurEcranAccueil()
{
}


ConstructeurEcranAccueil::~ConstructeurEcranAccueil()
{
}
