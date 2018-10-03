#include "stdafx.h"
#include "Layout_Combat.h"

LayoutCombat::LayoutCombat(DataEcranCombat* Data):Layout(),data(Data)
{
}


void LayoutCombat::Affichage()
{
}

LayoutCombat::~LayoutCombat()
{
	// ne pas delete la variable data car effectuer par la classe ecran qui possede le layout
}
