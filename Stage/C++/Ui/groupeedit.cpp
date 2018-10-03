#include "groupeedit.h"
#include "ui_groupeedit.h"

// classe qui herite de vue ca fonction refresh sera appeler a chaque fois que les donnees d'un model (groupes, stations,parametres )changent
// listCur contient les elements de la liste situer a gauche
// listEle contient les elements de la liste situer a droite
// listIni contient les elements qu'il y avait dans la liste de gauche initialement

/*--------------------------------CONSTRUCTEURS--------------------------------*/
GroupeEdit::GroupeEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupeEdit)
{
    ui->setupUi(this);
}

GroupeEdit::GroupeEdit(Stations *s, Parametres *p, Groupes *g, QWidget *parent):
    QWidget(parent),
    ui(new Ui::GroupeEdit),
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
GroupeEdit::~GroupeEdit()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLICS--------------------------------*/

// fonction appele pour ouvir la fenetre
void GroupeEdit::ouvrir(QList<Element *> l, Element *p){
    listCur = l;
    listIni = l;
    pere = p;

    // si le pere est NULL on modifie donc le nom du groupe on recupere donc l'ancien nom du groupe
    if(pere==NULL){
        oldPere = l.at(0);
    }

    refresh();
    show();
}

// fonction qui permet de rafraichir les differents elements de la fenetre
void GroupeEdit::refresh(){
    // si la liste courante n'est pas vide on initilise la fenetre
    if(!listCur.isEmpty()){
        if(listCur.at(0)->getStatut()=="Station")
            listEle = modelStation->getListStation();
        else
            listEle = modelParametre->getListParametre();
        init_table();
    }
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/

// fonction appele quand on clique sur la listView qui contient la liste courante (supprime un element de la liste)
void GroupeEdit::on_listViewCur_clicked(const QModelIndex &index)
{
    Element *item;
    QString nom = index.data().toString();
    QStringListModel *modelListCur = qobject_cast<QStringListModel*>(ui->listViewCur->model());

    // si la liste a plus d'un element on supprime l'element cliquer
    if(modelListCur->rowCount()>1){
        modelListCur->removeRow(index.row());

        if(listCur.at(0)->getStatut()=="Station")
            item = modelStation->getStation(nom);
        else
            item = modelParametre->getParametre(nom);

        listCur.removeOne(item);
    }
}

// fonction appele quand on clique sur la listView qui contient la liste de tous les elements (ajoute un element a la liste courante)
void GroupeEdit::on_listViewEle_clicked(const QModelIndex &index)
{
    Element *item;
    QStringListModel *modelListCur = qobject_cast<QStringListModel*>(ui->listViewCur->model());
    QStringList list = modelListCur->stringList();

    QString nom = index.data().toString();
    // si la liste n'a pas deja l'element on l'ajoute
    if(!list.contains(nom)){
        list.append(nom);

        if(listCur.at(0)->getStatut()=="Station")
            item = modelStation->getStation(nom);
        else
            item = modelParametre->getParametre(nom);

        listCur.append(item);

        modelListCur->setStringList(list);
    }

}

// fonction appele quand on clique sur le bouton editer (edite le groupe)
void GroupeEdit::on_buttonEdit_clicked()
{
    QStringListModel *modelListCur = qobject_cast<QStringListModel*>(ui->listViewCur->model());

    // si pere n'est pas null on met a jour son fils sinon on met a jour le pere du groupe
    if(pere!=NULL){
        modelGroupe->setFils(pere,listIni,listCur);
        listCur.clear();
        close();
    }else{
        // on verifie qu'il n'y a qu'un seul pere
        if(modelListCur->stringList().size()==1){
            QString nomPere = modelListCur->stringList().at(0);
            if(listCur.at(0)->getStatut()=="Station")
                pere = modelStation->getStation(nomPere);
            else
                pere = modelParametre->getParametre(nomPere);

            if(oldPere!=pere)
                modelGroupe->setPere(oldPere,pere);
            listCur.clear();
            close();
        }else{
            QMessageBox msg;
            msg.setWindowTitle("Erreur");
            msg.setText("Vous devez avoir uniquement un nom.");
            msg.exec();
        }
    }
}

void GroupeEdit::on_buttonAnnuler_clicked()
{
    listCur.clear();
    close();
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/

// fonction qui permet d'initialiser les listView
void GroupeEdit::init_table(){
    QStringListModel *modelListCur = new QStringListModel();
    QStringListModel *modelListEle = new QStringListModel();

    ui->listViewCur->setModel(modelListCur);
    ui->listViewEle->setModel(modelListEle);

    ui->listViewCur->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listViewEle->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList nomCur;
    foreach(Element* elt,listCur){
        nomCur.append(elt->getNom());
    }
    modelListCur->setStringList(nomCur);

    QStringList nomEle;
    foreach(Element* elt,listEle){
        nomEle.append(elt->getNom());
    }
    modelListEle->setStringList(nomEle);
}




