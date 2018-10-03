#include "stdafx.h"
#include "Layout.h"


Layout::Layout(IFenetre* Fenetre) : fenetre(Fenetre)
{
	
}

string Layout::RetourUtilisateur()
{
	return fenetre->RetourSaisi();
}

Layout::Layout()
{
	switch (OS) {
	case 0:
		fenetre = new Window();
		break;
	}
}

Layout::~Layout()
{
	delete fenetre;
}
