#ifndef GROUPEEDIT_H
#define GROUPEEDIT_H

#include <QWidget>
#include <QMessageBox>

#include "Core/vue.h"
#include "Core/stations.h"
#include "Core/parametres.h"
#include "Core/groupes.h"

namespace Ui {
class GroupeEdit;
}

class GroupeEdit : public QWidget, public Vue
{
    Q_OBJECT

public:
    explicit GroupeEdit(QWidget *parent = 0);
    GroupeEdit(Stations *s, Parametres *p , Groupes *g, QWidget *parent = 0);

    ~GroupeEdit();

    void ouvrir(QList<Element*> l,Element* p);
    void refresh();

private slots:
    void on_listViewCur_clicked(const QModelIndex &index);

    void on_listViewEle_clicked(const QModelIndex &index);

    void on_buttonEdit_clicked();

    void on_buttonAnnuler_clicked();

private:
    Ui::GroupeEdit *ui;
    Stations *modelStation;
    Parametres *modelParametre;
    Groupes *modelGroupe;
    QList<Element*> listCur;
    QList<Element*> listIni;
    QList<Element*> listEle;
    Element *pere;
    Element *oldPere;

    void init_table();
};

#endif // GROUPEEDIT_H
