/********************************************************************************
** Form generated from reading UI file 'aideparametretest.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDEPARAMETRETEST_H
#define UI_AIDEPARAMETRETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AideParametreTest
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *AideParametreTest)
    {
        if (AideParametreTest->objectName().isEmpty())
            AideParametreTest->setObjectName(QStringLiteral("AideParametreTest"));
        AideParametreTest->setWindowModality(Qt::ApplicationModal);
        AideParametreTest->resize(800, 600);
        gridLayout = new QGridLayout(AideParametreTest);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(AideParametreTest);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(AideParametreTest);

        QMetaObject::connectSlotsByName(AideParametreTest);
    } // setupUi

    void retranslateUi(QWidget *AideParametreTest)
    {
        AideParametreTest->setWindowTitle(QApplication::translate("AideParametreTest", "Aide Configuration Param\303\250tre Test", 0));
        textEdit->setHtml(QApplication::translate("AideParametreTest", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pour ajouter ou modifier les param\303\250tres de test vous pouvez le faire \303\240 l'ouverture d'un fichier ou en allant dans configuration -&gt; Param\303\250tre de test.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">ATTENTION</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Pour valider toutes les modifications apport\303\251es aux tests il faut cliquer sur le bouton &quot;OK&quot; en bas \303\240 gauche.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">Ajouter un param\303\250tre de test :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	a. S\303\251lectionner le param\303\250tre qui sera celui sur lequel le test sera effectu\303\251.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	b. S\303\251lectionner l'op\303\251ration \303\240 appliquer.</p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Sup : sup\303\251rieur \303\240,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Inf : inf\303\251rieur \303\240,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		= : \303\251gale \303\240,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Sup ou = : sup\303\251rieur ou \303\251gale \303\240,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Inf ou = : inf\303\251rieur ou \303\251gale \303\240,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Sup et Inf : sup\303\251rieur \303\240  et inf"
                        "\303\251rieur \303\240,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Sans : utilisable uniquement avec un autre param\303\250tre par exemple NO sans NO2</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	c. Choissisez le type du second \303\251l\303\251ment de la comparaison (Valeur ou Param\303\250tre).</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Pour Sup ou = ,Inf ou = ,Sup et Inf on peut avoir le premier \303\251l\303\251ment qui est une valeur et l'autre un param\303\250tre et inversement.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;"
                        " -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	d. Choissisez le param\303\250tre ou entrer les valeurs pour la comparaison.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	e. Cliquer sur &quot;Valider ?&quot; pour confirmer la valeur.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	f. Cliquer sur &quot;Ajouter param\303\250tre&quot;.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px;"
                        " margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">Modifier un param\303\250tre de test :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	a. Cliquer sur le param\303\250tre de test dans la liste. Puis \303\240 la fin de la modification cliquer sur &quot;Modifier param\303\250tre&quot;.</p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">Supprimer un param\303\250tre de test :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	a. Double cliquer sur le param\303\250tre de test dans la liste.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AideParametreTest: public Ui_AideParametreTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDEPARAMETRETEST_H
