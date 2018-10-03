/********************************************************************************
** Form generated from reading UI file 'parametretest.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRETEST_H
#define UI_PARAMETRETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParametreTest
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label;
    QListView *listViewParametreTest;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButtonParametre;
    QRadioButton *radioButtonValeur;
    QRadioButton *radioButtonDate;
    QComboBox *comboBoxOperation;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QComboBox *comboBoxFirstOperande;
    QGridLayout *gridLayout_3;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *comboBoxParametre;
    QPushButton *buttonAjouterParametre;
    QSpacerItem *verticalSpacer_5;
    QPushButton *buttonModifierParametre;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxValeur;
    QDateTimeEdit *dateTimeEditIntervalle;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonValider;

    void setupUi(QWidget *ParametreTest)
    {
        if (ParametreTest->objectName().isEmpty())
            ParametreTest->setObjectName(QStringLiteral("ParametreTest"));
        ParametreTest->resize(703, 513);
        gridLayout_5 = new QGridLayout(ParametreTest);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ParametreTest);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listViewParametreTest = new QListView(ParametreTest);
        listViewParametreTest->setObjectName(QStringLiteral("listViewParametreTest"));

        gridLayout->addWidget(listViewParametreTest, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 2, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 3, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 5, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButtonParametre = new QRadioButton(ParametreTest);
        radioButtonParametre->setObjectName(QStringLiteral("radioButtonParametre"));

        gridLayout_2->addWidget(radioButtonParametre, 0, 0, 1, 1);

        radioButtonValeur = new QRadioButton(ParametreTest);
        radioButtonValeur->setObjectName(QStringLiteral("radioButtonValeur"));

        gridLayout_2->addWidget(radioButtonValeur, 1, 0, 1, 1);

        radioButtonDate = new QRadioButton(ParametreTest);
        radioButtonDate->setObjectName(QStringLiteral("radioButtonDate"));

        gridLayout_2->addWidget(radioButtonDate, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 6, 0, 1, 2);

        comboBoxOperation = new QComboBox(ParametreTest);
        comboBoxOperation->setObjectName(QStringLiteral("comboBoxOperation"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        comboBoxOperation->setFont(font);
        comboBoxOperation->setLayoutDirection(Qt::LeftToRight);
        comboBoxOperation->setEditable(false);

        gridLayout_4->addWidget(comboBoxOperation, 4, 0, 1, 2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 7, 0, 1, 1);

        comboBoxFirstOperande = new QComboBox(ParametreTest);
        comboBoxFirstOperande->setObjectName(QStringLiteral("comboBoxFirstOperande"));
        comboBoxFirstOperande->setEditable(false);
        comboBoxFirstOperande->setMaxVisibleItems(5);

        gridLayout_4->addWidget(comboBoxFirstOperande, 2, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        dateTimeEdit = new QDateTimeEdit(ParametreTest);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);

        gridLayout_3->addWidget(dateTimeEdit, 2, 0, 1, 1);

        comboBoxParametre = new QComboBox(ParametreTest);
        comboBoxParametre->setObjectName(QStringLiteral("comboBoxParametre"));
        comboBoxParametre->setEnabled(false);
        comboBoxParametre->setEditable(false);
        comboBoxParametre->setMaxVisibleItems(5);

        gridLayout_3->addWidget(comboBoxParametre, 0, 0, 1, 1);

        buttonAjouterParametre = new QPushButton(ParametreTest);
        buttonAjouterParametre->setObjectName(QStringLiteral("buttonAjouterParametre"));
        buttonAjouterParametre->setEnabled(false);

        gridLayout_3->addWidget(buttonAjouterParametre, 6, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 5, 0, 1, 1);

        buttonModifierParametre = new QPushButton(ParametreTest);
        buttonModifierParametre->setObjectName(QStringLiteral("buttonModifierParametre"));
        buttonModifierParametre->setEnabled(false);

        gridLayout_3->addWidget(buttonModifierParametre, 7, 0, 1, 1);

        label_3 = new QLabel(ParametreTest);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBoxValeur = new QDoubleSpinBox(ParametreTest);
        doubleSpinBoxValeur->setObjectName(QStringLiteral("doubleSpinBoxValeur"));
        doubleSpinBoxValeur->setEnabled(false);
        doubleSpinBoxValeur->setMinimum(-10000);
        doubleSpinBoxValeur->setMaximum(10000);

        gridLayout_3->addWidget(doubleSpinBoxValeur, 1, 0, 1, 1);

        dateTimeEditIntervalle = new QDateTimeEdit(ParametreTest);
        dateTimeEditIntervalle->setObjectName(QStringLiteral("dateTimeEditIntervalle"));
        dateTimeEditIntervalle->setEnabled(false);

        gridLayout_3->addWidget(dateTimeEditIntervalle, 4, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 8, 0, 1, 2);

        label_2 = new QLabel(ParametreTest);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 2, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        buttonValider = new QPushButton(ParametreTest);
        buttonValider->setObjectName(QStringLiteral("buttonValider"));

        gridLayout_5->addWidget(buttonValider, 1, 4, 1, 1);


        retranslateUi(ParametreTest);

        comboBoxOperation->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ParametreTest);
    } // setupUi

    void retranslateUi(QWidget *ParametreTest)
    {
        ParametreTest->setWindowTitle(QApplication::translate("ParametreTest", "Param\303\250tre de Tests", 0));
        label->setText(QApplication::translate("ParametreTest", "Param\303\250tres de test actuel", 0));
        radioButtonParametre->setText(QApplication::translate("ParametreTest", "Param\303\250tre", 0));
        radioButtonValeur->setText(QApplication::translate("ParametreTest", "Valeur", 0));
        radioButtonDate->setText(QApplication::translate("ParametreTest", "Date", 0));
        comboBoxOperation->clear();
        comboBoxOperation->insertItems(0, QStringList()
         << QApplication::translate("ParametreTest", "Sup", 0)
         << QApplication::translate("ParametreTest", "Inf", 0)
         << QApplication::translate("ParametreTest", "=", 0)
         << QApplication::translate("ParametreTest", "Sans", 0)
         << QApplication::translate("ParametreTest", "Min", 0)
         << QApplication::translate("ParametreTest", "Max", 0)
        );
        comboBoxFirstOperande->clear();
        comboBoxFirstOperande->insertItems(0, QStringList()
         << QApplication::translate("ParametreTest", "Tous", 0)
        );
        dateTimeEdit->setDisplayFormat(QApplication::translate("ParametreTest", "yyyy-MM-dd hh:mm:ss", 0));
        comboBoxParametre->clear();
        comboBoxParametre->insertItems(0, QStringList()
         << QApplication::translate("ParametreTest", "Tous", 0)
        );
        buttonAjouterParametre->setText(QApplication::translate("ParametreTest", "Ajouter param\303\250tre", 0));
        buttonModifierParametre->setText(QApplication::translate("ParametreTest", "Modifier param\303\250tre", 0));
        label_3->setText(QApplication::translate("ParametreTest", "Intervalle", 0));
        dateTimeEditIntervalle->setDisplayFormat(QApplication::translate("ParametreTest", "yyyy-MM-dd hh:mm:ss", 0));
        label_2->setText(QApplication::translate("ParametreTest", "Nouveau param\303\250tre de test", 0));
        buttonValider->setText(QApplication::translate("ParametreTest", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class ParametreTest: public Ui_ParametreTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRETEST_H
