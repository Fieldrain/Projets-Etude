#include "configtest.h"
#include "ui_configtest.h"

// classe qui herite de vue ca fonction refresh sera appeler a chaque fois que les donnees d'un model (groupes, stations,parametres )changent

/*--------------------------------CONSTRUCTEURS--------------------------------*/
ConfigTest::ConfigTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigTest)
{
    ui->setupUi(this);
}

ConfigTest::ConfigTest( Parametres *p, Xml *xml, QWidget *parent):
    QDialog(parent),
    ui(new Ui::ConfigTest),
    modelParametre(p)
{
    modelParametre->abonne(this);

    ui->setupUi(this);

    init_listView_Xml(xml);

    refresh();
}

/*--------------------------------DESTRUCTEURS--------------------------------*/
ConfigTest::~ConfigTest()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
void ConfigTest::refresh(){
    init_ComboBox();

    ui->listViewConfigTest->selectionModel()->clearSelection();

    ui->doubleSpinBoxValeur->setValue(0);
    ui->doubleSpinBoxValeur->setEnabled(false);

    ui->comboBoxParametre->setEnabled(false);
    ui->comboBoxParametre->setCurrentIndex(0);
    ui->comboBoxOperation->setCurrentIndex(0);

    ui->checkBoxParametre->setEnabled(true);
    ui->checkBoxValeur->setEnabled(true);

    ui->checkBoxParametre->setChecked(false);
    ui->checkBoxValeur->setChecked(false);

    ui->buttonAjouterParametre->setEnabled(false);
    ui->buttonModifierParametre->setEnabled(false);

    for(int i =0;i<ui->tableValeurstest->rowCount();i++)
        ui->tableValeurstest->removeRow(i);

    ui->tableValeurstest->setColumnHidden(2,true);

    ui->tableValeurstest->setRowCount(1);

    QStringList header;
    header.append("Valeurs du test");
    header.append("Valider");
    ui->tableValeurstest->setHorizontalHeaderLabels(header);

}

// fonction qui permet de recuperer la liste des tests
QStringList ConfigTest::getConfigTest(){
    return configTest;
}

/*--------------------------------FONCTIONS PROTECTED--------------------------------*/
// surcharge l'evenement entrer qui ferme nrmalement la fenetre car c'est une QDialog
void ConfigTest::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Enter){
        event->accept();
    }
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/
void ConfigTest::on_buttonAjouterParametre_clicked()
{
    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewConfigTest->model());

    QStringList parametres = model->stringList();
    QString parametre = getNewParametreTest();

    if(!parametre.isEmpty()){
        parametres.append(parametre);

        model->setStringList(parametres);

        refresh();

    }
}

void ConfigTest::on_buttonModifierParametre_clicked()
{
    int index = ui->listViewConfigTest->selectionModel()->selectedIndexes().at(0).row();

    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewConfigTest->model());

    QStringList parametres = model->stringList();

    QString parametre = getNewParametreTest();

    if(!parametre.isEmpty()){

        parametres.replace(index,parametre);

        model->setStringList(parametres);

        refresh();
    }
}

void ConfigTest::on_comboBoxOperation_currentIndexChanged(const QString &arg1)
{
    ui->checkBoxParametre->setChecked(false);
    ui->checkBoxValeur->setChecked(false);

    ui->doubleSpinBoxValeur->setValue(0);
    ui->doubleSpinBoxValeur->setEnabled(false);

    ui->comboBoxParametre->setEnabled(false);
    ui->comboBoxParametre->setCurrentIndex(0);

    ui->checkBoxParametre->setEnabled(true);
    ui->checkBoxValeur->setEnabled(true);

    ui->buttonAjouterParametre->setEnabled(false);
    ui->buttonModifierParametre->setEnabled(false);

    for(int i =0;i<ui->tableValeurstest->rowCount();i++)
        ui->tableValeurstest->removeRow(i);

    if(arg1 == "Sans"){
        ui->comboBoxParametre->setEnabled(true);

        ui->checkBoxParametre->setChecked(true);
        ui->checkBoxValeur->setEnabled(false);
    }
    if(arg1 == "Sup ou =" || arg1 == "Inf ou =" || arg1 == "Sup et Inf"){
        ui->tableValeurstest->setRowCount(2);
    }else
        ui->tableValeurstest->setRowCount(1);
}

