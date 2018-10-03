#ifndef CONFIGSTATIONPARAMETRE_H
#define CONFIGSTATIONPARAMETRE_H

#include <QDialog>
#include <QMessageBox>
#include <QKeyEvent>

#include "Core/stations.h"
#include "Core/parametres.h"
#include "Core/vue.h"

namespace Ui {
class ConfigStationParametre;
}

class ConfigStationParametre : public QDialog, public Vue
{
    Q_OBJECT

public:
    explicit ConfigStationParametre(QWidget *parent = 0);
    ConfigStationParametre(Stations *s, Parametres *p , QWidget *parent = 0);
    ~ConfigStationParametre();

    void refresh();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_listViewNouveaux_clicked(const QModelIndex &index);

    void on_buttonValiderCategorie_clicked();

    void on_lineEditNewCategorie_editingFinished();

    void on_buttonFin_clicked();

private:
    Ui::ConfigStationParametre *ui;
    Parametres *modelParametres;
    Stations *modelStations;

    void init_listView();
    void init_comboBox();
};

#endif // CONFIGSTATIONPARAMETRE_H
