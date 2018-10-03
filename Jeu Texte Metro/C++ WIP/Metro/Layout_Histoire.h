#pragma once
#include "Layout.h"
#include "DataEcranHistoire.h"

class LayoutHistoire :
	public Layout
{
private:
	DataEcranHistoire* data;
public:
	void Affichage();

	LayoutHistoire(DataEcranHistoire* Data);
	~LayoutHistoire();
};

