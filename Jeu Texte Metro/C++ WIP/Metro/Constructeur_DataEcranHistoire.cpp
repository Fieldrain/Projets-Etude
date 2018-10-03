#include "stdafx.h"
#include "Constructeur_DataEcranHistoire.h"


void* ConstructeurDataEcranHistoire::Construit(int nbParam, ...)
{
	va_list args;
	va_start(args, nbParam);
	string code = va_arg(args, string);
	va_end(args);
	return new DataEcranHistoire(code);
}

ConstructeurDataEcranHistoire::ConstructeurDataEcranHistoire()
{
}


ConstructeurDataEcranHistoire::~ConstructeurDataEcranHistoire()
{
}
