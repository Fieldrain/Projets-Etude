#ifndef GESTIONDATE_H
#define GESTIONDATE_H
#include <QDateTime>
#include <QPointF>

class GestionDate
{
public:
    GestionDate(QDateTime dd, QDateTime df);

    QDateTime getDateMin();
    QDateTime getDateMax();
    void setDateMin(QDateTime d);
    void setDateMax(QDateTime d);
    QDateTime getDateFin();
    QDateTime getDateDeb();
    QDateTime getDateFromPoint(int nb, QPointF echelleX);
    int ecart(int intervalleMin);
    int ecart(int intervalleMin, QDateTime d);

private:
    QDateTime dateDeb;
    QDateTime dateFin;
    QDateTime dateMin;
    QDateTime dateMax;
};

#endif // GESTIONDATE_H
