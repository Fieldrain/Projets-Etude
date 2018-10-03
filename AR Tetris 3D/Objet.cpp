#include "Objet.h"


Objet::Objet(string t) :type(t), originX(0), originY(0), originZ(0), color(new Couleur(1,1,1))
{
}

Objet::Objet(string t,float x, float y, float z, Couleur *c) : type(t) ,originX(x), originY(y), originZ(z), color(c)
{
}

float Objet::GetOriginX(){
	return originX;
}

float Objet::GetOriginY(){
	return originY;
}

float Objet::GetOriginZ(){
	return originZ;
}

Couleur* Objet::GetColor(){
	return color;
}

void Objet::SetAffichage(GLenum ta){
	typeAffichage = ta;
}

string Objet::GetType(){
	return type;
}

Objet::~Objet()
{
	color->~Couleur();
}
