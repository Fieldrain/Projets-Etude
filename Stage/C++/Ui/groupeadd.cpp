#include "groupeadd.h"
#include "ui_groupeadd.h"

// classe qui herite de vue ca fonction refresh sera appeler a chaque fois que les donnees d'un model (groupes, stations,parametres )changent
// list contient les elements qui sont dans la zone groupe

/*--------------------------------CONSTRUCTEURS--------------------------------*/
GroupeAdd::GroupeAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupeAdd)
{
    ui->setupUi(this);
}

GroupeAdd::GroupeAdd(Stations *s, Parametres *p, Groupes *g, QWidget *parent):
    QWidget(parent),
    ui(new Ui::GroupeAdd),
    modelStation(s),
    modelParametre(p),
    modelGroupe(g)
{
    modelStation->abonne(this);
    modelGroupe->abonne(this);
    modelParametre->abonne(this);

    ui->setupUi(this);

    refresh();
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
GroupeAdd::~GroupeAdd()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/

// fonction appele pour ouvir la fenetre
void GroupeAdd::ouvrir(QList<Element *> l, Element *p){
    // on initialise le nom du groupe et le groupe si besoin
    if(!l.isEmpty() && p!=NULL){
        list = l;
        pere = p;
    }
    refresh();
    show();
}

// fonction qui permet de rafraichir les differents elements de la fenetre
void GroupeAdd::refresh(){
    init_listView();
    init_element();
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/

// fonction appele quand la checkBox du nom du groupe change d'etat suite a un clique de l'utilisateur
void GroupeAdd::on_checkBoxNom_stateChanged(int arg1)
{
    // on bloque la validation si le nom du groupe est vide
    if(ui->lineEditNom->text().isEmpty())
        ui->checkBoxNom->setCheckState(Qt::Unchecked);
    else if(arg1==2){ // si la checkbox est valide on debloque la listViewGroupe et la checkbox groupe
        ui->listViewGroupe->setEnabled(true);
        ui->checkBoxGroupe->setEnabled(true);

        // on bloque la liste qui est du me type que le nom de la station
        if(modelStation->isStation(ui->lineEditNom->text()))
            ui->listViewStations->setEnabled(false);
        else
            ui->listViewParametres->setEnabled(false);

    }else{
        ui->listViewGroupe->setEnabled(false);
        ui->checkBoxGroupe->setCheckState(Qt::Unchecked);
        ui->checkBoxGroupe->setEnabled(false);

        ui->listViewStations->setEnabled(true);
        ui->listViewParametres->setEnabled(true);
    }
}

// fonction appele quand la checkBox du groupe change d'etat suite a un clique de l'utilisateur
void GroupeAdd::on_checkBoxGroupe_stateChanged(int arg1)
{
    QStringListModel *modelList = qobject_cast<QStringListModel*>(ui->listViewGroupe->model());
    QStringList listElement = modelList->stringList();

    // si la checkbox est valide et que le groupe a plus d'un element on bloque la derniere listView sinon on bloque la validation du groupe
    if(arg1==2){

        if(listElement.count()>0){

            if(modelStation->isStation(listElement.at(0)))
                ui->listViewStations->setEnabled(false);
            else
                ui->listViewParametres->setEnabled(false);

        }else
            ui->checkBoxGroupe->setCheckState(Qt::Unchecked);

    }else{
    // si la checkbox n'est pas valide et que le groupe a plus d'un element on debloque la derniere listView sinon on change l'etat de la checkBox
        if(listElement.count()>0){

            if(modelStation->isStation(listElement.at(0)))
                ui->listViewStations->setEnabled(true);
            else
                ui->listViewParametres->setEnabled(true);

        }else
            ui->checkBoxGroupe->setCheckState(Qt::Unchecked);
    }
}

// fonction appele quand on clique sur la listView du groupe (supprime un element du groupe)
void GroupeAdd::on_listViewGroupe_clicked(const QModelIndex &index)
{
    QStringListModel *modelList = qobject_cast<QStringListModel*>(ui->listViewGroupe->model());

    Element* eltSuppr;
    QString nomElt = modelList->index(index.row()).data().toString();

    if (modelStation->isStation(nomElt)){
        eltSuppr = modelStation->getStation(nomElt);
    }else
        eltSuppr = modelParametre->getParametre(nomElt);

    list.removeOne(eltSuppr);

    modelList->removeRow(index.row());

    // si le nombre d'items du groupe est egale a 0 on reactive la listeView et on change l'etat de la checkBox
    if(modelList->rowCount()==0){

        if(pere->getStatut()=="Station")
            ui->listViewParametres->setEnabled(true);
        else
            ui->listViewStations->setEnabled(true);

        ui->checkBoxGroupe->setCheckState(Qt::Unchecked);
    }
}

// fonction appele quand on clique sur le bouton creer
void GroupeAdd::on_buttonCreer_clicked()
{
    if(ui->checkBoxGroupe->isChecked() && ui->checkBoxNom->isChecked()){
        modelGroupe->addGroupe(pere,list);
        pere =NULL;
        list.clear();
        close();
    }else{
        QMessageBox msg;
        msg.setWindowTitle("Erreur");
        msg.setText("Vous devez valider le nom et le groupe.");
        msg.exec();
    }
}

// fonction appele quand on clique sur la listeView station ou parametre
void GroupeAdd::listViewSelections_clicked(const QModelIndex &index){
    QStringListModel *modelList = qobject_cast<QStringListModel*>(ui->listViewGroupe->model());
    QStringList listElement = modelList->stringList();

    QString nom = index.data().toString();

    // si le nom du groupe n'est pas valider on ajoute l'item cliquer en tant que nom du groupe sinon en tant qu'element du groupe
    if(!ui->checkBoxNom->isChecked()){
        ui->lineEditNom->clear();
        ui->lineEditNom->insert(nom);

        if(modelStation->isStation(nom))
            pere = modelStation->getStation(nom);
        else
            pere = modelParametre->getParametre(nom);

        // si on as des elements dans le groupe et qu'ils sont du meme type que le nom du groupe on les suppriment
        if(listElement.count()> 0){
            if((pere->getStatut()=="Station" && modelStation->isStation(listElement.at(0)))||
                (pere->getStatut()=="Parametre" && !modelStation->isStation(listElement.at(0)))){

                QStringList newSList;
                modelList->setStringList(newSList);

                QList<Element*> newList;
                list = newList;
            }
        }
    }else{
        if(!listElement.contains(nom)){
            listElement.append(nom);
            Element *item;

            if(modelStation->isStation(nom))
                item = modelStation->getStation(nom);
            else
                item = modelParametre->getParametre(nom);

            list.append(item);
            modelList->setStringList(listElement);
        }
    }
}

void GroupeAdd::on_buttonAnnuler_clicked()
{
    pere =NULL;
    list.clear();
    close();
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/

//fonction qui permet d'initialiser les listView
void GroupeAdd::init_listView(){
    QList<Element*> stations = modelStation->getListStation();
    QList<Element*> parametres = modelParametre->getListParametre();

    QStringListModel *modelListStation = new QStringListModel();
    QStringListModel *modelListParametre = new QStringListModel();
    QStringListModel *modelList = new QStringListModel();

    ui->listViewGroupe->setModel(modelList);
    ui->listViewStations->setModel(modelListStation);
    ui->listViewParametres->setModel(modelListParametre);

    ui->listViewGroupe->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listViewParametres->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listViewStations->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->listViewGroupe->setSelectionMode(QAbstractItemView::NoSelection);
    ui->listViewParametres->setSelectionMode(QAbstractItemView::NoSelection);
    ui->listViewStations->setSelectionMode(QAbstractItemView::NoSelection);

    // on connect le signal clicked des listeView a la fonction listViewSelections_clicked
    connect(ui->listViewParametres,SIGNAL(clicked(QModelIndex)),this,SLOT(listViewSelections_clicked(QModelIndex)));
    connect(ui->listViewStations,SIGNAL(clicked(QModelIndex)),this,SLOT(listViewSelections_clicked(QModelIndex)));

    QStringList listStation;
    foreach(Element* station, stations){
        listStation.append(station->getNom());
    }
    modelListStation->setStringList(listStation);

    QStringList listParametre;
    foreach(Element* parametre, parametres){
        listParametre.append(parametre->getNom());
    }
    modelListParametre->setStringList(listParametre);

    if(!list.isEmpty() && pere!=NULL){
        QStringList listElement;
        foreach(Element* elt, list){
            listElement.append(elt->getNom());
        }
        modelList->setStringList(listElement);

        ui->lineEditNom->clear();
        ui->lineEditNom->insert(pere->getNom());
    }
}

// fonction qui permet d'initialiser les statuts des elements de la fenetre
void GroupeAdd::init_element(){
    ui->checkBoxGroupe->setCheckState(Qt::Unchecked);
    ui->checkBoxNom->setCheckState(Qt::Unchecked);
    ui->listViewParametres->setEnabled(true);
    ui->listViewStations->setEnabled(true);

    if(!ui->checkBoxNom->isChecked()){
        ui->listViewGroupe->setEnabled(false);
        ui->checkBoxGroupe->setEnabled(false);
    }

}
