#include "Materiel.h"

Materiel::Materiel(Couleur* CouleurParameter,Vect CouleurEmise,double Shininess, Type TypeObject) : couleur(CouleurParameter), shininess(Shininess),emission(CouleurEmise),typeObject(TypeObject){

}

Materiel::~Materiel(){

}

Couleur* Materiel::GetCouleurParameter() const{
    return couleur;
}

double Materiel::GetShininess() const{
    return shininess;
}

Vect Materiel::GetCouleurEmission() const{
    return emission;
}

Type Materiel::GetType() const{
    return typeObject;
}