#include "scene.h"

// Les coordonnees y doivent etre négative car le point d'origin est placer en bas a gauche
// classe qui herite de QGraphicsScene et qui represente la scene dans laquel les graphes sont affichés
// itemGraph est une dictionnaire qui contient en cle le nom du graph composer du nom du pere suivie du nom du fils (ex : NO_TARNIER) et a comme valeur la list des items qui compose le graph
// itemGraph a egalement 3 graph qui sont les items de l'echelleX , l'echelleY, echelle

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Scene::Scene(QLineEdit *minMax,QLineEdit *nom,QDateTimeEdit *date, QLineEdit *taux, ConfigScene *c ,QGraphicsView *v,Stations *s, Parametres *p,GestionDate *da,QGraphicsScene* parent):
    QGraphicsScene(c->getRect(),parent),
    config(c),
    dateTimeEdit(date),
    tauxLineEdit(taux),
    nomLineEdit(nom),
    minMaxLineEdit(minMax),
    view(v),
    pen(QPen()),
    date(da),
    itemGraph(QMap<QString,QList<QGraphicsItem*> >()),
    modelStations(s),
    modelParametres(p)
{
    drawGraphBase();
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
Scene::~Scene(){
    foreach(QList<QGraphicsItem*> l,itemGraph.values()){
        foreach(QGraphicsItem* i,l){
            delete i;
        }
    }
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
//fonction qui permet de d'ajouter un graphe dans la scene
void Scene::ajoutGraph(Element* pere, QList<Element*> fils){
    listParametreUnite.clear();
    if(!fils.isEmpty()){

        // on ajoute a la liste des graphe a supprimer tous les graphes present (ainsi que les echelles)
        QStringList graphSuppr = itemGraph.keys();

        double Ymin = config->getYmin();
        double Ymax = config->getYmax();

        // si la scene n'a pas deja les echelles de dessine on les dessinent sinon on supprimer les echelles de la liste des graphes a supprimer
        if(!graphSuppr.contains("EchelleY") && !graphSuppr.contains("EchelleX")){
            drawEchelle(Ymin);
        }else{
            graphSuppr.removeOne("EchelleY");
            graphSuppr.removeOne("EchelleX");
        }
        graphSuppr.removeOne("Echelle");

        double echelleY = config->getEchelleY().y();
        float unite = config->getEchelleY().x();

        foreach(Element* f,fils){
            QString nomUnite = getParametreUnite(pere,f);

            if(!listParametreUnite.contains(nomUnite))
                listParametreUnite.append(nomUnite);

            // si le graphe n'est pas dans la liste des graphes a supprimer on le dessine sinon on le supprime de la liste des graphes a supprimer cela permet d'eviter de redessiner un graphes deja dessine
            if(!graphSuppr.contains(pere->getNom()+"_"+f->getNom())){

                // on recupere les donnees du graph
                QList<double> donnees = getDonne(pere,f);

                // on recupere la couleur du graph
                QPen pen = getPen(f);

                double xPred = 99999999999;
                double yPred = 99999999999;
                double xCur = config->getOrigin().x();
                double yCur;
                QList<QGraphicsItem*> listItem;
                QDateTime dateCur = date->getDateMin();
                bool donnePreValide = false;

                foreach(double donne,donnees){

                    yCur = (config->getOrigin().y()+(Ymin*echelleY)/unite) - config->getEchelleUnite(nomUnite)*echelleY;

                    if(donne!=99999999999 && donne>=Ymin && donne<=Ymax && dateCur>=date->getDateMin() && dateCur<=date->getDateMax()){
                        yCur -= ((donne*echelleY)/unite);

                        QString itemNom = pere->getNom()+"_"+f->getNom();

                        // on ajoute les items cad les points et les droites
                        addItems(xCur,yCur,xPred,yPred,listItem,pen,itemNom,donnePreValide);

                        donnePreValide = true;

                        xPred = xCur;

                        xCur = nextX(xCur);

                        yPred = yCur;
                    }else{
                        donnePreValide = false;

                        xCur = nextX(xCur);
                        // on ajoute 3fois NULL dans les liste des items du graphs car cela facilite la recuperation de donne par la suite puisque l'on aura toujours 3 items par donne
                        listItem.append(NULL);
                        listItem.append(NULL);
                        listItem.append(NULL);
                    }
                    dateCur = dateCur.addSecs(60*15);
                    // on ajoute le graph a la liste des graphes de la scene
                    itemGraph.insert(pere->getNom()+"_"+f->getNom(),listItem);
                }
            }else{
                graphSuppr.removeOne(pere->getNom()+"_"+f->getNom());
            }
        }
        // on supprime tous les graphes qui sont rester dans la liste
        foreach(QString graph,graphSuppr){
            QList<QGraphicsItem*> listItem = itemGraph.value(graph);
            removeListItem(listItem);
            itemGraph.remove(graph);
        }
    }
    config->init_echelleUnite(listParametreUnite);
}

void Scene::supprGraph(){
    foreach(QString nomGraph, itemGraph.keys()){
        QList<QGraphicsItem*> listItem = itemGraph.value(nomGraph);
        if(nomGraph!="Echelle"){
            removeListItem(listItem);
            itemGraph.remove(nomGraph);
        }
    }
}

// fonction qui permet de rafraichir la scene(supprime tous les elements de la scene)
void Scene::refresh(){
    QApplication::setOverrideCursor( Qt::WaitCursor );

    //on recupere le nom du graph dans lequel est le pointCourant et ca position dans la liste d'item
    // a faire en premier car la fonction supprime les items getPereFils()
    QString itemNom = "";
    int positionList = -1;

    if(config->getPointCur()!=NULL){
        itemNom = config->getPointCur()->data(0).toString();
        positionList = itemGraph.value(itemNom).indexOf(config->getPointCur());
    }

    QList<Element*> pereFils = getPereFils();
    Element* pere;
    QList<Element*> fils;

    if(pereFils.count()>=2){
        pere = pereFils.at(0);
        pereFils.removeAt(0);
        fils = pereFils;
    }

    setMinMax(pere,fils);
    config->init_rectScene(date);
    setSceneRect(config->getRect());

    if(itemGraph.count()>=1){

        foreach(QString nomGraph,itemGraph.keys()){
            QList<QGraphicsItem*> listItem = itemGraph.value(nomGraph);
            if(nomGraph=="EchelleX" || nomGraph=="EchelleY" || nomGraph=="Echelle"){
                removeListItem(listItem);
                itemGraph.remove(nomGraph);
            }
        }
        drawGraphBase();
    }
    actualiserGraph(pere,fils);

    // on le met le pointCourrant a nul pour la fonction changeColorItem
    // a faire en dernier car actualiserGraph() ajoute les items
    config->setPointCur(NULL);

    if(itemGraph.keys().contains(itemNom) && itemNom!="" && positionList!=-1){
        QGraphicsEllipseItem* point = qgraphicsitem_cast<QGraphicsEllipseItem*>(itemGraph.value(itemNom).at(positionList));

        changeColorItem(point);

        config->setPointCur(point);

        view->centerOn(point);
    }else{
        view->centerOn(config->getCentreX(),config->getCentreY());
    }
    QApplication::restoreOverrideCursor();
}

// fonction qui permet de savoir si la scene a au moins un graph
bool Scene::hasGraph(){
    return itemGraph.count()>3;
}

QStringList Scene::getListParametreUnite(){
    return listParametreUnite;
}

QStringList Scene::getNomGraphAfficher(){
    QStringList retour = itemGraph.keys();
    retour.removeOne("EchelleX");
    retour.removeOne("EchelleY");
    retour.removeOne("Echelle");

    return retour;
}

void Scene::hide(bool estAfficher){

    foreach(QGraphicsItem* item,this->items()){
        // on verifie que l'item est un point
        if(item!=NULL && item->type() == 4){

            //on verifie que ce ne soit pas la hitbox d'un point
            if(item->data(0).isNull())
                item->setVisible(estAfficher);
        }
    }
}

/*--------------------------------FONCTIONS PROTECTED--------------------------------*/
// surcharge de l'event clique de la souris
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    // on recupere l'item a la position du clique de la souris
    QGraphicsItem* item = itemAt(event->scenePos(),QTransform());
    QGraphicsEllipseItem* pointCur = config->getPointCur();

    // on verifie que l'item est un point
    if(item!=NULL && item->type()==4){

        // on cast l'item pour avoir accés au bonne fonction
        QGraphicsEllipseItem *point = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);
        QString nomGraph;
        int index=0;

        // on recherche a quel graphe appartient le point on recupere le nom du graph et l'index du point
        foreach(QString key, itemGraph.keys()){
            if(itemGraph.value(key).contains(point)){
                nomGraph = key;
                index = itemGraph.value(key).indexOf(point)/3;
            }
        }

        // on recupere la valeur du taux du point clique
        QString taux = traiteTaux(nomGraph,index);
        tauxLineEdit->clear();
        tauxLineEdit->insert(taux);

        nomLineEdit->clear();
        nomLineEdit->insert(nomGraph);

        // on recupere le min et le max du graph
        QStringList nomGraphList = nomGraph.split("_");
        QString minMax;

        if(modelStations->isStation(nomGraphList.at(0))){
            Station* station = static_cast<Station*>(modelStations->getStation(nomGraphList.at(0)));
            double min = station->getMin(nomGraphList.at(1));
            double max = station->getMax(nomGraphList.at(1));

            minMax = QString::number(min) + "/" + QString::number(max);

        }else{
            Station* station = static_cast<Station*>(modelStations->getStation(nomGraphList.at(1)));
            double min = station->getMin(nomGraphList.at(0));
            double max = station->getMax(nomGraphList.at(0));

            minMax = QString::number(min) + "/" + QString::number(max);
        }

        minMaxLineEdit->setText(minMax);

        // on recupere la date
        dateTimeEdit->setDateTime(date->getDateDeb().addSecs(60*15*index));

        //on change le couleur du point et la valeur du point courrant et on centre le vue sur ce point
        changeColorItem(point);

        if(pointCur == point)
            config->setPointCur(NULL);
        else
            config->setPointCur(point);

        view->centerOn(point);
    }
}

