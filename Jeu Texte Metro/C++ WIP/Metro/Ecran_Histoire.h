#pragma once
#include "Ecran.h"
#include "Layout_Histoire.h"

class EcranHistoire :
	public Ecran
{
private:
	DataEcranHistoire* data;
	LayoutHistoire* layout;

public:
	EcranHistoire(DataEcranHistoire* DATA);
	~EcranHistoire();
};

