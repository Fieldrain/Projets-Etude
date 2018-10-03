/********************************************************************************
** Form generated from reading UI file 'emplacementxml.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLACEMENTXML_H
#define UI_EMPLACEMENTXML_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmplacementXml
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGridLayout *gridLayout_2;
    QPushButton *buttonValider;
    QCheckBox *checkBoxEnregistrer;
    QPushButton *buttonAnnuler;

    void setupUi(QWidget *EmplacementXml)
    {
        if (EmplacementXml->objectName().isEmpty())
            EmplacementXml->setObjectName(QStringLiteral("EmplacementXml"));
        EmplacementXml->setWindowModality(Qt::ApplicationModal);
        EmplacementXml->resize(477, 92);
        gridLayout_3 = new QGridLayout(EmplacementXml);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(EmplacementXml);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(EmplacementXml);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(false);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(EmplacementXml);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonValider = new QPushButton(EmplacementXml);
        buttonValider->setObjectName(QStringLiteral("buttonValider"));

        gridLayout_2->addWidget(buttonValider, 0, 2, 1, 1);

        checkBoxEnregistrer = new QCheckBox(EmplacementXml);
        checkBoxEnregistrer->setObjectName(QStringLiteral("checkBoxEnregistrer"));

        gridLayout_2->addWidget(checkBoxEnregistrer, 0, 0, 1, 1);

        buttonAnnuler = new QPushButton(EmplacementXml);
        buttonAnnuler->setObjectName(QStringLiteral("buttonAnnuler"));

        gridLayout_2->addWidget(buttonAnnuler, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(EmplacementXml);

        QMetaObject::connectSlotsByName(EmplacementXml);
    } // setupUi

    void retranslateUi(QWidget *EmplacementXml)
    {
        EmplacementXml->setWindowTitle(QApplication::translate("EmplacementXml", "XML", 0));
        label->setText(QApplication::translate("EmplacementXml", "Emplacement XML :", 0));
        pushButton->setText(QApplication::translate("EmplacementXml", "Parcourir", 0));
        buttonValider->setText(QApplication::translate("EmplacementXml", "OK", 0));
        checkBoxEnregistrer->setText(QApplication::translate("EmplacementXml", "Enregistrer Emplacement", 0));
        buttonAnnuler->setText(QApplication::translate("EmplacementXml", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class EmplacementXml: public Ui_EmplacementXml {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLACEMENTXML_H
