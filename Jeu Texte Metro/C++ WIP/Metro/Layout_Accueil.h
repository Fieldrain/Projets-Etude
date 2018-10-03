#pragma once
#include "Layout.h"
#include "DataEcranAccueil.h"

class LayoutAccueil :
	public Layout
{
private:
	DataEcranAccueil * data;
public:
	void Affichage();

	void Credit();

	LayoutAccueil(DataEcranAccueil* Data);
	~LayoutAccueil();
};

