#pragma once

#include "Sujet.h"
#include "Scene.h"

class Controleur : public Sujet
{
private:
	Scene * scene;

public:
	Controleur(Scene *s);
	~Controleur();
	void AddObjet(Objet* o);
	void SetLecture();
	void Resize(Size theGlWindowSize);
	void DeplacePiece(Sens s);
	void RotatePiece(SensRotation s);
};

