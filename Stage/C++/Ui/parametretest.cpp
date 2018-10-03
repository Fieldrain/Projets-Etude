#include "parametretest.h"
#include "ui_parametretest.h"

// classe qui herite de vue ca fonction refresh sera appeler a chaque fois que les donnees d'un model (groupes, stations,parametres )changent

/*--------------------------------CONSTRUCTEURS--------------------------------*/
ParametreTest::ParametreTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParametreTest)
{
    ui->setupUi(this);
}

ParametreTest::ParametreTest( Parametres *p, Xml *xml, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ParametreTest),
    modelParametre(p)
{
    modelParametre->abonne(this);

    ui->setupUi(this);

    init_listView_Xml(xml);

    refresh();
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
ParametreTest::~ParametreTest()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
void ParametreTest::refresh(){
    newParametre.clear();


    ui->doubleSpinBoxValeur->setValue(0);
    ui->doubleSpinBoxValeur->setEnabled(false);

    ui->dateTimeEdit->setEnabled(false);
    ui->dateTimeEditIntervalle->setEnabled(false);

    ui->comboBoxParametre->setEnabled(false);

    ui->comboBoxOperation->setCurrentIndex(0);

    if(ui->radioButtonDate->isChecked()){
        ui->radioButtonDate->setCheckable(true);
        ui->radioButtonDate->setAutoExclusive(false);
        ui->radioButtonDate->setChecked(false);
        ui->radioButtonDate->setAutoExclusive(true);
    }
    else if(ui->radioButtonValeur->isChecked()){
        ui->radioButtonValeur->setCheckable(true);
        ui->radioButtonValeur->setAutoExclusive(false);
        ui->radioButtonValeur->setChecked(false);
        ui->radioButtonValeur->setAutoExclusive(true);
    }
    else{
        ui->radioButtonParametre->setCheckable(true);
        ui->radioButtonParametre->setAutoExclusive(false);
        ui->radioButtonParametre->setChecked(false);
        ui->radioButtonParametre->setAutoExclusive(true);
    }

    ui->buttonAjouterParametre->setEnabled(false);
}

QStringList ParametreTest::getParametreTest(){
    return parametreTest;
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/
void ParametreTest::on_buttonAjouterParametre_clicked()
{
    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewParametreTest->model());

    QStringList parametres = model->stringList();

    QString parametre = newParametre.at(0) + "|" + newParametre.at(1) + "|" + newParametre.at(2) + "|" + newParametre.at(3);
    if(newParametre.at(2) =="Date")
        parametre += "|" + newParametre.at(4);

    if(newParametre.at(0) != newParametre.at(3) && !newParametre.at(3).isEmpty() && ((newParametre.at(0) != "Tous" && newParametre.at(3) != "Tous" )|| !ui->radioButtonParametre->isChecked())){
        parametres.append(parametre);

        model->setStringList(parametres);

        refresh();

    }else{
        QMessageBox msg;
        msg.setWindowTitle("Erreur");
        msg.setText("Impossible de comparer "+newParametre.at(0)+" avec "+newParametre.at(3));
        msg.exec();
    }


}

void ParametreTest::on_buttonModifierParametre_clicked()
{
    ui->buttonAjouterParametre->setEnabled(false);

    int index = ui->listViewParametreTest->selectionModel()->selectedIndexes().at(0).row();

    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewParametreTest->model());

    QStringList parametres = model->stringList();

    QString parametre = newParametre.at(0) + "|" + newParametre.at(1) + "|" + newParametre.at(2) + "|" + newParametre.at(3);
    if(newParametre.at(2) =="Date")
        parametre += "|" + newParametre.at(4);

    if(newParametre.at(0) != newParametre.at(3) && !newParametre.at(3).isEmpty() && ((newParametre.at(0) != "Tous" && newParametre.at(3)!="Tous" )|| ui->radioButtonParametre->isChecked())){

        parametres.replace(index,parametre);

        model->setStringList(parametres);

        refresh();
    }else{
        QMessageBox msg;
        msg.setWindowTitle("Erreur");
        msg.setText("Impossible de comparer "+newParametre.at(0)+" avec "+newParametre.at(3));
        msg.exec();
    }
}

