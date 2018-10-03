#include "gestiondate.h"

// classe qui permet de gérer les dates dans le programme (essentiellement dans la scene)

/*--------------------------------CONSTRUCTEURS--------------------------------*/
GestionDate::GestionDate(QDateTime dd, QDateTime df):
    dateDeb(dd),
    dateFin(df),
    dateMin(dd),
    dateMax(df)
{
}

/*--------------------------------FONCTIONS PUBLICS--------------------------------*/
QDateTime GestionDate::getDateMax(){
    return dateMax;
}

QDateTime GestionDate::getDateMin(){
    return dateMin;
}

void GestionDate::setDateMax(QDateTime d){
    dateMax = d;
}

void GestionDate::setDateMin(QDateTime d){
    dateMin = d;
}

QDateTime GestionDate::getDateDeb(){
    return dateDeb;
}

QDateTime GestionDate::getDateFin(){
    return dateFin;
}

// fonction qui permet de recuperer la date par rapport a la valeur en x d'une point dans la scene
QDateTime GestionDate::getDateFromPoint(int nb, QPointF echelleX){
    nb = nb/echelleX.y();

    int uniteX = static_cast<int>(echelleX.x());

    switch(uniteX){
    case 0:
        nb = nb*15*60;
        break;
    case 1:
        nb = nb*60*60;
        break;
    case 2:
        nb = nb*60*60*12;
        break;
    case 3:
        nb = nb*60*60*24;
        break;
    case 4:
        nb = nb*60*60*24*7;
        break;

    }

    return dateMin.addSecs(nb);
}

// fonction qui permet de recuperer le nombre de valeurs entre deux date avec un intervalle donne
int GestionDate::ecart(int intervalleMin){
    QDateTime date = dateMin;
    int nbVal =1;

    while(date<dateMax){
        nbVal ++;
        date = date.addSecs(60*intervalleMin);
    }

    return nbVal;
}

int GestionDate::ecart(int intervalleMin,QDateTime d){
    QDateTime date = dateMin;
    int nbVal =1;

    while(date<d){
        nbVal ++;
        date = date.addSecs(60*intervalleMin);
    }

    return nbVal;
}

