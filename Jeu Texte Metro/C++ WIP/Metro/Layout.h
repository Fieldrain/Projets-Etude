#pragma once

#include "Fenetre.h"
#include "Window.h"
#include "DataEcran.h"

class Layout
{
protected:
	IFenetre* fenetre;

public:
	virtual void Affichage() =0;
	string RetourUtilisateur();

	Layout();
	Layout(IFenetre* Fenetre);
	~Layout();
};

