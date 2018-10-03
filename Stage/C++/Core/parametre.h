#ifndef PARAMETRE_H
#define PARAMETRE_H

#include "element.h"

class Parametre : public Element
{
public:
    Parametre(QString n, QString c, QString u = "");

    QString getUnite();
    void setUnite(QString u);

private:
    QString unite;

};

#endif // PARAMETRE_H
