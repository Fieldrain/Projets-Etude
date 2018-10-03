#ifndef CONFIGTEST_H
#define CONFIGTEST_H

#include <QDialog>
#include <QMessageBox>
#include <QKeyEvent>

#include "Core/vue.h"
#include "Core/parametres.h"

namespace Ui {
class ConfigTest;
}

class ConfigTest : public QDialog, public Vue
{
    Q_OBJECT

public:
    explicit ConfigTest(QWidget *parent = 0);
    ConfigTest(Parametres *p , Xml *xml, QWidget *parent = 0);
    ~ConfigTest();

    void refresh();

    QStringList getConfigTest();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_buttonAjouterParametre_clicked();

    void on_buttonModifierParametre_clicked();

    void on_comboBoxOperation_currentIndexChanged(const QString &arg1);

    void on_comboBoxParametre_currentIndexChanged(const QString &arg1);

    void on_doubleSpinBoxValeur_editingFinished();

    void on_checkBoxParametre_toggled(bool checked);

    void on_checkBoxValeur_toggled(bool checked);

    void on_tableValeurstest_clicked(const QModelIndex &index);

    void on_listViewConfigTest_clicked(const QModelIndex &index);

    void on_listViewConfigTest_doubleClicked(const QModelIndex &index);

    void on_buttonBox_accepted();

    void on_buttonAnnuler_clicked();


private:
    Ui::ConfigTest *ui;
    Parametres *modelParametre;
    QStringList configTest;

    void init_listView_Xml(Xml *xml);
    void init_ComboBox();
    QString getNewParametreTest();
    bool valide();
};

#endif // CONFIGTEST_H
