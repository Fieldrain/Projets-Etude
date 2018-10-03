#include "Couleur.h"


Couleur::Couleur()
{
}

Couleur::Couleur(float r, float g, float b):red(r),green(g),blue(b){

}


Couleur::~Couleur()
{
}

// Getters
float Couleur::GetRed(){
	return red;
}

float Couleur::GetGreen(){
	return green;
}

float Couleur::GetBlue(){
	return blue;
}

void Couleur::GetColor(float *color){
	float c[3] = { red, green, blue };
	color = c;
}

// Setters
void Couleur::SetRed(float r){
	red = r;
}

void Couleur::SetGreen(float g){
	green = g;
}

void Couleur::SetBlue(float b){
	blue = b;
}

void Couleur::SetColor(float *color){
	red = color[0];
	green = color[1];
	blue = color[2];
}