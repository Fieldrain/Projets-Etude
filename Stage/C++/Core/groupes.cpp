#include "groupes.h"

// classe qui permet de gerer tous les groupes
// herite de la classe modele a chaque modification d'un groupe la classe va appeler la fonction refresh de ces vues(qui sont les interfaces)
// groupes contient la liste de tous les groupes

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Groupes::Groupes()
{
}

Groupes::Groupes(QList<Element *> stations, QList<Element *> parametres, Xml *xml){
    QList<QDomElement> listElement= xml->getCible("Groupes");
    Element *pere;
    QList<QList<Element*> > fils;

    foreach(QDomElement dom_element, listElement){
        if(estDans(dom_element.tagName(),stations)){
            pere = rechercheElement(dom_element.tagName(),stations);
            fils = rechercheFils(dom_element,parametres);
        }else{
            pere = rechercheElement(dom_element.tagName(),parametres);
            fils = rechercheFils(dom_element,stations);
        }

        groupes.append(new Groupe(pere,fils));
    }
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
Groupes::~Groupes(){
    foreach(Groupe* g,groupes){
        delete g;
    }
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
// fonction qui permet de recuperer la liste des noms de tous les peres
QList<QString> Groupes::getListNomParent(){
    QList<QString> listeParent;

    foreach(Groupe *groupe, groupes){
        listeParent.append(groupe->getPere()->getNom());
    }

    return listeParent;
}

// fonction qui permet de recuperer un groupe grace au nom du pere
Groupe* Groupes::getGroupe(QString nomPere){
    Groupe *groupe =NULL;

    foreach(Groupe *g, groupes){
        if(g->getPere()->getNom()==nomPere)
            groupe = g;
    }

    return groupe;
}

// fonction qui permet de recuperer la liste des nom des fils d'un groupe
QStringList Groupes::getNomFils(Groupe* groupe){
    QStringList listNomFils;
    QList<QList<Element*> > fils = groupe->getFils();

    foreach(QList<Element*> f,fils){
        QString label = "";

        foreach(Element *e, f){

            if(label.size()>0)
                label += ",";

            label += e->getNom();
        }

        listNomFils.append(label);
    }

    return listNomFils;
}

// fonction qui permet de changer le fils d'un groupe
void Groupes::setFils(Element *p, QList<Element*> oldFils, QList<Element*> newFils){
    foreach(Groupe *groupe, groupes){
        if(groupe->getPere() == p){
            int index = groupe->getFils().indexOf(oldFils);
            groupe->setFils(newFils,index);
        }
    }

    this->update();
}

// fonction qui permet de changer le pere d'un groupe
void Groupes::setPere(Element *oldPere, Element *newPere){

    QList<Element*> listParent;
    foreach(Groupe *groupe, groupes){
        listParent.append(groupe->getPere());
    }

    // si le nouveau pere existe dans la liste des peres si oui on ajoute les fils de l'ancien pere au nouveau pere
    if(listParent.contains(newPere)){
        Groupe *nG = this->getGroupe(newPere->getNom());
        Groupe *oG = this->getGroupe(oldPere->getNom());
        QList<QList<Element*> > fils = oG->getFils();

        foreach(QList<Element*> f, fils){
            nG->addFils(f);
        }

        this->removeGroupe(oG);
    }else{

        foreach(Groupe *groupe, groupes){
            if(groupe->getPere() == oldPere)
                groupe->setPere(newPere);
        }
    }

    this->update();
}

// fonction qui permet de supprimer un fils
void Groupes::removeFils(Element *pere, QList<Element*> fils){
    QList<Groupe*> delGroupe;

    foreach(Groupe *groupe , groupes){
        if(groupe->getPere()== pere){
            int index = groupe->getFils().indexOf(fils);
            groupe->removeFils(index);
        }
        // si le groupe n'a plus de fils on l'ajoute a une liste qui supprimera les groupes contenu dedans
        if(groupe->getFils().count()==0)
            delGroupe.append(groupe);
    }

    foreach (Groupe *groupe, delGroupe) {
        this->removeGroupe(groupe);
    }

    this->update();
}

// fonction qui supprime un groupe
void Groupes::removeGroupe(Groupe *g){
    foreach(Groupe *groupe, groupes){
        if(groupe == g)
            groupes.removeOne(groupe);
    }

    this->update();
}

// fonction qui ajoute un grouoe
void Groupes::addGroupe(Element *newPere, QList<Element*> newFils){
    bool ajout =false;
    foreach(Groupe *groupe, groupes){

        // si le groupe existe deja on l'on ajoute le nouveau fils
        if(groupe->getPere()== newPere){
            if(!groupe->getFils().contains(newFils)){
                groupe->addFils(newFils);
                ajout = true;
            }
        }
    }
    if(!ajout){
        QList<QList<Element*> > list;
        list.append(newFils);
        Groupe *g =  new Groupe(newPere,list);
        groupes.append(g);
    }

    this->update();
}

// fonction qui permet de recuperer tous les groupes
QList<Groupe*> Groupes::getListGroupe(){
    return groupes;
}

// fonction qui permet de supprimer un element dans tous les groupes
void Groupes::removeElementFils(Element *element){
    foreach(Groupe *groupe,groupes){
        groupe->removeElementFils(element);
    }
    this->update();
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/
// fonction qui permet de savoir si un element est dans une liste d'elements
bool Groupes::estDans(QString nom, QList<Element *> list){
    foreach(Element* element,list){
        if(nom==element->getNom())
            return true;
    }
    return false;
}

// fonction qui permet de rechercher un element dans une liste d'elements
Element* Groupes::rechercheElement(QString nom, QList<Element *> list){
    foreach(Element* element,list){
        if(nom==element->getNom())
            return element;
    }
    return NULL;
}

// fonction qui permet de recuperer les fils a partir des informations du fichier xml
QList<QList<Element*> > Groupes::rechercheFils(QDomElement pere, QList<Element *> list){
    QDomNodeList child = pere.childNodes();
    QList<QList<Element*> > fils;

    for(int i =0 ; i<child.count();i++){
        // on recupere l'element XML qui correspond a un groupe
        QDomElement element = child.at(i).toElement();
        //on recupere la liste des fils
        QStringList listFils = element.text().split(",");
        QList<Element*> listElementFils;

        foreach(QString nomFils,listFils){
            Element *eltFils = rechercheElement(nomFils,list);
            listElementFils.append(eltFils);
        }
        fils.append(listElementFils);
    }

    return fils;
}