void ParametreTest::on_radioButtonParametre_clicked(bool checked)
{
    if (checked){
        newParametre.insert(0,ui->comboBoxFirstOperande->currentText());
        newParametre.insert(1,ui->comboBoxOperation->currentText());

        ui->comboBoxParametre->setEnabled(true);
        ui->doubleSpinBoxValeur->setEnabled(false);
        ui->dateTimeEdit->setEnabled(false);
        ui->dateTimeEditIntervalle->setEnabled(false);
        if(ui->listViewParametreTest->selectionModel()->selectedIndexes().count()==0)
            ui->buttonAjouterParametre->setEnabled(true);
        setParametre(4,ui->comboBoxParametre->currentText(),"Parametre");
    }

}

void ParametreTest::on_radioButtonValeur_clicked(bool checked)
{
    if (checked){
        newParametre.insert(0,ui->comboBoxFirstOperande->currentText());
        newParametre.insert(1,ui->comboBoxOperation->currentText());

        ui->comboBoxParametre->setEnabled(false);
        ui->doubleSpinBoxValeur->setEnabled(true);
        ui->dateTimeEdit->setEnabled(false);
        ui->dateTimeEditIntervalle->setEnabled(false);
        if(ui->listViewParametreTest->selectionModel()->selectedIndexes().count()==0)
            ui->buttonAjouterParametre->setEnabled(true);

        setParametre(4,QString::number(ui->doubleSpinBoxValeur->value()),"Valeur");
    }
}

void ParametreTest::on_radioButtonDate_clicked(bool checked)
{
    if (checked){
        newParametre.insert(0,ui->comboBoxFirstOperande->currentText());
        newParametre.insert(1,ui->comboBoxOperation->currentText());

        ui->comboBoxParametre->setEnabled(false);
        ui->doubleSpinBoxValeur->setEnabled(false);
        ui->dateTimeEdit->setEnabled(true);
        ui->dateTimeEditIntervalle->setEnabled(true);
        if(ui->listViewParametreTest->selectionModel()->selectedIndexes().count()==0)
            ui->buttonAjouterParametre->setEnabled(true);

        setParametre(4,ui->dateTimeEdit->dateTime().toString(),"Date");
    }
}

void ParametreTest::on_comboBoxOperation_currentIndexChanged(const QString &arg1)
{
    if(newParametre.count()>=2)
        newParametre.replace(1,arg1);
    else
        newParametre.insert(1,arg1);

    if(arg1 =="Min" || arg1 =="Max"){
        ui->doubleSpinBoxValeur->setEnabled(false);
        ui->comboBoxParametre->setEnabled(false);
        ui->dateTimeEdit->setEnabled(true);
        ui->dateTimeEditIntervalle->setEnabled(true);

        ui->radioButtonDate->setAutoExclusive(false);
        ui->radioButtonDate->setChecked(true);
        ui->radioButtonDate->setAutoExclusive(true);
        ui->radioButtonParametre->setCheckable(false);
        ui->radioButtonValeur->setCheckable(false);

        ui->buttonAjouterParametre->setEnabled(true);

        setParametre(4,ui->dateTimeEdit->dateTime().toString(),"Date");

    }else if(arg1 == "Sans"){
        ui->doubleSpinBoxValeur->setEnabled(false);
        ui->comboBoxParametre->setEnabled(true);
        ui->dateTimeEdit->setEnabled(false);
        ui->dateTimeEditIntervalle->setEnabled(false);

        ui->radioButtonParametre->setAutoExclusive(false);
        ui->radioButtonParametre->setChecked(true);
        ui->radioButtonParametre->setAutoExclusive(true);
        ui->radioButtonDate->setCheckable(false);
        ui->radioButtonValeur->setCheckable(false);

        ui->buttonAjouterParametre->setEnabled(true);

        setParametre(4,ui->comboBoxParametre->currentText(),"Parametre");

    }else{
        ui->radioButtonParametre->setCheckable(true);
        ui->radioButtonValeur->setCheckable(true);
        ui->radioButtonDate->setCheckable(true);
    }
}

void ParametreTest::on_comboBoxFirstOperande_currentIndexChanged(const QString &arg1)
{
    if(newParametre.count()>=1)
        newParametre.replace(0,arg1);
    else
        newParametre.insert(0,arg1);
}


void ParametreTest::on_comboBoxParametre_currentIndexChanged(const QString &arg1)
{
    setParametre(4,arg1,"Parametre");
}

void ParametreTest::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    setParametre(4,dateTime.toString(),"date");

    ui->dateTimeEditIntervalle->setDateTime(dateTime);

    if(newParametre.count()>=5)
        newParametre.replace(4,dateTime.toString());
    else
        newParametre.insert(4,dateTime.toString());
}

