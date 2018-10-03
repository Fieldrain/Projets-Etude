#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QMap>
#include "xml.h"
#include "parametre.h"
#include "modele.h"

class Parametres : public Modele
{
public:
    Parametres(Xml *xml);
    ~Parametres();

    QList<Element*> getListParametre();
    QList<Element *> getListParametre(QList<QString> listNom);
    Element* getParametre(QString nom);
    QStringList getListNomParametre();
    QStringList getListCouleurParametre();
    QString getCouleurParametre(QString nom);
    void setCouleurParametre(QString nom, QString couleur);
    void setNomParametre(QString oldNom , QString newNom);
    void addParametre(QString nom, QString unite);
    void setCategorie(QString nom, QString categorie);
    void removeParametre(QString nomParametre);

private:
    QMap<QString, Parametre*> parametres;

};

#endif // PARAMETRES_H
