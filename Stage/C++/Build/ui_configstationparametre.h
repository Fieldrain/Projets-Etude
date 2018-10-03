/********************************************************************************
** Form generated from reading UI file 'configstationparametre.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGSTATIONPARAMETRE_H
#define UI_CONFIGSTATIONPARAMETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConfigStationParametre
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QListView *listViewNouveaux;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QComboBox *comboBoxCategorie;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *lineEditNom;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QLineEdit *lineEditNewCategorie;
    QPushButton *buttonValiderCategorie;
    QPushButton *buttonFin;

    void setupUi(QDialog *ConfigStationParametre)
    {
        if (ConfigStationParametre->objectName().isEmpty())
            ConfigStationParametre->setObjectName(QStringLiteral("ConfigStationParametre"));
        ConfigStationParametre->setWindowModality(Qt::ApplicationModal);
        ConfigStationParametre->resize(495, 531);
        gridLayout_3 = new QGridLayout(ConfigStationParametre);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ConfigStationParametre);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listViewNouveaux = new QListView(ConfigStationParametre);
        listViewNouveaux->setObjectName(QStringLiteral("listViewNouveaux"));

        gridLayout->addWidget(listViewNouveaux, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 2, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(ConfigStationParametre);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 3, 0, 1, 1);

        comboBoxCategorie = new QComboBox(ConfigStationParametre);
        comboBoxCategorie->setObjectName(QStringLiteral("comboBoxCategorie"));

        gridLayout_2->addWidget(comboBoxCategorie, 5, 0, 1, 1);

        label_3 = new QLabel(ConfigStationParametre);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 6, 0, 1, 1);

        lineEditNom = new QLineEdit(ConfigStationParametre);
        lineEditNom->setObjectName(QStringLiteral("lineEditNom"));
        lineEditNom->setReadOnly(true);

        gridLayout_2->addWidget(lineEditNom, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        label_4 = new QLabel(ConfigStationParametre);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 7, 0, 1, 1);

        lineEditNewCategorie = new QLineEdit(ConfigStationParametre);
        lineEditNewCategorie->setObjectName(QStringLiteral("lineEditNewCategorie"));

        gridLayout_2->addWidget(lineEditNewCategorie, 8, 0, 1, 1);

        buttonValiderCategorie = new QPushButton(ConfigStationParametre);
        buttonValiderCategorie->setObjectName(QStringLiteral("buttonValiderCategorie"));

        gridLayout_2->addWidget(buttonValiderCategorie, 11, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 2, 1, 1);

        buttonFin = new QPushButton(ConfigStationParametre);
        buttonFin->setObjectName(QStringLiteral("buttonFin"));

        gridLayout_3->addWidget(buttonFin, 2, 2, 1, 1);


        retranslateUi(ConfigStationParametre);

        QMetaObject::connectSlotsByName(ConfigStationParametre);
    } // setupUi

    void retranslateUi(QDialog *ConfigStationParametre)
    {
        ConfigStationParametre->setWindowTitle(QApplication::translate("ConfigStationParametre", "Configuration Nouveaux Elements", 0));
        label->setText(QApplication::translate("ConfigStationParametre", "Nouveaux Param\303\250tres/Stations", 0));
        label_2->setText(QApplication::translate("ConfigStationParametre", "Nom", 0));
        label_3->setText(QApplication::translate("ConfigStationParametre", "Cat\303\251gorie", 0));
        label_4->setText(QApplication::translate("ConfigStationParametre", "Ajouter Categorie", 0));
        buttonValiderCategorie->setText(QApplication::translate("ConfigStationParametre", "Valider la cat\303\251gorie", 0));
        buttonFin->setText(QApplication::translate("ConfigStationParametre", "Fin", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigStationParametre: public Ui_ConfigStationParametre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGSTATIONPARAMETRE_H
