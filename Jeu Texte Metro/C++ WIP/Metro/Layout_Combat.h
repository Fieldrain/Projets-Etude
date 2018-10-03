#pragma once
#include "Layout.h"
#include "DataEcranCombat.h"

class LayoutCombat :
	public Layout
{
	DataEcranCombat* data;
public:
	void Affichage();

	LayoutCombat(DataEcranCombat* Data);
	~LayoutCombat();
};

