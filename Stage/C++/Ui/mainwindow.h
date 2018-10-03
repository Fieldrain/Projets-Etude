#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QWheelEvent>
#include <QTextStream>

#include "Core/vue.h"
#include "Core/stations.h"
#include "Core/parametres.h"
#include "Core/groupes.h"
#include "Core/scene.h"
#include "Core/configscene.h"
#include "Core/csv.h"
#include "Core/gestiondate.h"

#include "groupeadd.h"
#include "groupeedit.h"
#include "legende.h"
#include "configtest.h"
#include "fullscreen.h"
#include "configstationparametre.h"
#include "configechelle.h"
#include "Aide/aideajoutgroupe.h"
#include "Aide/aideeditgroupe.h"
#include "Aide/aidesupprgroupe.h"
#include "Aide/aideparametretest.h"
#include "Aide/aidegraph.h"
#include "emplacementxml.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Vue
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(Xml *xml, QWidget *parent = 0);

    ~MainWindow();

    void refresh();

protected :
    void keyPressEvent(QKeyEvent * event);

    void closeEvent(QCloseEvent *event);

private slots:

    void on_actionOuvrir_triggered();

    void on_actionFermer_triggered();

    void on_actionParam_tre_Test_triggered();

    void on_actionAjouter_un_groupe_triggered();

    void on_actionSupprimer_un_groupe_triggered();

    void on_actionEditer_un_groupe_triggered();

    void on_actionParam_tres_de_test_triggered();

    void on_actionManipulation_des_Graphs_triggered();

    void on_actionEmplacement_XMl_triggered();

    void on_treeViewGroupe_clicked(const QModelIndex &index);

    void on_buttonEditerGroupe_clicked();

    void on_buttonLegende_clicked();

    void on_buttonAjoutGroupe_clicked();

    void on_buttonSupprGroupe_clicked();

    void on_buttonActualiser_clicked();

    void on_buttonEchelle_clicked();

    void on_dateTimeEditXmin_editingFinished();

    void on_dateTimeEditXmax_editingFinished();

    void on_doubleSpinBoxYmin_editingFinished();

    void on_doubleSpinBoxYmax_editingFinished();

    void on_doubleSpinBoxPasY_editingFinished();

    void on_doubleSpinBoxMarquageY_editingFinished();

    void on_comboBoxIntervalleX_currentIndexChanged(int index);

    void on_dateTimeDate_editingFinished();

    void on_checkBoxHidePoint_toggled(bool checked);

    void selectionChanged_listView();

private:
    Ui::MainWindow *ui;

    Stations *modelStation;
    Parametres *modelParametre;
    Groupes *modelGroupe;
    ConfigScene *configScene;
    ConfigEchelle *configEchelle;
    Scene *scene;
    FullScreen *fullscreen;

    ConfigTest *configTest;
    GroupeEdit *groupeEdit;
    GroupeAdd *groupeAdd;
    Legende *legende;
    AideAjoutGroupe *aideAG;
    AideEditGroupe *aideEG;
    AideSupprGroupe *aideSG;
    AideParametreTest *aidePT;
    AideGraph *aideG;

    Xml *gestionXml;

    Csv *csv;
    GestionDate *date;

    void init_listViewParametre();
    void init_listViewStation();
    void init_treeViewGroupe();
    void init_scene();
    void init_textEditDonneInvalide(QList<QStandardItem*> *donneInvalide);
    void removeGras();
    void addGras(QStandardItemModel *model, QStringList listDonne);
};

#endif // MAINWINDOW_H
