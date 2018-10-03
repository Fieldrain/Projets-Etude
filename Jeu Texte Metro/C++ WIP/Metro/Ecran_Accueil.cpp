#include "stdafx.h"
#include "Ecran_Accueil.h"


Retour* EcranAccueil::Continuer(Retour* ret)
{

	return ret;
}

Retour* EcranAccueil::NouvellePartie(Retour* ret)
{
	ret->code = 2;

	return ret;
}

Retour* EcranAccueil::Credit(Retour* ret)
{
	ret->code = -1;

	while (ret->code == -1) {
		layout->Credit();
		string saisie = layout->RetourUtilisateur();

		if (saisie.compare("Retour"))
			ret->code = 0;
	}
	
	return ret;
}

Retour* EcranAccueil::Runtime(Joueur * Joueur)
{
	Retour* ret = new Retour();
	ret->code = -1;

	while (ret->code == -1) {
		layout->Affichage();
		string saisie = layout->RetourUtilisateur();

		switch (stoi(saisie)) {
		case 1:
			ret = Continuer(ret);
			break;
		case 2:
			ret = NouvellePartie(ret);
			break;
		case 3:
			ret = Credit(ret);
			ret->code = -1;
			break;
		}
	}

	return ret;
}

EcranAccueil::EcranAccueil(DataEcranAccueil* DATA) : data(DATA)
{
	layout = new LayoutAccueil(DATA);
}


EcranAccueil::~EcranAccueil()
{
	delete layout;

	delete data;
}
