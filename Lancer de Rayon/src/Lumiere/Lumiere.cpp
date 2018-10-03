#include "Lumiere.h"

Lumiere::Lumiere(Couleur* CouleurLumiere, Vect LumierePosition, Vect Attenuation) : couleur(CouleurLumiere),position(LumierePosition),attenuation(Attenuation){

}

Lumiere::~Lumiere(){

}

Vect Lumiere::GetPosition() const{
    return position;
}

Couleur* Lumiere::GetCouleur() const{
    return couleur;
}

Vect Lumiere::GetAttenuation() const{
    return attenuation;
}