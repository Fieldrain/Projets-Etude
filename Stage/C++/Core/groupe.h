#ifndef GROUPE_H
#define GROUPE_H

#include "element.h"
#include <QList>

class Groupe
{
private:
    Element *pere;
    QList<QList<Element*> > fils;

public:
    Groupe();
    Groupe(Element *p, QList<QList<Element*> > f);
    ~Groupe();

    Element* getPere();
    QList<QList<Element*> > getFils();
    void setFils(QList<Element*> f, int index);
    void setFils(QList<QList<Element*> > f);
    void setPere(Element *p);
    void removeFils(int index);
    void addFils(QList<Element*> f);
    void removeElementFils(Element *element);

    bool operator ==(Groupe *g);
};

#endif // GROUPE_H