void ConfigTest::on_comboBoxParametre_currentIndexChanged(const QString &arg1)
{
    if(ui->tableValeurstest->item(0,0) == NULL || ui->tableValeurstest->item(0,1)->text() != "V"){
        ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(arg1));
        ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("Valider ?"));
        ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Parametre"));
    }
    else if(ui->tableValeurstest->item(1,0) == NULL || ui->tableValeurstest->item(1,1)->text() != "V"){
        ui->tableValeurstest->setItem(1,0,new QTableWidgetItem(arg1));
        ui->tableValeurstest->setItem(1,1,new QTableWidgetItem("Valider ?"));
        ui->tableValeurstest->setItem(1,2,new QTableWidgetItem("Parametre"));
    }

}

void ConfigTest::on_doubleSpinBoxValeur_editingFinished()
{
    QString arg1 = QString::number(ui->doubleSpinBoxValeur->value());

    if(ui->tableValeurstest->item(0,0) == NULL || ui->tableValeurstest->item(0,1)->text() != "V"){
        ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(arg1));
        ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("Valider ?"));
        ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Valeur"));
    }
    else if(ui->tableValeurstest->item(1,0) == NULL || ui->tableValeurstest->item(1,1)->text() != "V"){
        ui->tableValeurstest->setItem(1,0,new QTableWidgetItem(arg1));
        ui->tableValeurstest->setItem(1,1,new QTableWidgetItem("Valider ?"));
        ui->tableValeurstest->setItem(1,2,new QTableWidgetItem("Valeur"));
    }
}

void ConfigTest::on_checkBoxParametre_toggled(bool checked)
{
    bool tousValide = valide();
    // si la checkbox parametre est cocher et que les valeurs du tableau ne sont pas valider
    if(checked && !tousValide){
        QString operation = ui->comboBoxOperation->currentText();
        if(operation == "Sup" || operation == "Inf" || operation == "=" || operation == "Sans"){
            ui->doubleSpinBoxValeur->setEnabled(false);

            ui->checkBoxValeur->setEnabled(false);

            ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(ui->comboBoxParametre->currentText()));
            ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("Valider ?"));
            ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Parametre"));

        }else{
            if(ui->tableValeurstest->item(0,0) != NULL && ui->tableValeurstest->item(0,1)->text() == "V" && ui->tableValeurstest->item(0,2)->text() == "Valeur")
                ui->doubleSpinBoxValeur->setEnabled(false);

            if(ui->tableValeurstest->item(0,0) == NULL || ui->tableValeurstest->item(0,1)->text() != "V"){
                ui->checkBoxValeur->setChecked(false);
                ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(ui->comboBoxParametre->currentText()));
                ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("Valider ?"));
                ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Parametre"));
            }
            else{
                ui->tableValeurstest->setItem(1,0,new QTableWidgetItem(ui->comboBoxParametre->currentText()));
                ui->tableValeurstest->setItem(1,1,new QTableWidgetItem("Valider ?"));
                ui->tableValeurstest->setItem(1,2,new QTableWidgetItem("Parametre"));
            }

        }

        ui->comboBoxParametre->setEnabled(true);
          // si la checkbox parametre est cocher et que les valeurs du tableau sont valider
    }else if(tousValide && checked){
        ui->checkBoxParametre->setChecked(false);
        // si la checkbox parametre n'est pas cocher
    }else{
        ui->checkBoxValeur->setEnabled(true);
        ui->comboBoxParametre->setEnabled(false);
        // on enleve toute les valeurs qui correspondent a un parametre
        int i = 0;
        while(i<ui->tableValeurstest->rowCount()){
            if(ui->tableValeurstest->item(i,0) != NULL && ui->tableValeurstest->item(i,2)->text() == "Parametre") {
                ui->tableValeurstest->removeRow(i);
            }else{
                i++;
            }
        }

        QString arg1 = ui->comboBoxOperation->currentText();

        // on force le nombre de ligne pour eviter d'en perdre a cause des remove fait au dessus
        if(arg1 == "Sup ou =" || arg1 == "Inf ou =" || arg1 == "Sup et Inf"){

            ui->tableValeurstest->setRowCount(2);
        }else{
            ui->tableValeurstest->setRowCount(1);
        }

        // on force le statut de la spinbox valeur si on as une valeur de valider dans le tableau
        if(ui->tableValeurstest->item(0,0) != NULL && ui->tableValeurstest->item(0,1)->text() == "V" && ui->tableValeurstest->item(0,2)->text() == "Valeur"){
            ui->doubleSpinBoxValeur->setEnabled(true);
        }

        // on met a jour le statut des bouttons
        if(ui->listViewConfigTest->selectionModel()->selectedIndexes().isEmpty())
            ui->buttonAjouterParametre->setEnabled(valide());
        else
            ui->buttonModifierParametre->setEnabled(valide());
    }
}

