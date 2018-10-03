#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QMap>
#include <QScrollBar>
#include <QApplication>

#include "gestiondate.h"
#include "configscene.h"
#include "stations.h"
#include "parametres.h"

class Scene : public QGraphicsScene
{
public:
    Scene(QLineEdit *minMax,QLineEdit *nom,QDateTimeEdit *date, QLineEdit *taux, ConfigScene *c ,QGraphicsView *v,Stations *s, Parametres *p,GestionDate* da,QGraphicsScene* parent=0);
    ~Scene();

    void ajoutGraph(Element *pere, QList<Element*> fils);
    bool hasGraph();
    void refresh();
    void supprGraph();
    QStringList getListParametreUnite();
    QStringList getNomGraphAfficher();
    void hide(bool estAfficher);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void wheelEvent(QGraphicsSceneWheelEvent * wheelEvent);

private:
    ConfigScene *config;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *tauxLineEdit;
    QLineEdit *nomLineEdit;
    QLineEdit *minMaxLineEdit;
    QGraphicsView *view;
    QPen pen;
    GestionDate* date;
    QMap<QString,QList<QGraphicsItem*> > itemGraph;
    Stations *modelStations;
    Parametres *modelParametres;
    QStringList listParametreUnite;

    void drawGraphBase();
    void drawEchelle(double yMin);

    QPen getPen(Element* f);
    void addItems(double xCur, double yCur, double xPred, double yPred, QList<QGraphicsItem*> &listItem, QPen pen, QString itemNom, bool donnePreValide);
    double nextX(double xCur);

    QString traiteTaux(QString nomGraph, int index);
    QList<double> getDonne(Element* pere,Element* f);
    QString getParametreUnite(Element* pere,Element* f);

    void changeColorItem(QGraphicsEllipseItem *point);

    void removeListItem(QList<QGraphicsItem*> list);

    void actualiserGraph(Element *pere, QList<Element *> fils);

    QList<Element*> getPereFils();

    void setMinMax(Element* pere,QList<Element*> fils);
};

#endif // SCENE_H
