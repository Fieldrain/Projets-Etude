#include "legende.h"
#include "ui_legende.h"

// classe qui herite de vue ca fonction refresh sera appeler a chaque fois que les donnees d'un model (groupes, stations,parametres )changent

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Legende::Legende(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Legende)
{
    ui->setupUi(this);
}

Legende::Legende(Stations *s, Parametres *p, Groupes *g, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Legende),
    modelStation(s),
    modelParametre(p),
    modelGroupe(g)
{
    modelStation->abonne(this);
    modelParametre->abonne(this);

    ui->setupUi(this);

    refresh();
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
Legende::~Legende()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLICS--------------------------------*/

// fonction qui permet de rafraichir les differents elements de la fenetre
void Legende::refresh(){
    init_table();
    QStandardItemModel *modelTabParametre = qobject_cast<QStandardItemModel*>(ui->tableViewParametre->model());
    QStandardItemModel *modelTabStation = qobject_cast<QStandardItemModel*>(ui->tableViewStation->model());

    // on connect le signal dataChanged des listeView a la fonction tableViewStation_dataChanged
    connect(modelTabStation, SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(tableViewStation_dataChanged(QModelIndex)));
    connect(modelTabParametre, SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(tableViewParametre_dataChanged(QModelIndex)));
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/

// fonction appele quand on double clique sur la tableViewStation (ouvre color dialog ou enregistre la valeur de la cellule)
void Legende::on_tableViewStation_clicked(const QModelIndex &index)
{
    ui->tableViewStation->clearSelection();
    // si l'item cliquer est sur la deuxieme colonne c'est une couleur on ouvre donc la color dialog sinon on enregistre la valeur de la cellule
    if(index.column()==1){
        QStandardItemModel *modelTabStation = qobject_cast<QStandardItemModel*>(ui->tableViewStation->model());
        QStandardItem *item= modelTabStation->item(index.row(),1);
        colorChange(item);

        QString nomStation = modelTabStation->item(index.row(),0)->text();
        QColor newColor = item->background().color();
        QString couleur = QString::number(newColor.red())+","+QString::number(newColor.green())+","+QString::number(newColor.blue());
        modelStation->setCouleurStation(nomStation,couleur);
    }else if(index.column()==3){
        QStandardItemModel *modelTabStation = qobject_cast<QStandardItemModel*>(ui->tableViewStation->model());
        QString nomStation = modelTabStation->item(index.row(),0)->text();

        if(modelGroupe->getListNomParent().contains(nomStation)){
            Groupe *groupe = modelGroupe->getGroupe(nomStation);
            modelGroupe->removeGroupe(groupe);
        }
        modelGroupe->removeElementFils(modelStation->getStation(nomStation));

        modelStation->removeStation(nomStation);
    }else
        currentItemData=index.data().toString();
}

// fonction appele quand on double clique sur la tableViewParametre (ouvre color dialog ou enregistre la valeur de la cellule)
void Legende::on_tableViewParametre_clicked(const QModelIndex &index)
{
    ui->tableViewParametre->clearSelection();
    // si l'item cliquer est sur la deuxieme colonne c'est une couleur on ouvre donc la color dialog sinon on enregistre la valeur de la cellule
    if(index.column()==1){
        QStandardItemModel *modelTabParametre = qobject_cast<QStandardItemModel*>(ui->tableViewParametre->model());
        QStandardItem *item= modelTabParametre->item(index.row(),1);
        colorChange(item);

        QString nomParametre = modelTabParametre->item(index.row(),0)->text();
        QColor newColor = item->background().color();
        QString couleur = QString::number(newColor.red())+","+QString::number(newColor.green())+","+QString::number(newColor.blue());
        modelParametre->setCouleurParametre(nomParametre,couleur);

    }else if(index.column()==3){
        QStandardItemModel *modelTabParametre = qobject_cast<QStandardItemModel*>(ui->tableViewParametre->model());
        QString nomParametre = modelTabParametre->item(index.row(),0)->text();

        if(modelGroupe->getListNomParent().contains(nomParametre)){
            Groupe *groupe = modelGroupe->getGroupe(nomParametre);
            modelGroupe->removeGroupe(groupe);
        }
        modelGroupe->removeElementFils(modelParametre->getParametre(nomParametre));
        modelParametre->removeParametre(nomParametre);
    }else
        currentItemData=index.data().toString();

}

//fonction appele quand les donnees de la tableView changent (change le nom du parametre, le nom de la categorie)
void Legende::tableViewStation_dataChanged(const QModelIndex & topLeft){
    if(topLeft.column()==0){
        modelStation->setNomStation(currentItemData,topLeft.data().toString());
    }
    if(topLeft.column()==2){
        QStandardItemModel *modelTabStation = qobject_cast<QStandardItemModel*>(ui->tableViewStation->model());
        QModelIndex indexStation = modelTabStation->index(topLeft.row(),0);
        modelStation->setCategorie(indexStation.data().toString(),topLeft.data().toString());
    }
}

//fonction appele quand les donnees de la tableView changent (change le nom du parametre, le nom de la categorie)
void Legende::tableViewParametre_dataChanged(const QModelIndex & topLeft){
    if(topLeft.column()==0){
        modelParametre->setNomParametre(currentItemData,topLeft.data().toString());
    }
    if(topLeft.column()==2){
        QStandardItemModel *modelTabParametre = qobject_cast<QStandardItemModel*>(ui->tableViewParametre->model());
        QModelIndex indexParametre = modelTabParametre->index(topLeft.row(),0);
        modelParametre->setCategorie(indexParametre.data().toString(),topLeft.data().toString());
    }
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/

// fonction qui permet d'initialiser les tableaux
void Legende::init_table(){

    ui->tableViewStation->verticalHeader()->setVisible(false);
    ui->tableViewStation->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableViewParametre->verticalHeader()->setVisible(false);
    ui->tableViewParametre->setSelectionMode(QAbstractItemView::SingleSelection);

    QStringList header;

    header.append("Nom");
    header.append("Code Couleur");
    header.append("Catégorie");
    header.append("Supprimer");

    init_TabParametre(header);
    init_TabStation(header);
}

// fonction qui permet d'initialiser le tableau parametre
void Legende::init_TabParametre(QStringList header){
    QList<Element*> parametres = modelParametre->getListParametre();
    QStandardItemModel *modelTabParametre = new QStandardItemModel();
    ui->tableViewParametre->setModel(modelTabParametre);

    modelTabParametre->setHorizontalHeaderLabels(header);

    foreach(Element* parametre,parametres){
        QStandardItem *itemNom = new QStandardItem(parametre->getNom());
        QString codeCouleur = parametre->getCouleur();

        QStringList rgb = codeCouleur.split(",");
        QColor couleur(rgb.at(0).toInt(),rgb.at(1).toInt(),rgb.at(2).toInt(),255);
        QBrush brush(couleur);

        QStandardItem *itemCouleur = new QStandardItem();
        itemCouleur->setBackground(brush);
        itemCouleur->setEditable(false);

        QStandardItem *itemCategorie = new QStandardItem(parametre->getCategorie());

        QStandardItem *itemSupprimer = new QStandardItem("X");
        itemSupprimer->setTextAlignment(Qt::AlignHCenter);
        itemSupprimer->setEditable(false);
        itemSupprimer->setSelectable(false);

        QList<QStandardItem*> items;
        items.append(itemNom);
        items.append(itemCouleur);
        items.append(itemCategorie);
        items.append(itemSupprimer);

        modelTabParametre->appendRow(items);
    }

}

// fonction qui permet d'initialiser le tableau station
void Legende::init_TabStation(QStringList header){
    QList<Element*> stations = modelStation->getListStation();
    QStandardItemModel *modelTabStation = new QStandardItemModel();
    ui->tableViewStation->setModel(modelTabStation);


    modelTabStation->setHorizontalHeaderLabels(header);

    foreach(Element* station,stations){
        QStandardItem *itemNom = new QStandardItem(station->getNom());
        QString codeCouleur = station->getCouleur();

        QStringList rgb = codeCouleur.split(",");
        QColor couleur(rgb.at(0).toInt(),rgb.at(1).toInt(),rgb.at(2).toInt(),255);
        QBrush brush(couleur);

        QStandardItem *itemCouleur = new QStandardItem();
        itemCouleur->setBackground(brush);
        itemCouleur->setEditable(false);

        QStandardItem *itemCategorie = new QStandardItem(station->getCategorie());

        QStandardItem *itemSupprimer = new QStandardItem("X");
        itemSupprimer->setTextAlignment(Qt::AlignHCenter);
        itemSupprimer->setEditable(false);
        itemSupprimer->setSelectable(false);

        QList<QStandardItem*> items;
        items.append(itemNom);
        items.append(itemCouleur);
        items.append(itemCategorie);
        items.append(itemSupprimer);

        modelTabStation->appendRow(items);
    }


}

// fonction qui permet de changer la couleur d'un element
void Legende::colorChange(QStandardItem *item){
    QColorDialog colorDialog;
    QBrush brush = item->background();

    QColor couleur = colorDialog.getColor(brush.color());

    if(couleur.isValid())
        brush.setColor(couleur);

    item->setBackground(brush);
}

