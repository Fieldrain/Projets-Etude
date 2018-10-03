/********************************************************************************
** Form generated from reading UI file 'configtest.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGTEST_H
#define UI_CONFIGTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigTest
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QListView *listViewConfigTest;
    QLabel *label;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxParametre;
    QCheckBox *checkBoxValeur;
    QComboBox *comboBoxIntervalle;
    QCheckBox *checkBoxIntervalle;
    QSpinBox *spinBoxIntervalle;
    QGridLayout *gridLayout_4;
    QComboBox *comboBoxFirstOperande;
    QComboBox *comboBoxOperation;
    QLabel *label_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *doubleSpinBoxValeur;
    QComboBox *comboBoxType;
    QComboBox *comboBoxParametre;
    QLabel *label_3;
    QTableWidget *tableValeurstest;
    QLabel *label_4;
    QGridLayout *gridLayout_5;
    QPushButton *buttonAjouterParametre;
    QPushButton *buttonModifierParametre;
    QDialogButtonBox *buttonBox;
    QPushButton *buttonAnnuler;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *ConfigTest)
    {
        if (ConfigTest->objectName().isEmpty())
            ConfigTest->setObjectName(QStringLiteral("ConfigTest"));
        ConfigTest->setWindowModality(Qt::ApplicationModal);
        ConfigTest->resize(687, 563);
        horizontalLayout = new QHBoxLayout(ConfigTest);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listViewConfigTest = new QListView(ConfigTest);
        listViewConfigTest->setObjectName(QStringLiteral("listViewConfigTest"));

        gridLayout->addWidget(listViewConfigTest, 1, 0, 1, 1);

        label = new QLabel(ConfigTest);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        checkBoxParametre = new QCheckBox(ConfigTest);
        checkBoxParametre->setObjectName(QStringLiteral("checkBoxParametre"));

        gridLayout_2->addWidget(checkBoxParametre, 0, 0, 1, 1);

        checkBoxValeur = new QCheckBox(ConfigTest);
        checkBoxValeur->setObjectName(QStringLiteral("checkBoxValeur"));

        gridLayout_2->addWidget(checkBoxValeur, 1, 0, 1, 1);

        comboBoxIntervalle = new QComboBox(ConfigTest);
        comboBoxIntervalle->setObjectName(QStringLiteral("comboBoxIntervalle"));

        gridLayout_2->addWidget(comboBoxIntervalle, 2, 2, 1, 1);

        checkBoxIntervalle = new QCheckBox(ConfigTest);
        checkBoxIntervalle->setObjectName(QStringLiteral("checkBoxIntervalle"));

        gridLayout_2->addWidget(checkBoxIntervalle, 2, 0, 1, 1);

        spinBoxIntervalle = new QSpinBox(ConfigTest);
        spinBoxIntervalle->setObjectName(QStringLiteral("spinBoxIntervalle"));

        gridLayout_2->addWidget(spinBoxIntervalle, 2, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 2, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        comboBoxFirstOperande = new QComboBox(ConfigTest);
        comboBoxFirstOperande->setObjectName(QStringLiteral("comboBoxFirstOperande"));
        comboBoxFirstOperande->setMinimumSize(QSize(256, 0));
        comboBoxFirstOperande->setEditable(false);
        comboBoxFirstOperande->setMaxVisibleItems(5);

        gridLayout_4->addWidget(comboBoxFirstOperande, 0, 0, 1, 1);

        comboBoxOperation = new QComboBox(ConfigTest);
        comboBoxOperation->setObjectName(QStringLiteral("comboBoxOperation"));
        comboBoxOperation->setMinimumSize(QSize(256, 0));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        comboBoxOperation->setFont(font);
        comboBoxOperation->setLayoutDirection(Qt::LeftToRight);
        comboBoxOperation->setEditable(false);

        gridLayout_4->addWidget(comboBoxOperation, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 1, 1, 1, 1);

        label_2 = new QLabel(ConfigTest);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_7->addWidget(label_2, 0, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        doubleSpinBoxValeur = new QDoubleSpinBox(ConfigTest);
        doubleSpinBoxValeur->setObjectName(QStringLiteral("doubleSpinBoxValeur"));
        doubleSpinBoxValeur->setEnabled(false);
        doubleSpinBoxValeur->setMinimum(-1000);
        doubleSpinBoxValeur->setMaximum(1000);

        gridLayout_3->addWidget(doubleSpinBoxValeur, 1, 0, 1, 1);

        comboBoxType = new QComboBox(ConfigTest);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));

        gridLayout_3->addWidget(comboBoxType, 5, 0, 1, 1);

        comboBoxParametre = new QComboBox(ConfigTest);
        comboBoxParametre->setObjectName(QStringLiteral("comboBoxParametre"));
        comboBoxParametre->setEnabled(false);
        comboBoxParametre->setEditable(false);
        comboBoxParametre->setMaxVisibleItems(5);

        gridLayout_3->addWidget(comboBoxParametre, 0, 0, 1, 1);

        label_3 = new QLabel(ConfigTest);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 4, 0, 1, 1);

        tableValeurstest = new QTableWidget(ConfigTest);
        if (tableValeurstest->columnCount() < 3)
            tableValeurstest->setColumnCount(3);
        tableValeurstest->setObjectName(QStringLiteral("tableValeurstest"));
        tableValeurstest->setEnabled(true);
        tableValeurstest->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableValeurstest->setSelectionMode(QAbstractItemView::NoSelection);
        tableValeurstest->setColumnCount(3);
        tableValeurstest->horizontalHeader()->setDefaultSectionSize(115);
        tableValeurstest->horizontalHeader()->setMinimumSectionSize(115);

        gridLayout_3->addWidget(tableValeurstest, 3, 0, 1, 1);

        label_4 = new QLabel(ConfigTest);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        buttonAjouterParametre = new QPushButton(ConfigTest);
        buttonAjouterParametre->setObjectName(QStringLiteral("buttonAjouterParametre"));
        buttonAjouterParametre->setEnabled(false);

        gridLayout_5->addWidget(buttonAjouterParametre, 0, 0, 1, 1);

        buttonModifierParametre = new QPushButton(ConfigTest);
        buttonModifierParametre->setObjectName(QStringLiteral("buttonModifierParametre"));
        buttonModifierParametre->setEnabled(false);

        gridLayout_5->addWidget(buttonModifierParametre, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ConfigTest);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout_5->addWidget(buttonBox, 1, 2, 1, 1);

        buttonAnnuler = new QPushButton(ConfigTest);
        buttonAnnuler->setObjectName(QStringLiteral("buttonAnnuler"));

        gridLayout_5->addWidget(buttonAnnuler, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 2, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_7);


        retranslateUi(ConfigTest);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigTest, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigTest, SLOT(reject()));

        comboBoxOperation->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigTest);
    } // setupUi

    void retranslateUi(QDialog *ConfigTest)
    {
        ConfigTest->setWindowTitle(QApplication::translate("ConfigTest", "Configuration des tests", 0));
        label->setText(QApplication::translate("ConfigTest", "Param\303\250tres de test actuel", 0));
        checkBoxParametre->setText(QApplication::translate("ConfigTest", "Param\303\250tre", 0));
        checkBoxValeur->setText(QApplication::translate("ConfigTest", "Valeur", 0));
        comboBoxIntervalle->clear();
        comboBoxIntervalle->insertItems(0, QStringList()
         << QApplication::translate("ConfigTest", "min", 0)
         << QApplication::translate("ConfigTest", "heure", 0)
        );
        checkBoxIntervalle->setText(QApplication::translate("ConfigTest", "Intervalle", 0));
        comboBoxFirstOperande->clear();
        comboBoxFirstOperande->insertItems(0, QStringList()
         << QApplication::translate("ConfigTest", "Tous", 0)
        );
        comboBoxOperation->clear();
        comboBoxOperation->insertItems(0, QStringList()
         << QApplication::translate("ConfigTest", "Sup", 0)
         << QApplication::translate("ConfigTest", "Inf", 0)
         << QApplication::translate("ConfigTest", "=", 0)
         << QApplication::translate("ConfigTest", "Sup ou =", 0)
         << QApplication::translate("ConfigTest", "Inf ou =", 0)
         << QApplication::translate("ConfigTest", "Sup et Inf", 0)
         << QApplication::translate("ConfigTest", "Sans", 0)
        );
        label_2->setText(QApplication::translate("ConfigTest", "Nouveau param\303\250tre de test", 0));
        comboBoxType->clear();
        comboBoxType->insertItems(0, QStringList()
         << QApplication::translate("ConfigTest", "Remarque", 0)
         << QApplication::translate("ConfigTest", "Correction", 0)
         << QApplication::translate("ConfigTest", "Invalide", 0)
        );
        comboBoxParametre->clear();
        comboBoxParametre->insertItems(0, QStringList()
         << QApplication::translate("ConfigTest", "Tous", 0)
        );
        label_3->setText(QApplication::translate("ConfigTest", "Type :", 0));
        label_4->setText(QApplication::translate("ConfigTest", "Liste des valeurs du test", 0));
        buttonAjouterParametre->setText(QApplication::translate("ConfigTest", "Ajouter param\303\250tre", 0));
        buttonModifierParametre->setText(QApplication::translate("ConfigTest", "Modifier param\303\250tre", 0));
        buttonAnnuler->setText(QApplication::translate("ConfigTest", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigTest: public Ui_ConfigTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGTEST_H
