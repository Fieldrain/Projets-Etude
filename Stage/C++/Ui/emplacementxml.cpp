#include "emplacementxml.h"
#include "ui_emplacementxml.h"

/*--------------------------------CONSTRUCTEURS--------------------------------*/
EmplacementXml::EmplacementXml(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmplacementXml)
{
    ui->setupUi(this);
    QString url = QDir::homePath()+"/.configLocalGraphXair.txt";
    QFile fichier(url);
    if(fichier.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fichier);
        emplacement = stream.readLine();
    }
    fichier.close();

}
/*--------------------------------DESTRUCTEURS--------------------------------*/
EmplacementXml::~EmplacementXml()
{
    delete ui;
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
// fonction qui rencoie l'emplacement selectionner
QString EmplacementXml::getEmplacement(){
    return emplacement;
}

/*--------------------------------FONCTIONS PRIVATE SLOTS--------------------------------*/
void EmplacementXml::on_buttonValider_clicked()
{
    if(!ui->lineEdit->text().isEmpty() && ui->checkBoxEnregistrer->isChecked()){
        QString url = QDir::homePath()+"/.configLocalGraphXair.txt";
        QFile fichier(url);
        if(!fichier.open(QIODevice::ReadWrite | QIODevice::Truncate))
        {
            QMessageBox msgBox;
            msgBox.setText("Impossible d'écrire dans le document");
            msgBox.exec();
        }else{
            QTextStream stream(&fichier);

            QString donne = emplacement;
            stream << donne;

        }
        fichier.close();
    }

    close();
}

void EmplacementXml::on_buttonAnnuler_clicked()
{
    emplacement = "";
    close();
}

void EmplacementXml::on_pushButton_clicked()
{
    QFileDialog fileDialog;
    QString filename = fileDialog.getExistingDirectory()+"/configXMLGraphXair.xml";
    ui->lineEdit->setText(filename);
    emplacement = filename;
}

void EmplacementXml::on_lineEdit_editingFinished()
{
    emplacement = ui->lineEdit->text();
}
