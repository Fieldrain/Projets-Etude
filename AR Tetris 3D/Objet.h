#pragma once

#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include <vector>
#include "Couleur.h"

using namespace std;

class Objet
{
protected:
	string type;
	GLenum typeAffichage;

	float originX;
	float originY;
	float originZ;

	Couleur *color;

public:
	// Constructeurs
	Objet(string t);
	Objet(string t,float x, float y, float z, Couleur *c);

	float GetOriginX();
	float GetOriginY();
	float GetOriginZ();

	Couleur* GetColor();
	string GetType();
	void SetAffichage(GLenum ta);

	virtual void Affiche() = 0;
	virtual void Translate(float x, float y, float z) = 0;
	virtual void Rotate(int type) = 0;
	virtual void Scale() = 0;

	//Destructeurs
	~Objet();
};

