#include "station.h"

Station::Station(QString n, QString c):
    Element(n,c,"Station")
{
}

QList<double> Station::getDonne(QString nom){
    return donnees.value(nom);
}

QStringList Station::getListDonne(){
    return donnees.keys();
}

void Station::setDonne(QString n, double d){
    QList<double> donne;

    if(!donnees.value(n).isEmpty())
        donne=donnees.value(n);

    donne.append(d);
    donnees.insert(n,donne);
}

void Station::setMinMax(QString p, double donne){
    if(max.value(p)<donne){
        max.insert(p,donne);
    }

    if(min.value(p)>donne){
        min.insert(p,donne);
    }
}

double Station::getMax(QString p){
    return max.value(p);
}

double Station::getMin(QString p){
    return min.value(p);
}