void ConfigTest::on_checkBoxValeur_toggled(bool checked)
{
    //meme fonctionnement que ci-dessus
    bool tousValide = valide();
    if(checked && !tousValide){
        QString operation = ui->comboBoxOperation->currentText();

        if(operation == "Sup" || operation == "Inf" || operation == "=" || operation == "Sans"){
            ui->comboBoxParametre->setEnabled(false);

            ui->checkBoxParametre->setEnabled(false);

            ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(QString::number(ui->doubleSpinBoxValeur->value())));
            ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("Valider ?"));
            ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Valeur"));

        }else{
            if(ui->tableValeurstest->item(0,0) != NULL && ui->tableValeurstest->item(0,1)->text() == "V" && ui->tableValeurstest->item(0,2)->text() == "Parametre")
                ui->comboBoxParametre->setEnabled(false);

            if(ui->tableValeurstest->item(0,0) == NULL || ui->tableValeurstest->item(0,1)->text() != "V"){
                ui->checkBoxParametre->setChecked(false);
                ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(QString::number(ui->doubleSpinBoxValeur->value())));
                ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("Valider ?"));
                ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Valeur"));
            }
            else{
                ui->tableValeurstest->setItem(1,0,new QTableWidgetItem(QString::number(ui->doubleSpinBoxValeur->value())));
                ui->tableValeurstest->setItem(1,1,new QTableWidgetItem("Valider ?"));
                ui->tableValeurstest->setItem(1,2,new QTableWidgetItem("Valeur"));
            }

        }

        ui->doubleSpinBoxValeur->setEnabled(true);
    }else if(tousValide && checked){
        ui->checkBoxValeur->setChecked(false);
    }else{
        ui->doubleSpinBoxValeur->setEnabled(false);

        ui->checkBoxParametre->setEnabled(true);

        int i =0;
        while(i<ui->tableValeurstest->rowCount()){
            if(ui->tableValeurstest->item(i,0) != NULL && ui->tableValeurstest->item(i,2)->text() == "Valeur") {
                ui->tableValeurstest->removeRow(i);
            }else{
                i++;
            }
        }

        QString arg1 = ui->comboBoxOperation->currentText();

        if(arg1 == "Sup ou =" || arg1 == "Inf ou =" || arg1 == "Sup et Inf"){
            ui->tableValeurstest->setRowCount(2);
        }else
            ui->tableValeurstest->setRowCount(1);

        if(ui->tableValeurstest->item(0,0) != NULL && ui->tableValeurstest->item(0,1)->text() == "V" && ui->tableValeurstest->item(0,2)->text() == "Parametre"){
            ui->comboBoxParametre->setEnabled(true);
        }

        if(ui->listViewConfigTest->selectionModel()->selectedIndexes().isEmpty())
            ui->buttonAjouterParametre->setEnabled(valide());
        else
            ui->buttonModifierParametre->setEnabled(valide());
    }

}

void ConfigTest::on_tableValeurstest_clicked(const QModelIndex &index)
{
    if (ui->tableValeurstest->item(index.row(),1) != NULL){
        if(ui->tableValeurstest->item(index.row(),1)->text()== "Valider ?")
            ui->tableValeurstest->setItem(index.row(),1,new QTableWidgetItem("V"));
        else
            ui->tableValeurstest->setItem(index.row(),1,new QTableWidgetItem("Valider ?"));
        bool tousValide = valide();

        if(ui->listViewConfigTest->selectionModel()->selectedIndexes().isEmpty())
            ui->buttonAjouterParametre->setEnabled(tousValide);
        else
            ui->buttonModifierParametre->setEnabled(tousValide);
    }

}


