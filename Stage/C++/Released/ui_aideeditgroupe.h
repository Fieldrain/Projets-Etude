/********************************************************************************
** Form generated from reading UI file 'aideeditgroupe.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDEEDITGROUPE_H
#define UI_AIDEEDITGROUPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AideEditGroupe
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *AideEditGroupe)
    {
        if (AideEditGroupe->objectName().isEmpty())
            AideEditGroupe->setObjectName(QStringLiteral("AideEditGroupe"));
        AideEditGroupe->setWindowModality(Qt::ApplicationModal);
        AideEditGroupe->resize(800, 600);
        gridLayout = new QGridLayout(AideEditGroupe);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(AideEditGroupe);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(AideEditGroupe);

        QMetaObject::connectSlotsByName(AideEditGroupe);
    } // setupUi

    void retranslateUi(QWidget *AideEditGroupe)
    {
        AideEditGroupe->setWindowTitle(QApplication::translate("AideEditGroupe", "Aide Edition Groupe", 0));
        textEdit->setHtml(QApplication::translate("AideEditGroupe", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">La fen\303\252tre d'\303\251dition des groupes est accessible en cliquant sur le bouton &quot;Editer Groupe&quot; en ayant selection un nom de groupe ou un sous-ensemble du groupe.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\"> Fonctionnement G\303\251n\303\251ral :</sp"
                        "an></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Dans cette fen\303\252tre d'\303\251dition vous trouverez deux listes, la liste de gauche contient les \303\251l\303\251ments ou nom du groupe tandis que la liste de droite contient ce que vous pouvez ajouter au groupe.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Ajouter un \303\251l\303\251ment au groupe \342\206\222 cliquer sur l'\303\251l\303\251ment dans la liste de droite.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-in"
                        "dent:0; text-indent:0px;\">	Supprimer un \303\251l\303\251ment du groupe \342\206\222 cliquer sur l'\303\251l\303\251ment dans la liste de gauche.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Valider la modification \342\206\222  cliquer sur &quot;Editer Groupe&quot;.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Nb :</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Lors de l'\303\251dition du nom d"
                        "u groupe vous ne pourrez avoir que deux \303\251l\303\251ments au maximum dans la liste de gauche. Il faudra \303\251galement supprimer un des deux \303\251l\303\251ments pour pouvoir valider la modification du nom du groupe.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AideEditGroupe: public Ui_AideEditGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDEEDITGROUPE_H
