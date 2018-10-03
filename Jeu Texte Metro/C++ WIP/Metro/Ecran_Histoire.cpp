#include "stdafx.h"
#include "Ecran_Histoire.h"


EcranHistoire::EcranHistoire(DataEcranHistoire* DATA) : data(DATA)
{
	layout = new LayoutHistoire(DATA);
}


EcranHistoire::~EcranHistoire()
{
	delete layout;

	delete data;

}
