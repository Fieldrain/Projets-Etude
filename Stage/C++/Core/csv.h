#ifndef CSV_H
#define CSV_H

#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QPair>
#include <QDateTime>
#include <QMap>
#include <QProgressBar>
#include <QStandardItem>

#include "Ui/configtest.h"
#include "Ui/configstationparametre.h"

#include "stations.h"
#include "parametres.h"

class Csv
{
public:
    Csv(QString nomFile, Stations *stations, Parametres *parametres, QProgressBar *progressBar, ConfigTest *configuration, QList<QStandardItem *> *dI);
    ~Csv();

    QDateTime getDateDeb();
    QDateTime getDateFin();

private:
    int tailleFile;
    Stations *modelStations;
    Parametres *modelParametres;
    QDateTime dateDeb;
    QDateTime dateFin;
    QList<QPair<QString,QString>* > entete;
    QList<QPair<QString,QString>* > unite;
    QList<QStandardItem *> *donneInvalide;
    QStringList configTest;

    void getEntete(QTextStream *file);
    void getUnite(QTextStream *file);
    bool addStations(QProgressBar *progressBar);
    bool addParametres(QProgressBar *progressBar);
    void addDonne(QTextStream *file,QProgressBar *progressBar);
    double traitementDonne(QString nomParametre, Element* station , QString donneCur , QStringList donnees , QDateTime date);
    void addInfo(QDateTime date, Element* station, QString com,QString type);
    void addInfo(QString nomParametre, QString maxMin , QString com);
    void addInfo(double val1 , double val2, QString com);
    QPair<QString, QString> *findPair(QString nomParametre,QString nomStation);
    void setMinMax(double valeur,QMap<QString,QStringList > *minima, QMap<QString,QStringList > *maxima, QString nomParametre, Element* station,QDateTime dateCur);
    bool testIntervalle(QString infoIntervalle, QString com, Element *station, QDateTime dateCur);
};

#endif // CSV_H
