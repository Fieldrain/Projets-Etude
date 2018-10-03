#include "groupe.h"

// classe qui represente un groupe avec un pere qui est une station ou un parametre et plusieurs fils qui sont une liste de stations ou des parametres
// fils est une liste qui contient une liste d'elements (stations ou parametres)

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Groupe::Groupe()
{
}

Groupe::Groupe(Element *p, QList<QList<Element*> > f):
    pere(p),
    fils(f)
{
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
Groupe::~Groupe(){
    foreach(QList<Element*> l,fils){
        l.clear();
    }
    fils.clear();
}

/*--------------------------------FONCTIONS PUBLICS--------------------------------*/
Element* Groupe::getPere(){
    return pere;
}

QList<QList<Element*> > Groupe::getFils(){
    return fils;
}

void Groupe::setPere(Element *p){
    pere = p;
}

void Groupe::setFils(QList<Element*> f, int index){
    fils.replace(index, f);
}

void Groupe::setFils(QList<QList<Element*> > f){
    fils = f;
}

void Groupe::addFils(QList<Element*> f){
    fils.append(f);
}

void Groupe::removeFils(int index){
    fils.removeAt(index);
}

void Groupe::removeElementFils(Element *element){
    QList<QList<Element*> > newFils;

    foreach(QList<Element*> listFils,fils){
        QList<Element*> newListFils;

        for(int i = 0;i<listFils.count();i++){
            Element *elt = listFils.at(i);

            if(elt!=element)
                newListFils.append(elt);
        }
        newFils.append(newListFils);
    }

    fils = newFils;
}

/*--------------------------------FONCTIONS OPERATEUR--------------------------------*/
bool Groupe::operator ==(Groupe *g){
    if(g->getPere()->getNom()==this->getPere()->getNom())
        return true;
    else
        return false;
}


