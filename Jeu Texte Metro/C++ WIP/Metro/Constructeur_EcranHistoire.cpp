#include "stdafx.h"
#include "Constructeur_EcranHistoire.h"


void * ConstructeurEcranHistoire::Construit(int nbParam, ...)
{
	va_list args;
	va_start(args, nbParam);
	DataEcranHistoire* data = (DataEcranHistoire*)va_arg(args, DataEcran*);
	va_end(args);
	return new EcranHistoire(data);
}

ConstructeurEcranHistoire::ConstructeurEcranHistoire()
{
}


ConstructeurEcranHistoire::~ConstructeurEcranHistoire()
{
}
