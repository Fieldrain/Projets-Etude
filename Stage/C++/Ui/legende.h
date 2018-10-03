#ifndef LEGENDE_H
#define LEGENDE_H

#include <QWidget>
#include <QStandardItem>
#include <QColorDialog>

#include "Core/vue.h"
#include "Core/stations.h"
#include "Core/parametres.h"
#include "Core/groupes.h"

namespace Ui {
class Legende;
}

class Legende : public QWidget, public Vue
{
    Q_OBJECT

public:
    explicit Legende(QWidget *parent = 0);
    Legende(Stations *s, Parametres *p , Groupes *g, QWidget *parent = 0);

    ~Legende();

    void refresh();

private slots:
    void on_tableViewStation_clicked(const QModelIndex &index);

    void on_tableViewParametre_clicked(const QModelIndex &index);

    void tableViewStation_dataChanged(const QModelIndex & topLeft);

    void tableViewParametre_dataChanged(const QModelIndex & topLeft);

private:
    Ui::Legende *ui;
    Stations *modelStation;
    Parametres *modelParametre;
    Groupes *modelGroupe;
    QString currentItemData;

    void init_table();
    void init_TabParametre(QStringList header);
    void init_TabStation(QStringList header);
    void colorChange(QStandardItem *item);
};

#endif // LEGENDE_H
