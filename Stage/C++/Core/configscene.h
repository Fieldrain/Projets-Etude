#ifndef CONFIGSCENE_H
#define CONFIGSCENE_H

#include <QPointF>
#include <QRect>
#include <QGraphicsEllipseItem>
#include <QMap>

#include "gestiondate.h"
#include <QDebug>

class ConfigScene
{
public:
    ConfigScene();
    ~ConfigScene();

    void init_echelleUnite(QStringList listUnite);
    void init_rectScene(GestionDate *date);
    void setHeight(double h);
    void setWidth(double w);
    void setOrigin(double x,double y);
    void setOrigin(QPointF o);
    void setEchelleY(QPointF echelle);
    void setEchelleX(QPointF echelle);
    void setRect(int h,int w);
    void setRect();
    void setCentreX(double x);
    void setCentreY(double y);
    void setPointCur(QGraphicsEllipseItem* p);
    void setPasY(double p);
    void setYmin(double y);
    void setYmax(double y);
    void setMarqY(double m);
    void setEchelleUnite(QString nom,double val);
    void setAfficherPoint(bool b);


    double getHeight();
    double getWidth();
    QPointF getEchelleX();
    QPointF getEchelleY();
    QPointF getOrigin();
    QRect getRect();
    double getCentreX();
    double getCentreY();
    QGraphicsEllipseItem* getPointCur();
    double getPasY();
    double getYmin();
    double getYmax();
    double getMarqY();
    double getEchelleUnite(QString nom);
    bool getAfficherPoint();

private:
    QRect rect;
    double height;
    double width;
    double x0;
    double y0;
    double ymin;
    double ymax;
    double marqY;
    double centreX;
    double centreY;
    QPointF echelleX;
    QPointF echelleY;
    double pasY;
    QGraphicsEllipseItem *pointCur;
    QMap<QString,double> echelleUnite;
    bool estAfficher;
};

#endif // CONFIGSCENE_H
