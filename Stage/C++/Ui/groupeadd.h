#ifndef GROUPEADD_H
#define GROUPEADD_H

#include <QWidget>
#include <QMessageBox>

#include "Core/vue.h"
#include "Core/stations.h"
#include "Core/parametres.h"
#include "Core/groupes.h"

namespace Ui {
class GroupeAdd;
}

class GroupeAdd : public QWidget, public Vue
{
    Q_OBJECT

public:
    explicit GroupeAdd(QWidget *parent = 0);
    GroupeAdd(Stations *s, Parametres *p , Groupes *g, QWidget *parent = 0);

    ~GroupeAdd();

    void ouvrir(QList<Element*> l, Element* p);
    void refresh();

private slots:

    void on_checkBoxNom_stateChanged(int arg1);

    void on_checkBoxGroupe_stateChanged(int arg1);

    void on_listViewGroupe_clicked(const QModelIndex &index);

    void on_buttonCreer_clicked();

    void listViewSelections_clicked(const QModelIndex &index);

    void on_buttonAnnuler_clicked();

private:
    Ui::GroupeAdd *ui;
    Stations *modelStation;
    Parametres *modelParametre;
    Groupes *modelGroupe;
    QList<Element*> list;
    Element* pere;

    void init_listView();
    void init_element();
};

#endif // GROUPEADD_H
