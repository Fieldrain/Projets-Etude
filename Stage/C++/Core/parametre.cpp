#include "parametre.h"

Parametre::Parametre(QString n, QString c, QString u):
    Element(n,c,"Parametre"),
    unite(u)
{
}

QString Parametre::getUnite(){
    return unite;
}

void Parametre::setUnite(QString u){
    unite = u;
}

