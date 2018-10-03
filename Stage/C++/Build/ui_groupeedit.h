/********************************************************************************
** Form generated from reading UI file 'groupeedit.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPEEDIT_H
#define UI_GROUPEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupeEdit
{
public:
    QGridLayout *gridLayout_2;
    QListView *listViewCur;
    QListView *listViewEle;
    QGridLayout *gridLayout;
    QPushButton *buttonEdit;
    QPushButton *buttonAnnuler;

    void setupUi(QWidget *GroupeEdit)
    {
        if (GroupeEdit->objectName().isEmpty())
            GroupeEdit->setObjectName(QStringLiteral("GroupeEdit"));
        GroupeEdit->setWindowModality(Qt::ApplicationModal);
        GroupeEdit->resize(388, 503);
        gridLayout_2 = new QGridLayout(GroupeEdit);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listViewCur = new QListView(GroupeEdit);
        listViewCur->setObjectName(QStringLiteral("listViewCur"));

        gridLayout_2->addWidget(listViewCur, 0, 0, 1, 1);

        listViewEle = new QListView(GroupeEdit);
        listViewEle->setObjectName(QStringLiteral("listViewEle"));

        gridLayout_2->addWidget(listViewEle, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonEdit = new QPushButton(GroupeEdit);
        buttonEdit->setObjectName(QStringLiteral("buttonEdit"));

        gridLayout->addWidget(buttonEdit, 0, 1, 1, 1);

        buttonAnnuler = new QPushButton(GroupeEdit);
        buttonAnnuler->setObjectName(QStringLiteral("buttonAnnuler"));

        gridLayout->addWidget(buttonAnnuler, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);


        retranslateUi(GroupeEdit);

        QMetaObject::connectSlotsByName(GroupeEdit);
    } // setupUi

    void retranslateUi(QWidget *GroupeEdit)
    {
        GroupeEdit->setWindowTitle(QApplication::translate("GroupeEdit", "Edition Groupe", 0));
        buttonEdit->setText(QApplication::translate("GroupeEdit", "Editer Groupe", 0));
        buttonAnnuler->setText(QApplication::translate("GroupeEdit", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupeEdit: public Ui_GroupeEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEEDIT_H