void ConfigTest::on_listViewConfigTest_clicked(const QModelIndex &index)
{
    ui->buttonAjouterParametre->setEnabled(false);

    QStringList parametre = index.data().toString().split("|");

    int i = ui->comboBoxFirstOperande->findText(parametre.at(1));
    ui->comboBoxFirstOperande->setCurrentIndex(i);

    i = ui->comboBoxOperation->findText(parametre.at(2));
    ui->comboBoxOperation->setCurrentIndex(i);

    i = ui->comboBoxType->findText(parametre.at(0));
    ui->comboBoxType->setCurrentIndex(i);

    // si on le trouve dans la comboBox il s'agit d'une station ou d'un parametre
    if(parametre.at(3)== "Parametre"){
        ui->checkBoxParametre->setChecked(true);
        // setChecked rappelle egalement la fonction on_checkBoxParametre_toggled

        i = ui->comboBoxParametre->findText(parametre.at(4));
        ui->comboBoxParametre->setCurrentIndex(i);
        ui->comboBoxParametre->setEnabled(true);

        ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(parametre.at(4)));
        ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Parametre"));
        ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("V"));

    }else if(parametre.at(3) == "Valeur"){
        ui->checkBoxValeur->setChecked(true);

        ui->doubleSpinBoxValeur->setValue(parametre.at(4).toDouble());
        ui->doubleSpinBoxValeur->setEnabled(true);

        ui->tableValeurstest->setItem(0,0,new QTableWidgetItem(parametre.at(4)));
        ui->tableValeurstest->setItem(0,2,new QTableWidgetItem("Valeur"));
        ui->tableValeurstest->setItem(0,1,new QTableWidgetItem("V"));
    }else{
        ui->tableValeurstest->setRowCount(0);
        QStringList typeValeurs = parametre.at(3).split(" ");
        ui->tableValeurstest->setRowCount(typeValeurs.count());

        for(int i=0;i<typeValeurs.count();i++){
            QString typeValeur = typeValeurs.at(i);
            QString val = parametre.at(4+i);

            if(typeValeur == "Parametre"){
                if(!ui->checkBoxParametre->isChecked())
                    ui->checkBoxParametre->setChecked(true);
                // setChecked rappelle egalement la fonction on_checkBoxParametre_toggled

                int j = ui->comboBoxParametre->findText(val);
                ui->comboBoxParametre->setCurrentIndex(j);
                ui->comboBoxParametre->setEnabled(true);

            }else if(typeValeur == "Valeur"){
                if(!ui->checkBoxValeur->isChecked())
                    ui->checkBoxValeur->setChecked(true);

                ui->doubleSpinBoxValeur->setValue(val.toDouble());
                ui->doubleSpinBoxValeur->setEnabled(true);
            }

            ui->tableValeurstest->setItem(i,0,new QTableWidgetItem(val));
            ui->tableValeurstest->setItem(i,2,new QTableWidgetItem(typeValeur));
            ui->tableValeurstest->setItem(i,1,new QTableWidgetItem("V"));
        }

        if(parametre.at(3) == "Parametre Valeur" || parametre.at(3) == "Valeur Parametre"){
            ui->doubleSpinBoxValeur->setEnabled(true);
            ui->comboBoxParametre->setEnabled(true);
        }
    }
    ui->buttonAjouterParametre->setEnabled(false);
    ui->buttonModifierParametre->setEnabled(true);
}

void ConfigTest::on_listViewConfigTest_doubleClicked(const QModelIndex &index)
{
    ui->buttonModifierParametre->setEnabled(false);

    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewConfigTest->model());

    QStringList parametres = model->stringList();

    parametres.removeOne(index.data().toString());

    model->setStringList(parametres);

    refresh();
}

void ConfigTest::on_buttonBox_accepted()
{
    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listViewConfigTest->model());
    configTest = model->stringList();
    close();
}

void ConfigTest::on_buttonAnnuler_clicked()
{
    close();
}

/*--------------------------------FONCTIONS PRIVATE--------------------------------*/
// fonction qui initialise la list view avec les test presents dans le xml
void ConfigTest::init_listView_Xml(Xml *xml){
    QList<QDomElement> listElement= xml->getCible("ParametresTest");

    QStringList listParametre;

    foreach(QDomElement element,listElement){
        listParametre.append(element.text());
    }

    QStringListModel *modelList = new QStringListModel(listParametre);

    ui->listViewConfigTest->setModel(modelList);

    ui->listViewConfigTest->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->listViewConfigTest->setSelectionMode(QAbstractItemView::SingleSelection);

    configTest = modelList->stringList();

}

