/********************************************************************************
** Form generated from reading UI file 'groupeadd.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPEADD_H
#define UI_GROUPEADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupeAdd
{
public:
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLabel *labelGroupe;
    QListView *listViewGroupe;
    QCheckBox *checkBoxGroupe;
    QGridLayout *gridLayout_4;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QCheckBox *checkBoxNom;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *labelStations;
    QListView *listViewStations;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *labelParametre;
    QListView *listViewParametres;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_8;
    QPushButton *buttonCreer;
    QPushButton *buttonAnnuler;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *GroupeAdd)
    {
        if (GroupeAdd->objectName().isEmpty())
            GroupeAdd->setObjectName(QStringLiteral("GroupeAdd"));
        GroupeAdd->setWindowModality(Qt::ApplicationModal);
        GroupeAdd->resize(916, 535);
        gridLayout_10 = new QGridLayout(GroupeAdd);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        verticalSpacer = new QSpacerItem(833, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        labelGroupe = new QLabel(GroupeAdd);
        labelGroupe->setObjectName(QStringLiteral("labelGroupe"));

        gridLayout_5->addWidget(labelGroupe, 0, 0, 1, 1);

        listViewGroupe = new QListView(GroupeAdd);
        listViewGroupe->setObjectName(QStringLiteral("listViewGroupe"));
        listViewGroupe->setEnabled(true);
        listViewGroupe->setMinimumSize(QSize(0, 350));

        gridLayout_5->addWidget(listViewGroupe, 1, 0, 1, 1);

        checkBoxGroupe = new QCheckBox(GroupeAdd);
        checkBoxGroupe->setObjectName(QStringLiteral("checkBoxGroupe"));

        gridLayout_5->addWidget(checkBoxGroupe, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        labelNom = new QLabel(GroupeAdd);
        labelNom->setObjectName(QStringLiteral("labelNom"));

        gridLayout_4->addWidget(labelNom, 0, 0, 1, 1);

        lineEditNom = new QLineEdit(GroupeAdd);
        lineEditNom->setObjectName(QStringLiteral("lineEditNom"));
        lineEditNom->setReadOnly(true);

        gridLayout_4->addWidget(lineEditNom, 1, 0, 1, 1);

        checkBoxNom = new QCheckBox(GroupeAdd);
        checkBoxNom->setObjectName(QStringLiteral("checkBoxNom"));

        gridLayout_4->addWidget(checkBoxNom, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelStations = new QLabel(GroupeAdd);
        labelStations->setObjectName(QStringLiteral("labelStations"));

        gridLayout->addWidget(labelStations, 0, 0, 1, 1);

        listViewStations = new QListView(GroupeAdd);
        listViewStations->setObjectName(QStringLiteral("listViewStations"));
        listViewStations->setMinimumSize(QSize(0, 400));
        listViewStations->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(listViewStations, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelParametre = new QLabel(GroupeAdd);
        labelParametre->setObjectName(QStringLiteral("labelParametre"));

        gridLayout_2->addWidget(labelParametre, 0, 0, 1, 1);

        listViewParametres = new QListView(GroupeAdd);
        listViewParametres->setObjectName(QStringLiteral("listViewParametres"));
        listViewParametres->setMinimumSize(QSize(0, 400));
        listViewParametres->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(listViewParametres, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 3, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 1, 1, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        buttonCreer = new QPushButton(GroupeAdd);
        buttonCreer->setObjectName(QStringLiteral("buttonCreer"));

        gridLayout_8->addWidget(buttonCreer, 0, 1, 1, 1);

        buttonAnnuler = new QPushButton(GroupeAdd);
        buttonAnnuler->setObjectName(QStringLiteral("buttonAnnuler"));

        gridLayout_8->addWidget(buttonAnnuler, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(833, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 4, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 0, 1, 1);


        retranslateUi(GroupeAdd);

        QMetaObject::connectSlotsByName(GroupeAdd);
    } // setupUi

    void retranslateUi(QWidget *GroupeAdd)
    {
        GroupeAdd->setWindowTitle(QApplication::translate("GroupeAdd", "Creation Groupe", 0));
        labelGroupe->setText(QApplication::translate("GroupeAdd", "Groupe", 0));
        checkBoxGroupe->setText(QApplication::translate("GroupeAdd", "Valider", 0));
        labelNom->setText(QApplication::translate("GroupeAdd", "Nom", 0));
        checkBoxNom->setText(QApplication::translate("GroupeAdd", "Valider", 0));
        labelStations->setText(QApplication::translate("GroupeAdd", "Stations", 0));
        labelParametre->setText(QApplication::translate("GroupeAdd", "Param\303\250tres", 0));
        buttonCreer->setText(QApplication::translate("GroupeAdd", "Cr\303\251er groupe", 0));
        buttonAnnuler->setText(QApplication::translate("GroupeAdd", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupeAdd: public Ui_GroupeAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEADD_H
