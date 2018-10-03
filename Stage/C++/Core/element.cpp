#include "element.h"

// classe qui represente un element une station ou un parametre
// donnees est un dictionnaire qui a pour cle le nom du parametre et pour valeur la liste des valeurs
// les donnees sont uniquement presentent dans les stations
/*--------------------------------CONSTRUCTEURS--------------------------------*/
Element::Element()
{   
}

Element::Element(QString n, QString c, QString s):
    nom(n),
    couleur(c),
    statut(s),
    nombreValeur(0),
    nombreValeurAttendu(0)
{
}

/*--------------------------------FONCTIONS PUBLICS--------------------------------*/
QString Element::getCouleur(){
    return couleur;
}

QString Element::getNom(){
    return nom;
}

QString Element::getStatut(){
    return statut;
}

QString Element::getCategorie(){
    return categorie;
}

int Element::getNbValeur(){
    return nombreValeur;
}

int Element::getNbValeurAttendu(){
    return nombreValeurAttendu;
}

void Element::setCouleur(QString c){
    couleur = c;
}

void Element::setNom(QString n){
    nom = n;
}

void Element::setStatut(QString s){
    statut = s;
}

void Element::setCategorie(QString c){
    categorie = c;
}

void Element::addNbValeur(int v){
    nombreValeur += v;
}

void Element::addNbValeurAttendu(int v){
    nombreValeurAttendu += v;
}

/*--------------------------------FONCTIONS OPERATEUR--------------------------------*/
bool Element::operator ==(Element e){
    if(e.getNom()==this->nom && e.getCouleur()==this->couleur && e.getStatut()==this->statut)
        return true;
    else
        return false;
}
