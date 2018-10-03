#ifndef EMPLACEMENTXML_H
#define EMPLACEMENTXML_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QStandardPaths>

namespace Ui {
class EmplacementXml;
}

class EmplacementXml : public QDialog
{
    Q_OBJECT

public:
    explicit EmplacementXml(QWidget *parent = 0);

    QString getEmplacement();

    ~EmplacementXml();

private slots:
    void on_buttonValider_clicked();

    void on_buttonAnnuler_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::EmplacementXml *ui;
    QString emplacement;
};

#endif // EMPLACEMENTXML_H
