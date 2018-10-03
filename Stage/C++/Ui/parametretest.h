#ifndef PARAMETRETEST_H
#define PARAMETRETEST_H

#include <QWidget>
#include <QMessageBox>

#include "Core/vue.h"
#include "Core/stations.h"
#include "Core/parametres.h"
#include "Core/groupes.h"

namespace Ui {
class ParametreTest;
}

class ParametreTest : public QWidget, public Vue
{
    Q_OBJECT

public:
    explicit ParametreTest(QWidget *parent = 0);
    ParametreTest(Parametres *p , Xml *xml, QWidget *parent = 0);

    ~ParametreTest();

    void refresh();

    QStringList getParametreTest();

private slots:
    void on_buttonAjouterParametre_clicked();

    void on_buttonModifierParametre_clicked();

    void on_radioButtonParametre_clicked(bool checked);

    void on_radioButtonValeur_clicked(bool checked);

    void on_radioButtonDate_clicked(bool checked);

    void on_comboBoxOperation_currentIndexChanged(const QString &arg1);

    void on_comboBoxFirstOperande_currentIndexChanged(const QString &arg1);

    void on_comboBoxParametre_currentIndexChanged(const QString &arg1);

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_dateTimeEditIntervalle_dateTimeChanged(const QDateTime &dateTime);

    void on_doubleSpinBoxValeur_valueChanged(double arg1);

    void on_listViewParametreTest_clicked(const QModelIndex &index);

    void on_listViewParametreTest_doubleClicked(const QModelIndex &index);

    void on_buttonValider_clicked();

private:
    Ui::ParametreTest *ui;
    Parametres *modelParametre;
    QStringList newParametre;
    QStringList parametreTest;

    void init_listView_Xml(Xml *xml);
    void initComboBox();
    void setParametre(int index,QString parametre,QString label);

};

#endif // PARAMETRETEST_H
