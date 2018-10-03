#include "stdafx.h"
#include "Layout_Histoire.h"


void LayoutHistoire::Affichage()
{
}

LayoutHistoire::LayoutHistoire(DataEcranHistoire* Data) : Layout(), data(Data)
{
}


LayoutHistoire::~LayoutHistoire()
{
	// ne pas delete la variable data car effectuer par la classe ecran qui possede le layout
}
