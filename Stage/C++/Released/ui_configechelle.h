/********************************************************************************
** Form generated from reading UI file 'configechelle.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGECHELLE_H
#define UI_CONFIGECHELLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigEchelle
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxRef;
    QTableView *tableViewEchelles;
    QGridLayout *gridLayout_2;
    QPushButton *buttonValider;
    QPushButton *buttonAnnuler;

    void setupUi(QWidget *ConfigEchelle)
    {
        if (ConfigEchelle->objectName().isEmpty())
            ConfigEchelle->setObjectName(QStringLiteral("ConfigEchelle"));
        ConfigEchelle->setWindowModality(Qt::ApplicationModal);
        ConfigEchelle->resize(314, 421);
        gridLayout_3 = new QGridLayout(ConfigEchelle);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ConfigEchelle);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxRef = new QComboBox(ConfigEchelle);
        comboBoxRef->setObjectName(QStringLiteral("comboBoxRef"));

        gridLayout->addWidget(comboBoxRef, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        tableViewEchelles = new QTableView(ConfigEchelle);
        tableViewEchelles->setObjectName(QStringLiteral("tableViewEchelles"));

        gridLayout_3->addWidget(tableViewEchelles, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonValider = new QPushButton(ConfigEchelle);
        buttonValider->setObjectName(QStringLiteral("buttonValider"));

        gridLayout_2->addWidget(buttonValider, 0, 1, 1, 1);

        buttonAnnuler = new QPushButton(ConfigEchelle);
        buttonAnnuler->setObjectName(QStringLiteral("buttonAnnuler"));

        gridLayout_2->addWidget(buttonAnnuler, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 1);


        retranslateUi(ConfigEchelle);

        QMetaObject::connectSlotsByName(ConfigEchelle);
    } // setupUi

    void retranslateUi(QWidget *ConfigEchelle)
    {
        ConfigEchelle->setWindowTitle(QApplication::translate("ConfigEchelle", "Configuration Echelles", 0));
        label->setText(QApplication::translate("ConfigEchelle", "R\303\251f\303\251rent :", 0));
        buttonValider->setText(QApplication::translate("ConfigEchelle", "Valider", 0));
        buttonAnnuler->setText(QApplication::translate("ConfigEchelle", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigEchelle: public Ui_ConfigEchelle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGECHELLE_H