void ParametreTest::on_dateTimeEditIntervalle_dateTimeChanged(const QDateTime &dateTime)
{
    if(newParametre.count()>=5)
        newParametre.replace(4,dateTime.toString());
    else
        newParametre.insert(4,dateTime.toString());
}

void ParametreTest::on_doubleSpinBoxValeur_valueChanged(double arg1)
{
    setParametre(4,QString::number(arg1),"Valeur");
}

void ParametreTest::on_listViewParametreTest_clicked(const QModelIndex &index)
{
    QStringList parametre = index.data().toString().split("|");

    int i = ui->comboBoxFirstOperande->findText(parametre.at(0));

    ui->comboBoxFirstOperande->setCurrentIndex(i);

    i = ui->comboBoxOperation->findText(parametre.at(1));

    ui->comboBoxOperation->setCurrentIndex(i);

    // si on as plus d'un element quand un decoupe le troisieme parametre avec ":" il s'agit d'une date
    if(parametre.at(3).split(":").count()>1 || parametre.at(1) =="Min" || parametre.at(1) =="Max"){
        ui->dateTimeEdit->setDateTime(QDateTime::fromString(parametre.at(3),"yyyy-MM-dd hh:mm:ss"));
        ui->dateTimeEditIntervalle->setDateTime(QDateTime::fromString(parametre.at(4),"yyyy-MM-dd hh:mm:ss"));
        ui->comboBoxParametre->setEnabled(false);
        ui->doubleSpinBoxValeur->setEnabled(false);
        ui->dateTimeEdit->setEnabled(true);
        ui->dateTimeEditIntervalle->setEnabled(true);

    }else if(ui->comboBoxParametre->findText(parametre.at(3)) != -1){// si on le trouve dans la comboBox il s'agit d'une station ou d'un parametre
        i = ui->comboBoxParametre->findText(parametre.at(3));
        ui->comboBoxParametre->setCurrentIndex(i);
        ui->comboBoxParametre->setEnabled(true);
        ui->doubleSpinBoxValeur->setEnabled(false);
        ui->dateTimeEdit->setEnabled(false);
        ui->dateTimeEditIntervalle->setEnabled(false);

    }else{// il s'agit d'une valeur
        ui->doubleSpinBoxValeur->clear();
        ui->doubleSpinBoxValeur->setValue(parametre.at(3).toDouble());
        ui->comboBoxParametre->setEnabled(false);
        ui->doubleSpinBoxValeur->setEnabled(true);
        ui->dateTimeEdit->setEnabled(false);
        ui->dateTimeEditIntervalle->setEnabled(false);
    }

    i=0;
    foreach(QString p,parametre){
        if(newParametre.count() >= i+1)
            newParametre.replace(i,p);
        else
            newParametre.insert(i,p);
        i++;
    }
    ui->buttonModifierParametre->setEnabled(true);
}

void ParametreTest::on_listViewParametreTest_doubleClicked(const QModelIndex &index)
{
    ui->buttonModifierParametre->setEnabled(false);

    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewParametreTest->model());

    QStringList parametres = model->stringList();

    parametres.removeOne(index.data().toString());

    model->setStringList(parametres);
}

void ParametreTest::on_buttonValider_clicked()
{
    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewParametreTest->model());
    parametreTest = model->stringList();
    close();
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/

void ParametreTest::init_listView_Xml(Xml *xml){
    QList<QDomElement> listElement= xml->getCible("ParametresTest");

    QStringList listParametre;

    foreach(QDomElement element,listElement){
        listParametre.append(element.text());
    }

    QStringListModel *modelList = new QStringListModel(listParametre);

    ui->listViewParametreTest->setModel(modelList);

    ui->listViewParametreTest->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->listViewParametreTest->setSelectionMode(QAbstractItemView::SingleSelection);
}

void ParametreTest::initComboBox(){
    QStringList parametres = modelParametre->getListNomParametre();

    ui->comboBoxFirstOperande->clear();
    ui->comboBoxParametre->clear();

    ui->comboBoxFirstOperande->addItems(parametres);
    ui->comboBoxParametre->addItems(parametres);
}

void ParametreTest::setParametre(int index,QString parametre,QString label){
    if(newParametre.count()>=index){
        newParametre.replace(index-2,label);
        newParametre.replace(index-1,parametre);
    }
    else{
        newParametre.insert(index-2,label);
        newParametre.insert(index-1,parametre);
    }
}
