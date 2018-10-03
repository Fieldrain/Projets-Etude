#include "configstationparametre.h"
#include "ui_configstationparametre.h"

// classe qui herite de vue ca fonction refresh sera appeler a chaque fois que les donnees d'un model (groupes, stations,parametres )changent

/*--------------------------------CONSTRUCTEURS--------------------------------*/
ConfigStationParametre::ConfigStationParametre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigStationParametre)
{
    ui->setupUi(this);
}

ConfigStationParametre::ConfigStationParametre(Stations *s, Parametres *p, QWidget *parent):
    QDialog(parent),
    ui(new Ui::ConfigStationParametre),
    modelParametres(p),
    modelStations(s)
{
    ui->setupUi(this);
    modelParametres->abonne(this);
    modelStations->abonne(this);
    refresh();
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
ConfigStationParametre::~ConfigStationParametre()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
void ConfigStationParametre::refresh(){
    ui->lineEditNom->clear();
    init_listView();
    init_comboBox();
}

/*--------------------------------FONCTIONS PROTECTED--------------------------------*/
// surcharge l'evenement entrer qui ferme nrmalement la fenetre car c'est une QDialog
void ConfigStationParametre::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Enter){
        event->accept();
    }
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/
void ConfigStationParametre::on_listViewNouveaux_clicked(const QModelIndex &index)
{

    QString nom = index.data().toString();

    ui->lineEditNom->clear();
    ui->lineEditNom->insert(nom);

}

void ConfigStationParametre::on_buttonValiderCategorie_clicked()
{
    if(!ui->lineEditNom->text().isEmpty()){
        QString nom = ui->lineEditNom->text();
        QString categorie = ui->comboBoxCategorie->currentText();
            if(modelStations->isStation(nom)){
                modelStations->setCategorie(nom,categorie);
            }else{
                modelParametres->setCategorie(nom,categorie);
            }

        ui->listViewNouveaux->setCurrentIndex(ui->listViewNouveaux->indexAt(QPoint(0,0)));

        ui->lineEditNom->insert(ui->listViewNouveaux->currentIndex().data().toString());

        ui->comboBoxCategorie->setCurrentText(categorie);
    }
}

void ConfigStationParametre::on_lineEditNewCategorie_editingFinished()
{
    QString nom = ui->lineEditNewCategorie->text();

    if(!nom.isNull() && ui->comboBoxCategorie->findText(nom)==-1)
        ui->comboBoxCategorie->addItem(nom);
}

void ConfigStationParametre::on_buttonFin_clicked()
{
    QStringListModel *modelList = qobject_cast<QStringListModel*>(ui->listViewNouveaux->model());
    QStringList list = modelList->stringList();

    if(list.isEmpty()){
        close();
    }
    else{
        QMessageBox msg;
        msg.setWindowTitle("Erreur");
        msg.setText("Tous les nouveaux éléments doivent être validés");
        msg.exec();
    }
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/
// fonction qui initialise la listeView avec les nouveaux parametres/stations
void ConfigStationParametre::init_listView(){
    QStringListModel *modelListView = new QStringListModel();

    ui->listViewNouveaux->setModel(modelListView);

    ui->listViewNouveaux->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList list;

    foreach(Element* station,modelStations->getListStation()){
        if(station->getCategorie()=="Nouveaux")
            list.append(station->getNom());
    }

    foreach(Element* parametre,modelParametres->getListParametre()){
        if(parametre->getCategorie()=="Nouveaux")
            list.append(parametre->getNom());
    }

    modelListView->setStringList(list);
}

// fonction qui initialise le comboBox avec la liste des categories existante
void ConfigStationParametre::init_comboBox(){
    QStringList list;

    foreach(Element* station,modelStations->getListStation()){
        if(!list.contains(station->getCategorie()) && station->getCategorie()!="Nouveaux")
            list.append(station->getCategorie());
    }

    foreach(Element* parametre,modelParametres->getListParametre()){
        if(!list.contains(parametre->getCategorie()) && parametre->getCategorie()!="Nouveaux")
            list.append(parametre->getCategorie());
    }

    ui->comboBoxCategorie->clear();
    ui->comboBoxCategorie->addItems(list);
}
