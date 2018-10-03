#include "configechelle.h"
#include "ui_configechelle.h"

// classe qui herite de vue mais n'est abonner a aucun modele il faut donc appeller la fonction refresh cela n'est pas automatique

/*--------------------------------CONSTRUCTEURS--------------------------------*/
ConfigEchelle::ConfigEchelle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigEchelle)
{
    ui->setupUi(this);
}

ConfigEchelle::ConfigEchelle(Scene *s, ConfigScene *c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigEchelle),
    scene(s),
    configScene(c)
{
    ui->setupUi(this);
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
ConfigEchelle::~ConfigEchelle()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLICS--------------------------------*/
void ConfigEchelle::refresh(){
    listUnite = scene->getListParametreUnite();

    init_table();
    init_comboBox();

    if(ui->tableViewEchelles->model()->rowCount()<=1){
        QString nom = ui->tableViewEchelles->model()->index(0,0).data().toString();

        configScene->setEchelleUnite(nom,0);
        scene->refresh();
    }
}

/*--------------------------------FONCTIONS PROTECTED--------------------------------*/
// surcharge l'evenement entrer qui ferme nrmalement la fenetre car c'est une QDialog
void ConfigEchelle::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Enter){
        event->accept();
    }
}

/*--------------------------------FONCTION PRIVATE SLOTS--------------------------------*/
void ConfigEchelle::on_buttonValider_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableViewEchelles->model());

    for(int i =0;i<model->rowCount();i++){
        QString nom = model->item(i,0)->text();
        double val = model->item(i,1)->text().toDouble();

        configScene->setEchelleUnite(nom,val);
    }

    scene->refresh();

    close();

}

void ConfigEchelle::on_comboBoxRef_currentIndexChanged(int index)
{
    if(index > 0){
        QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableViewEchelles->model());

        for(int i =0;i<model->rowCount();i++){

            QString nom = model->item(i,0)->text();
            QStandardItem *val = model->item(i,1);
            if(ui->comboBoxRef->itemText(index)!=nom){
                val->setEditable(true);
                val->setForeground(QBrush(QColor(0,0,0,255)));
            }
            else{
                val->setEditable(false);
                val->setForeground(QBrush(QColor(143,143,143,255)));
            }

        }
    }
}

void ConfigEchelle::on_buttonAnnuler_clicked()
{
    close();
}

/*--------------------------------FONCTION PRIVATE--------------------------------*/
// fonction qui initialise la combobox avec la liste des unites presentent dans le graph
void ConfigEchelle::init_comboBox(){
    ui->comboBoxRef->clear();

    ui->comboBoxRef->addItem("");
    ui->comboBoxRef->addItems(listUnite);

}

// fonction qui initialise le tableau qui contient les unites ainsi que leurs echelle(qui est en fait plus un decalage)
void ConfigEchelle::init_table(){
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableViewEchelles->verticalHeader()->setVisible(false);
    ui->tableViewEchelles->horizontalHeader()->setVisible(false);

    foreach(QString unite,listUnite){
        QStandardItem *item = new QStandardItem(unite);
        item->setEditable(false);
        item->setSelectable(false);

        double valEchelle = configScene->getEchelleUnite(unite);
        QStandardItem *val;
        if(valEchelle!= NULL && valEchelle!=0)
            val = new QStandardItem(QString::number(valEchelle));
        else
            val = new QStandardItem("0");
        val->setSelectable(false);
        val->setEditable(false);
        val->setForeground(QBrush(QColor(143,143,143,255)));

        QList<QStandardItem*> list;
        list.append(item);
        list.append(val);

        model->appendRow(list);
    }

    ui->tableViewEchelles->setModel(model);
}
