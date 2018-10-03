#include "parametres.h"

// classe qui permet de gerer tous les parametres
// herite de la classe modele a chaque modification d'un groupe la classe va appeler la fonction refresh de ces vues(qui sont les interfaces)
// parametres est un dictionnaire qui a pour cle le nom du parametre et comme valeur le pointeur vers le parametre

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Parametres::Parametres(Xml *xml){
    QList<QDomElement> listElement = xml->getCible("Parametres");

    foreach(QDomElement element, listElement){
        QString nom = element.attribute("nom");
        QString couleur = element.attribute("couleur");
        QString categorie = element.attribute("categorie");
        Parametre *parametre = new Parametre(nom,couleur);
        parametre->setCategorie(categorie);
        parametres.insert(nom,parametre);
    }
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
Parametres::~Parametres(){
    foreach(Parametre* elt, parametres.values()){
        if(elt!=NULL)
            delete elt;
    }
    parametres.clear();
}


/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
QList<Element*> Parametres::getListParametre(){
    QList<Element*> listParametre;
    foreach(Element* parametre, parametres.values()){
        listParametre.append(parametre);
    }

    return listParametre;
}

// fonction qui peremt de recuperer une liste de parametres en fonction d'une liste de nom
QList<Element*> Parametres::getListParametre(QList<QString> listNom){
    QList<Element*> listParametre;
    foreach(QString nom, listNom){
        listParametre.append(parametres.value(nom));
    }

    return listParametre;
}

Element *Parametres::getParametre(QString nom){
    return parametres.value(nom);
}

QStringList Parametres::getListNomParametre(){
    return parametres.keys();
}

QStringList Parametres::getListCouleurParametre(){
    QStringList listCouleur;
    foreach(Parametre* parametre , parametres.values()){
        listCouleur.append(parametre->getCouleur());
    }
    return listCouleur;
}

QString Parametres::getCouleurParametre(QString nom){
    return parametres.value(nom)->getCouleur();
}

void Parametres::setCouleurParametre(QString nom, QString couleur){
    parametres.value(nom)->setCouleur(couleur);
    update();
}

void Parametres::setNomParametre(QString oldNom, QString newNom){
    Parametre* parametre = parametres.value(oldNom);
    parametre->setNom(newNom);
    parametres.remove(oldNom);
    parametres.insert(parametres.end(),newNom,parametre);
    update();
}

// fonction qui permet d'ajouter un parametre
void Parametres::addParametre(QString nom, QString unite){
    Parametre *parametre = new Parametre(nom,"0,0,0",unite);
    parametre->setCategorie("Nouveaux");
    parametres.insert(nom,parametre);
    update();
}

void Parametres::setCategorie(QString nom, QString categorie){
    Parametre *parametre = parametres.value(nom);
    parametre->setCategorie(categorie);
    update();
}

void Parametres::removeParametre(QString nomParametre){
    Parametre *parametre = parametres.value(nomParametre);
    parametres.remove(nomParametre);
    delete parametre;
    update();
}
