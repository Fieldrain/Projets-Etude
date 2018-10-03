#ifndef CONFIGECHELLE_H
#define CONFIGECHELLE_H

#include <QDialog>
#include <QStandardItem>
#include <QKeyEvent>

#include "Core/vue.h"
#include "Core/scene.h"
#include "Core/configscene.h"

namespace Ui {
class ConfigEchelle;
}

class ConfigEchelle : public QDialog, public Vue
{
    Q_OBJECT

public:
    explicit ConfigEchelle(QWidget *parent = 0);
    ConfigEchelle(Scene *s,ConfigScene *c,QWidget *parent = 0);
    ~ConfigEchelle();

    void refresh();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_buttonValider_clicked();

    void on_comboBoxRef_currentIndexChanged(int index);

    void on_buttonAnnuler_clicked();

private:
    Ui::ConfigEchelle *ui;
    Scene *scene;
    ConfigScene *configScene;
    QStringList listUnite;

    void init_comboBox();
    void init_table();
};

#endif // CONFIGECHELLE_H
