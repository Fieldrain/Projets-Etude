#ifndef STATION_H
#define STATION_H

#include <QMap>
#include <QStringList>
#include "element.h"

class Station : public Element
{
public:
    Station(QString n, QString c);

    QList<double> getDonne(QString nom);
    QStringList getListDonne();
    void setDonne(QString n, double d);
    void setMinMax(QString p, double donne);
    double getMin(QString p);
    double getMax(QString p);
private:
    QMap<QString,QList<double> > donnees;
    QMap<QString,double> max;
    QMap<QString,double> min;
};

#endif // STATION_H
