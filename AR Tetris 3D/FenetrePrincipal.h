#pragma once

#include "Observateur.h"
#include "Scene.h"
#include "Controleur.h"

class FenetrePrincipal : public IObservateur
{
private:
	Scene *scene;
	Controleur* controleur;
	char presse;

	Size theGlWindowSize;

public:
	void MiseAJour();

	void Affichage();
	void Clavier(unsigned char touche, int x, int y);
	void Reshape(int iWidth, int iHeight);
	void Mouse(int button, int state, int x, int y);
	void Idle();

	FenetrePrincipal(int *argc, char **argv, Scene *s, Controleur *c);
	~FenetrePrincipal();
};

