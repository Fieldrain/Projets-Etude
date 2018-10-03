#include "Controleur.h"


Controleur::Controleur(Scene *s) : scene(s)
{
}


Controleur::~Controleur()
{
}

//ajoute l'objet a la scene
void Controleur::AddObjet(Objet* o){
	scene->AddObjet(o);
	Notifie();
}

void Controleur::SetLecture(){
	scene->SetLecture();
	Notifie();
}

void Controleur::Resize(Size theGlWindowSize){
	scene->Resize(theGlWindowSize);
	Notifie();
}

void Controleur::DeplacePiece(Sens s){
	scene->DeplacePiece(s);
	Notifie();
}
	
void Controleur::RotatePiece(SensRotation s){
	scene->RotatePiece(s);
	Notifie();
}