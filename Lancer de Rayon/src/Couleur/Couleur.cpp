#include "Couleur.h"

Couleur::Couleur(Vect couleurSpeculaire, Vect couleurDiffuse, Vect couleurAmbient) : V_Speculaire(couleurSpeculaire),V_Diffuse(couleurDiffuse),V_Ambient(couleurAmbient){

}

Couleur::~Couleur(){

}

Vect Couleur::GetValue(TypeCouleur type) const{

    switch(type){
        case Diffuse:
            return V_Diffuse;
        break;
        case Speculaire:
            return V_Speculaire;
        break;
        case Ambient:
            return V_Ambient;
        break;
    }
}

Vect Couleur::GetSum() const{
    return V_Ambient + V_Diffuse + V_Speculaire;
}

Couleur Couleur::operator+(const Couleur c){
    return Couleur((V_Speculaire+c.GetValue(Speculaire))/2,(V_Diffuse+c.GetValue(Diffuse))/2,(V_Ambient+c.GetValue(Ambient))/2);
}
void Couleur::operator+=(const Couleur c){
    V_Speculaire = (V_Speculaire+c.GetValue(Speculaire))/2;
    V_Diffuse = (V_Diffuse+c.GetValue(Diffuse))/2;
    V_Ambient = (V_Ambient+c.GetValue(Ambient))/2;
}

ostream& operator<<(ostream& os, const Couleur& c){
    os << c.V_Speculaire << "|" << c.V_Diffuse << "|" << c.V_Ambient << " = " << c.GetSum().clip();
    return os; 
}