/********************************************************************************
** Form generated from reading UI file 'aidegraph.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDEGRAPH_H
#define UI_AIDEGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AideGraph
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *AideGraph)
    {
        if (AideGraph->objectName().isEmpty())
            AideGraph->setObjectName(QStringLiteral("AideGraph"));
        AideGraph->setWindowModality(Qt::ApplicationModal);
        AideGraph->resize(800, 600);
        gridLayout = new QGridLayout(AideGraph);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(AideGraph);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(AideGraph);

        QMetaObject::connectSlotsByName(AideGraph);
    } // setupUi

    void retranslateUi(QWidget *AideGraph)
    {
        AideGraph->setWindowTitle(QApplication::translate("AideGraph", "Aide Manipulation Graph", 0));
        textEdit->setHtml(QApplication::translate("AideGraph", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Vous pouvez afficher les graphes dans une autre fen\303\252tre en appuyant sur la touche F11.</p>\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:600;\">Modification d'\303\251chelle :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Pour modifier l'\303\251chelle des graphes vous pouvez :</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		-modifier le yMin, le yMax et le xMin, xMax</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		-modifier le pasY qui correspond aux pas de l'\303\251chelle Y, si vous avez un pas de deux les valeurs iront de deux en deux.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		-modifier le marquageY cela permet d'avoir un trait plein sur certaines valeurs.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		-modifier l'intervalle via la liste d\303\251roulante cela permet de choisir l'intervalle des dates pour l'\303\251chelle X.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		-modifier l'espacement des points en faisant un CRTL+Mo"
                        "lette de souris (Attention cette modification peut bloquer l'application pendant quelques instants)</p>\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:600;\">S\303\251lection d'un graphe :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Pour afficher un graphe il faut s\303\251lectionner une station ou un param\303\250tre puis s\303\251lectionner les stations ou les param\303\250tres que l'on veut afficher. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Lorsque que vous s\303\251lectionnez une station ou un param\303\250tre vous verrez afficher en gras les stations ou param\303\250tres disponible.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-b"
                        "lock-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:600;\">Double \303\251chelle :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Pour avoir acc\303\250s \303\240 la double \303\251chelle, cliquer sur le bouton &quot;Echelle&quot;. Pour modifier l'\303\251chelle d'un graphe il vous faudra tout d'abord choisir un graphe de r\303\251f\303\251rence dans la liste d\303\251roulante. Ensuite, vous pourrez modifier les valeurs dans les cellules non gris\303\251. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Si vous mettez la valeur 20 pour une unit\303\251 de mesure cela va faire monter les graphes qui ont cette unit\303\251 de mesure de 20 unit\303\251s sur le graphe.</p>\n"
"<p s"
                        "tyle=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:600;\">Modification cat\303\251gorie, couleur ou nom d'un param\303\250tre ou d'une station :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Pour modifier une station ou un param\303\250tre, cliquer sur le bouton &quot;L\303\251gende&quot;.</p>\n"
"<p style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; text-decoration: underline;\">Nb : </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Si vous avez un graphe qui est affich\303\251 et que vous changez une couleur le graphe sera affich\303\251 avec les nouvelles couleurs, mais les s\303\251lections seront enlev"
                        "\303\251es vous devrez res\303\251lectionner les stations et param\303\250tres. </p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AideGraph: public Ui_AideGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDEGRAPH_H
