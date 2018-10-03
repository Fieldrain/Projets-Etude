#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

class Element
{

private :
    QString nom;
    QString couleur;
    QString statut;
    QString categorie;
    int nombreValeur;
    int nombreValeurAttendu;

public:
    Element();
    Element(QString n, QString c, QString s);

    QString getStatut();
    QString getNom();
    QString getCouleur();
    QString getCategorie();
    int getNbValeur();
    int getNbValeurAttendu();

    void setStatut(QString s);
    void setNom(QString n);
    void setCouleur(QString c);
    void setCategorie(QString c);
    void addNbValeur(int v);
    void addNbValeurAttendu(int v);

    bool operator ==(Element e);
};

#endif // ELEMENT_H
