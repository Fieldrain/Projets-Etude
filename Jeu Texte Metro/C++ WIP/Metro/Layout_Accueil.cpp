#include "stdafx.h"
#include "Layout_Accueil.h"

LayoutAccueil::LayoutAccueil(DataEcranAccueil* Data) : Layout(),data(Data)
{
}


void LayoutAccueil::Affichage()
{
}

void LayoutAccueil::Credit()
{
}

LayoutAccueil::~LayoutAccueil()
{
	// ne pas delete la variable data car effectuer par la classe ecran qui possede le layout
}
