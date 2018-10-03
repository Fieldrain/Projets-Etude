#include "stations.h"

// classe qui permet de gerer toutes les stations
// herite de la classe modele a chaque modification d'un groupe la classe va appeler la fonction refresh de ces vues(qui sont les interfaces)
// stations est un dictionnaire qui a pour cle le nom de station et comme valeur le pointeur vers la station
/*--------------------------------CONSTRUCTEURS--------------------------------*/
Stations::Stations(Xml *xml){
    QList<QDomElement> listElement = xml->getCible("Stations");

    foreach(QDomElement element, listElement){
        QString nom = element.attribute("nom");
        QString couleur = element.attribute("couleur");
        QString categorie = element.attribute("categorie");
        Station *station = new Station(nom,couleur);
        station->setCategorie(categorie);
        stations.insert(nom,station);
    }
}
/*--------------------------------DESTRUCTEURS--------------------------------*/
Stations::~Stations(){
    foreach(Station* elt,stations.values()){
        if(elt!=NULL)
            delete elt;
    }
    stations.clear();
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
QList<Element*> Stations::getListStation(){
    QList<Element*> listStation;
    foreach(Element* station, stations.values()){
        listStation.append(station);
    }

    return listStation;
}

// fonction qui peremt de recuperer une liste de stations en fonction d'une liste de nom
QList<Element*> Stations::getListStation(QList<QString> listNom){
    QList<Element*> listStation;
    foreach(QString nom, listNom){
        listStation.append(stations.value(nom));
    }

    return listStation;
}

Element* Stations::getStation(QString nom){
    return stations.value(nom);
}

QList<QString> Stations::getListNomStation(){
    return stations.keys();
}

QList<QString> Stations::getListCouleurStation(){
    QList<QString> listCouleur;
    foreach(Station* station , stations.values()){
        listCouleur.append(station->getCouleur());
    }
    return listCouleur;
}

QString Stations::getCouleurStation(QString nom){
    return stations.value(nom)->getCouleur();
}

void Stations::setCouleurStation(QString nom, QString couleur){
    stations.value(nom)->setCouleur(couleur);
    update();
}

void Stations::setNomStation(QString oldNom, QString newNom){
    Station* station = stations.value(oldNom);
    station->setNom(newNom);
    stations.remove(oldNom);
    stations.insert(stations.end(),newNom,station);
    update();
}

// fonction qui permet de savoir si un element est une station
bool Stations::isStation(QString nom){
    return stations.keys().contains(nom);
}

// fonction qui permet d'ajouter un station
void Stations::addStation(QString nom){
    Station *station = new Station(nom,"125,125,125");
    station->setCategorie("Nouveaux");
    stations.insert(nom,station);
    update();
}

void Stations::setCategorie(QString nom,QString categorie){
    Station *station = stations.value(nom);
    station->setCategorie(categorie);
    update();
}

void Stations::removeStation(QString nomStation){
    Station *station = stations.value(nomStation);
    stations.remove(nomStation);
    delete station;
    update();
}
