#ifndef GROUPES_H
#define GROUPES_H

#include <QWidget>
#include "modele.h"
#include "xml.h"
#include "groupe.h"

class Groupes: public Modele
{
public:
    Groupes();
    Groupes(QList<Element*> stations,QList<Element*> parametres, Xml *xml);
    ~Groupes();

    QList<QString> getListNomParent();
    Groupe* getGroupe(QString nomPere);
    QStringList getNomFils(Groupe* groupe);
    void setFils(Element *p,QList<Element*> oldFils, QList<Element*> newFils);
    void setPere(Element *oldPere, Element *newPere);
    void removeFils(Element *pere, QList<Element*> fils);
    void removeGroupe(Groupe *g);
    void addGroupe(Element *newPere, QList<Element*> newFils);
    QList<Groupe*> getListGroupe();
    void removeElementFils(Element *element);

private:
    QList<Groupe*> groupes;

    bool estDans(QString nom , QList<Element *> list);
    Element* rechercheElement(QString nom, QList<Element *> list);
    QList<QList<Element*> > rechercheFils(QDomElement pere, QList<Element *>  list);

};

#endif // GROUPES_H
