/********************************************************************************
** Form generated from reading UI file 'aideajoutgroupe.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDEAJOUTGROUPE_H
#define UI_AIDEAJOUTGROUPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AideAjoutGroupe
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *AideAjoutGroupe)
    {
        if (AideAjoutGroupe->objectName().isEmpty())
            AideAjoutGroupe->setObjectName(QStringLiteral("AideAjoutGroupe"));
        AideAjoutGroupe->setWindowModality(Qt::ApplicationModal);
        AideAjoutGroupe->resize(800, 600);
        gridLayout = new QGridLayout(AideAjoutGroupe);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(AideAjoutGroupe);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(AideAjoutGroupe);

        QMetaObject::connectSlotsByName(AideAjoutGroupe);
    } // setupUi

    void retranslateUi(QWidget *AideAjoutGroupe)
    {
        AideAjoutGroupe->setWindowTitle(QApplication::translate("AideAjoutGroupe", "Aide Ajout Groupe", 0));
        textEdit->setHtml(QApplication::translate("AideAjoutGroupe", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Il existe deux fa\303\247ons diff\303\251rentes pour ajouter un groupe.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\"> 1</span><span style=\" font-size:large; font-weight:600; vertical-align:super;\">re</span><span style=\" font-size:large; font-weight:600;\"> m\303\251thode d'ajout :</span></p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	a. S\303"
                        "\251lectionner la station ou le param\303\250tre  qui correspondra au nom du groupe.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	b. S\303\251lectionner les param\303\250tres ou les stations qui composeront votre groupe.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	c. Apr\303\250s avoir effectu\303\251 les s\303\251lections cliquer sur le bouton &quot;Ajouter Groupe&quot;.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	d. Valider les composantes du groupe en cliquant sur les carr\303\251s puis cliquer sur &quot;Creer Groupe&quot;.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\"> 2</span><span style=\" font-size:large; font-w"
                        "eight:600; vertical-align:super;\">\303\250</span><span style=\" font-size:large; font-weight:600;\"> m\303\251thode d'ajout :</span></p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	a. Cliquer sur le bouton &quot;Ajouter Groupe&quot;.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	b. S\303\251lectionner dans la liste des param\303\250tres et des stations le nom du futur groupe puis cliquer sur le carr\303\251 pour valider.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	c. S\303\251lectionner dans la liste encore active les \303\251l\303\251ments qui constitueront le futur groupe puis cliquer sur le carr\303\251 pour valider.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	d. Une"
                        " fois les deux parties valider cliquer sur &quot;Creer groupe&quot;.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Nb :</span></p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	- En cliquant sur un \303\251l\303\251ment qui est dans la cellule groupe vous l'enlevez de celle-ci.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	- Si le nom du groupe passe d'une station \303\240 un param\303\250tre ou inversement cela vide la cellule groupe.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AideAjoutGroupe: public Ui_AideAjoutGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDEAJOUTGROUPE_H