// fonction qui initialise les comboBox avec la liste des parametres
void ConfigTest::init_ComboBox(){
    QStringList parametres = modelParametre->getListNomParametre();

    ui->comboBoxFirstOperande->clear();
    ui->comboBoxParametre->clear();

    ui->comboBoxFirstOperande->addItem("Tous");
    ui->comboBoxParametre->addItem("Tous");

    ui->comboBoxFirstOperande->addItems(parametres);
    ui->comboBoxParametre->addItems(parametres);
}

// fonction qui permet de recuperer les elements du test et de la mettre en forme
QString ConfigTest::getNewParametreTest(){
    QString parametre = "";

    QString nomPremierParametre = ui->comboBoxFirstOperande->currentText();
    QString operation = ui->comboBoxOperation->currentText();
    if(ui->checkBoxIntervalle->isChecked())
        operation += " avec Intervalle";

    if(operation == "Sup" || operation == "Inf" || operation == "=" || operation == "Sans"){
        if(ui->checkBoxParametre->isChecked()){
            parametre += ui->comboBoxType->currentText() + "|" + nomPremierParametre + "|"  +operation + "|"+ "Parametre" +"|";
            QString nomDeuxiemeParametre = ui->tableValeurstest->item(0,0)->text();

            if(nomPremierParametre != nomDeuxiemeParametre && !nomDeuxiemeParametre.isEmpty() && (nomPremierParametre != "Tous" && nomDeuxiemeParametre!="Tous")){
                parametre += nomDeuxiemeParametre;
            }else{
                QMessageBox msg;
                msg.setWindowTitle("Erreur");
                msg.setText("Impossible d'effectuer le test demandé");
                msg.exec();
                return "";
            }

        }else if(ui->checkBoxValeur->isChecked()){
            parametre += ui->comboBoxType->currentText() + "|" + nomPremierParametre + "|"  +operation + "|"+ "Valeur" +"|";
            QString val = ui->tableValeurstest->item(0,0)->text();

            parametre += val;
        }
    }else{
        parametre += ui->comboBoxType->currentText() + "|" + nomPremierParametre + "|"  +operation + "|";

        QString typeValeurs;
        QString valeurs;

        for(int i =0; i<ui->tableValeurstest->rowCount();i++){
            QString valeur = ui->tableValeurstest->item(i,0)->text();
            QString typeValeur = ui->tableValeurstest->item(i,2)->text();

            if(i>=ui->tableValeurstest->rowCount()-1)
                typeValeurs += typeValeur;
            else
                typeValeurs += typeValeur + " ";

            if(typeValeur == "Parametre"){
                if(nomPremierParametre != valeur && !valeur.isEmpty() && (nomPremierParametre != "Tous" && valeur!="Tous")){
                    if(i>=ui->tableValeurstest->rowCount()-1)
                        valeurs += valeur;
                    else
                        valeurs += valeur +"|";
                }else{
                    QMessageBox msg;
                    msg.setWindowTitle("Erreur");
                    msg.setText("Impossible d'effectuer le test demandé");
                    msg.exec();
                    return "";
                }

            }else{
                if(i>=ui->tableValeurstest->rowCount()-1)
                    valeurs += valeur;
                else
                    valeurs += valeur +"|";
            }

        }

        parametre += typeValeurs + "|" + valeurs;
    }

    if(ui->checkBoxIntervalle->isChecked()){
        parametre += "|" + QString::number(ui->spinBoxIntervalle->value()) + " " + ui->comboBoxIntervalle->currentText();
    }

    return parametre;
}

// fonction qui permet de savoir si tous les elements du tableaux ont été valider
bool ConfigTest::valide(){

    bool tousValide = true;

    int i =0;

    if(ui->tableValeurstest->rowCount()==0)
        tousValide = false;
    else{
        while(tousValide && i<ui->tableValeurstest->rowCount()){

            if(ui->tableValeurstest->item(i,0) == NULL || ui->tableValeurstest->item(i,1)->text() != "V")
                tousValide = false;

            i++;
        }
    }

    return tousValide;
}
