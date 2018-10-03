#ifndef STATIONS_H
#define STATIONS_H

#include <QMap>

#include "xml.h"
#include "station.h"
#include "modele.h"

class Stations : public Modele
{
public:
    Stations(Xml *xml);
    ~Stations();

    QList<Element*> getListStation();
    QList<Element*> getListStation(QList<QString> listNom);
    Element *getStation(QString nom);
    QList<QString> getListNomStation();
    QList<QString> getListCouleurStation();
    QString getCouleurStation(QString nom);
    void setCouleurStation(QString nom, QString couleur);
    void setNomStation(QString oldNom , QString newNom);
    bool isStation(QString nom);
    void addStation(QString nom);
    void setCategorie(QString nom, QString categorie);
    void removeStation(QString nomStation);

private:
    QMap<QString, Station*> stations;
};

#endif // STATIONS_H
