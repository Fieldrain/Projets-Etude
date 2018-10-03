#include "xml.h"
#include <QMessageBox>

// classe qui gere le fichier xml
// dom est la representation de QT du fichier xml

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Xml::Xml(QString e):
    emplacement(e)
{
    if(!e.isNull() && e!=""){
        dom = new QDomDocument("Config");
        QFile xml_doc(e);
        QMessageBox msgBox;

        if(!xml_doc.open(QIODevice::ReadOnly))
        {
            msgBox.setText("Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
            msgBox.exec();
        }
        dom->setContent(&xml_doc);
        xml_doc.close();
    }else
        dom =NULL;
}
/*--------------------------------DESTRUCTEURS--------------------------------*/
Xml::~Xml(){
    if(dom!=NULL)
        delete dom;
}


/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
// fonction qui permet de recuperer la informations dans le fichier xml grace a un mot cle par exemple Stations,Parametres,Groupes
QList<QDomElement> Xml::getCible(QString cible){
    QList<QDomElement> listElement;
    if(dom!=NULL){
        QDomElement dom_element = dom->documentElement();
        QDomNode noeud = dom_element.firstChild();
        while(!noeud.isNull()){

            QDomElement root = noeud.toElement();

            if(root.tagName()==cible){
                QDomNodeList child = root.childNodes();
                for(int i=0; i<child.count();i++){
                    QDomElement element = child.at(i).toElement();
                    listElement.append(element);
                }
            }
            noeud = noeud.nextSibling();
        }
    }
    return listElement;
}

// fonction qui permet de sauvegarder les informations dans le fichier xml
void Xml::saveDonnees(QList<Element *> stations, QList<Element *> parametres, QList<Groupe *> groupes, QStringList configTest){

    if(!emplacement.isNull() && emplacement!=""){
        dom->clear();

        QDomElement root = dom->createElement("Donnees");

        QDomElement stationsNode = dom->createElement("Stations");

        for(int i = 0; i<stations.count();i++){
            Element* station = stations.at(i);
            QDomElement stationNode = dom->createElement("Station");

            stationNode.setAttribute("nom",station->getNom());
            stationNode.setAttribute("couleur",station->getCouleur());
            stationNode.setAttribute("categorie",station->getCategorie());

            stationsNode.appendChild(stationNode);
        }

        root.appendChild(stationsNode);

        QDomElement parametresNode = dom->createElement("Parametres");

        for(int i = 0; i<parametres.count();i++){
            Element* parametre = parametres.at(i);
            QDomElement parametreNode = dom->createElement("Parametre");

            parametreNode.setAttribute("nom",parametre->getNom());
            parametreNode.setAttribute("couleur",parametre->getCouleur());
            parametreNode.setAttribute("categorie",parametre->getCategorie());

            parametresNode.appendChild(parametreNode);
        }

        root.appendChild(parametresNode);

        QDomElement groupesNode = dom->createElement("Groupes");

        for(int i = 0; i<groupes.count();i++){
            Groupe* groupe = groupes.at(i);

            QDomElement pereNode = dom->createElement(groupe->getPere()->getNom());

            foreach(QList<Element*> fils,groupe->getFils()){
                QDomElement groupeNode = dom->createElement("Groupe");
                QString valGroupe;

                for(int j = 0;j<fils.count();j++){
                    Element* elt = fils.at(j);

                    if(j>0)
                        valGroupe += ",";

                    valGroupe += elt->getNom();
                }

                groupeNode.appendChild(dom->createTextNode(valGroupe));
                pereNode.appendChild(groupeNode);
            }

            groupesNode.appendChild(pereNode);
        }

        root.appendChild(groupesNode);

        QDomElement parametreTestNode = dom->createElement("ParametresTest");

        foreach(QString test,configTest){
            QDomElement testNode = dom->createElement("ParametreTest");

            testNode.appendChild(dom->createTextNode(test));

            parametreTestNode.appendChild(testNode);
        }

        root.appendChild(parametreTestNode);

        dom->appendChild(root);

        QFile fichier(emplacement);
        if(!fichier.open(QIODevice::WriteOnly))
        {
            QMessageBox msgBox;
            msgBox.setText("Impossible d'écrire dans le document XML");
            msgBox.exec();
        }else{
            QTextStream stream(&fichier);

            QString donneXml = dom->toString();
            stream << donneXml;

        }
        fichier.close();
    }

}
