#ifndef XML_H
#define XML_H

#include <QList>
#include <QtXml/QtXml>
#include "groupe.h"


class Xml
{
private:
    QDomDocument *dom;
    QString emplacement;

public:
    Xml(QString e);
    ~Xml();
    QList<QDomElement> getCible(QString cible);
    void saveDonnees(QList<Element*> stations, QList<Element*> parametres, QList<Groupe*> groupes, QStringList configTest);
};

#endif // XML_H