void Scene::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent){
    // on verifie que la scene existe et que l'utilisateur appuie sur ctrl
    if(wheelEvent->modifiers() == Qt::CTRL){
        QPointF echelleX = config->getEchelleX();

        // on diminue les echelles quand l'utilisateur tourne la molette vers le bas sinon on les augmentent
        if(wheelEvent->delta()<0){
            if(echelleX.y()>10){
                echelleX.setY(echelleX.y() - 10);
            }else if(echelleX.y()>3 && echelleX.y()<=10){
                echelleX.setY(echelleX.y() - 1);
            }
        }else{
            if(echelleX.y()>10)
                echelleX.setY(echelleX.y() + 10);
            else if(echelleX.y()<=10)
                echelleX.setY(echelleX.y() + 1);
        }

        if(config->getEchelleX()!=echelleX){
            config->setEchelleX(echelleX);

            // on met a jour la scene
            refresh();
        }
        wheelEvent->accept();
    }
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/
// fonction qui peermet de dessiner la base des graphes cad le quadrillage
void Scene::drawGraphBase(){
    double width = config->getWidth();
    double height = config->getHeight();
    double echelleY = config->getEchelleY().y();
    double echelleX = config->getEchelleX().y();
    double x0 = config->getOrigin().x();
    double y0 = config->getOrigin().y();

    QList<QGraphicsItem*> listItem;

    // tracage des abscisse et ordonnée
    QGraphicsLineItem *lineX = new QGraphicsLineItem(x0,y0,width,y0);
    lineX->setFlag(QGraphicsItem::ItemIsSelectable,false);

    QGraphicsLineItem *lineY = new QGraphicsLineItem(x0,y0,x0,-height);
    lineY->setFlag(QGraphicsItem::ItemIsSelectable,false);

    addItem(lineX);
    addItem(lineY);
    listItem.append(lineX);
    listItem.append(lineY);

    QPen penDash;
    penDash.setStyle(Qt::DashLine);
    penDash.setBrush(QColor(0,0,0,50));

    // tracage du quadrillage
    for(int i =-y0;i<height;i+=echelleY){

        // +5 et -5 pour ne pas avoir un point
        QGraphicsLineItem *line = new QGraphicsLineItem(x0-5,-i,x0+5,-i);
        line->setFlag(QGraphicsItem::ItemIsSelectable,false);

        QGraphicsLineItem *lineDash = new QGraphicsLineItem(x0,-i,width,-i);
        lineDash->setFlag(QGraphicsItem::ItemIsSelectable,false);
        lineDash->setPen(penDash);

        addItem(line);
        addItem(lineDash);
        listItem.append(line);
        listItem.append(lineDash);
    }

    for(int i =x0;i<width;i+=echelleX){
        // +5 et -5 pour ne pas avoir un point
        QGraphicsLineItem *line = new QGraphicsLineItem(i,y0+5,i,y0-5);
        line->setFlag(QGraphicsItem::ItemIsSelectable,false);

        QGraphicsLineItem *lineDash = new QGraphicsLineItem(i,y0,i,-height);
        lineDash->setFlag(QGraphicsItem::ItemIsSelectable,false);
        lineDash->setPen(penDash);

        addItem(line);
        addItem(lineDash);
        listItem.append(line);
        listItem.append(lineDash);
    }

    // on ajoute ces items dans la liste des graphes a tant qu'echelle
    itemGraph.insert("Echelle",listItem);
}

// fonction qui permet des dessiner les etiquettes des axes
void Scene::drawEchelle(double yMin){
    double width = config->getWidth();
    double height = config->getHeight();
    double echelleY = config->getEchelleY().y();
    double echelleX = config->getEchelleX().y();
    double x0 = config->getOrigin().x();
    double y0 = config->getOrigin().y();
    double unite = config->getEchelleY().x();
    double marqY = config->getMarqY();
    double val = yMin;

    QList<QGraphicsItem*> listItemEY;
    for(int i =-y0;i<height;i+=echelleY){
        QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem(QString::number(val));

        //-40 pour deplacer le text sur la gauche, -10 pour le centrer au niveau du trait
        text->setPos(x0-40,-i-10);

        addItem(text);
        listItemEY.append(text);

        //obliger de passer les valeurs en string sinon a certain moments ou val = marqY cela donne faux donc ne rentre pas dans le if
        if(QString::number(val) == QString::number(marqY)){
            QGraphicsLineItem *line = new QGraphicsLineItem(x0,-i,width,-i);
            addItem(line);
            listItemEY.append(line);
            marqY += config->getMarqY();
        }

        val += unite;
    }

    QList<QGraphicsItem*> listItemEX;
    for(int i =x0;i<width;i+=echelleX){
        if(echelleX>=20){
            QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem(date->getDateFromPoint(i-x0,config->getEchelleX()).toString("dd/MM/yy - hh:mm:ss"));

            // +15 pour deplacer le text vers le bas, +10 pour le centrer au niveau du trait
            text->setPos(i+15,y0+10);

            // rotation de 90 pour que les textes ne se chevauchent pas
            text->setRotation(90.0);

            addItem(text);
            listItemEX.append(text);
        }else{
            listItemEX.append(NULL);
        }

    }

    // on ajoute ces items dans la liste des graphes a tant qu'echelleX et echelleY
    itemGraph.insert("EchelleY",listItemEY);
    itemGraph.insert("EchelleX",listItemEX);
}

// fonction qui permet de recuperer le pinceau qui permet de changer la couleur du graph
QPen Scene::getPen(Element *f){
    QString codeCouleur = f->getCouleur();
    QStringList rgb = codeCouleur.split(",");
    QColor couleur(rgb.at(0).toInt(),rgb.at(1).toInt(),rgb.at(2).toInt(),255);
    return QPen(couleur);
}

// fonction qui permet d'ajouter les items du graphes a la scene
void Scene::addItems(double xCur, double yCur, double xPred, double yPred, QList<QGraphicsItem *> &listItem, QPen pen, QString itemNom, bool donnePreValide){
    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(xCur-3,yCur-3,6,6);

    // rend le point non-selectionnable
    point->setFlag(QGraphicsItem::ItemIsSelectable,false);
    point->setVisible(config->getAfficherPoint());

    QGraphicsEllipseItem *hitBoxPoint = new QGraphicsEllipseItem(xCur-8,yCur-8,16,16);
    hitBoxPoint->setPen(QPen(QColor(255,255,255,0)));
    hitBoxPoint->setData(0,itemNom);

    if(xPred!=99999999999 && yPred!=99999999999 && donnePreValide==true){
        QGraphicsLineItem *line = new QGraphicsLineItem(xPred,yPred,xCur,yCur);
        // rend le trait non-selectionnable
        line->setFlag(QGraphicsItem::ItemIsSelectable,false);
        line->setPen(pen);

        addItem(line);
        addItem(point);
        addItem(hitBoxPoint);

        listItem.append(line);
        listItem.append(hitBoxPoint);
        listItem.append(point);

    }else{
        addItem(point);
        addItem(hitBoxPoint);

        // on rajoute NULL pour avoir toujours 3 items par donne
        listItem.append(NULL);
        listItem.append(hitBoxPoint);
        listItem.append(point);

    }

}

// fonction qui permet de recuperer la prochaine valeur de X qui depend de l'unite du graphes cad si un regarde toutes les 15min ou toutes les heures ect
double Scene::nextX(double xCur){
    double newX = xCur;
    int uniteX = static_cast<int>(config->getEchelleX().x());

    switch(uniteX){
    case 0:
        newX += config->getEchelleX().y()/(15/15);
        break;
    case 1:
        newX += config->getEchelleX().y()/(60/15);
        break;
    case 2:
        newX += config->getEchelleX().y()/(12*60/15);
        break;
    case 3:
        newX += config->getEchelleX().y()/(24*60/15);
        break;
    case 4:
        newX += config->getEchelleX().y()/(7*24*60/15);
        break;

    }
    return newX;
}

// fonction qui permet de recupere la valeur du taux d'un point
QString Scene::traiteTaux(QString nomGraph,int index){
    QString pere = nomGraph.split("_").at(0);
    QString fils = nomGraph.split("_").at(1);
    QString donne;

    if(modelStations->isStation(pere)){
        donne = QString::number(static_cast<Station*>(modelStations->getStation(pere))->getDonne(fils).at(index)) +" "+ static_cast<Parametre*>(modelParametres->getParametre(fils))->getUnite();
    }else
        donne = QString::number(static_cast<Station*>(modelStations->getStation(fils))->getDonne(pere).at(index)) +" "+ static_cast<Parametre*>(modelParametres->getParametre(pere))->getUnite();

    return donne;
}

// fonction qui permet de recuperer les donnees d'un graphe rappel les donnes sont stocker uniquement dans les stations
QList<double> Scene::getDonne(Element *pere, Element* f){
    if(pere->getStatut()=="Station")
        return static_cast<Station*>(pere)->getDonne(f->getNom());
    else{
        return static_cast<Station*>(f)->getDonne(pere->getNom());
    }
}

QString Scene::getParametreUnite(Element *pere, Element *f){
    if(pere->getStatut()=="Station")
        return static_cast<Parametre*>(f)->getUnite();
    else{
        return static_cast<Parametre*>(pere)->getUnite();
    }
}

// fonction qui permet de changer la couleur d'un point
void Scene::changeColorItem(QGraphicsEllipseItem *point){
    QGraphicsEllipseItem* pointCur = config->getPointCur();

    if(pointCur!=NULL){
        point->setBrush(QColor(255,0,0,255));
        pointCur->setBrush(QColor(255,255,255,0));
    }else{
        point->setBrush(QColor(255,0,0,255));
    }

}

// fonction qui permet de supprimer de la scene tous les items d'une liste
void Scene::removeListItem(QList<QGraphicsItem *> list){
    foreach(QGraphicsItem* item,list){
        if(item!=NULL){
            removeItem(item);
        }
        delete item;
    }
}

//fonction qui permet de supprimer uniquement les graphes present puis de les rajouter
void Scene::actualiserGraph(Element* pere,QList<Element*>fils){
    if(pere!=NULL && !fils.isEmpty())
        ajoutGraph(pere,fils);
}

// fonction qui permet de recupere le pere et les fils qui sont afficher sur le graph
QList<Element*> Scene::getPereFils(){
    Element* pere;
    QList<Element*> fils;

    foreach(QString nomGraph,itemGraph.keys()){
        if(nomGraph!= "EchelleY" && nomGraph!="EchelleX" && nomGraph!="Echelle"){
            QList<QGraphicsItem*> listItem = itemGraph.value(nomGraph);
            removeListItem(listItem);

            QString nomPere = nomGraph.split("_").at(0);
            QString nomFils = nomGraph.split("_").at(1);

            if(modelStations->isStation(nomPere)){
                pere = modelStations->getStation(nomPere);
                fils.append(modelParametres->getParametre(nomFils));
            }else{
                pere = modelParametres->getParametre(nomPere);
                fils.append(modelStations->getStation(nomFils));
            }

            itemGraph.remove(nomGraph);
        }
    }

    QList<Element*> list;
    list.append(pere);
    list.append(fils);

    return list;
}

// fonction qui permet de mettre a jour le min et le max
void Scene::setMinMax(Element *pere, QList<Element*> fils){
    if(pere!=NULL && !fils.isEmpty()){
        double yMin = config->getYmin();
        double yMax = config->getYmax();

        if(pere->getStatut()=="Parametre"){
            foreach(Element* f,fils){
                QString nomUnite = static_cast<Parametre*>(pere)->getUnite();

                double min = static_cast<Station*>(f)->getMin(pere->getNom()) + config->getEchelleUnite(nomUnite);
                double max = static_cast<Station*>(f)->getMax(pere->getNom()) + config->getEchelleUnite(nomUnite);

                if(min<yMin){
                    if(min>0)
                        yMin = ceil(min);
                    else
                        yMin = floor(min);
                }
                if(max>yMax){
                    if(max>0)
                        yMax = ceil(max);
                    else
                        yMax = floor(max);
                }
            }
        }else{
            foreach(Element* f,fils){
                QString nomUnite = static_cast<Parametre*>(f)->getUnite();

                double min = static_cast<Station*>(pere)->getMin(f->getNom()) + config->getEchelleUnite(nomUnite);
                double max = static_cast<Station*>(pere)->getMax(f->getNom()) + config->getEchelleUnite(nomUnite);

                if(min<yMin){
                    if(min>0)
                        yMin = ceil(min);
                    else
                        yMin = floor(min);
                }
                if(max>yMax){
                    if(max>0)
                        yMax = ceil(max);
                    else
                        yMax = floor(max);
                }
            }
        }

        config->setYmin(yMin);
        config->setYmax(yMax);
    }
}
