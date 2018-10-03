#include "stdafx.h"
#include "Constructeur_DataObjet.h"


void * ConstructeurDataObjet::Construit(int nbParam, ...)
{
	va_list args;
	va_start(args, nbParam);
	string nom = va_arg(args, string);
	va_end(args);
	return new DataObjet(nom);
}

ConstructeurDataObjet::ConstructeurDataObjet()
{
}


ConstructeurDataObjet::~ConstructeurDataObjet()
{
}
