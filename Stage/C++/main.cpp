#include "Ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EmplacementXml *eXml = new EmplacementXml();

    QString emplacement = eXml->getEmplacement();
    if(emplacement.isEmpty()){
        eXml->exec();
        emplacement = eXml->getEmplacement();
    }
    delete eXml;

    Xml *xml = new Xml(emplacement);

    MainWindow w(xml);

    return a.exec();
}
