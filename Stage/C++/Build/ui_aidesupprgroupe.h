/********************************************************************************
** Form generated from reading UI file 'aidesupprgroupe.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDESUPPRGROUPE_H
#define UI_AIDESUPPRGROUPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AideSupprGroupe
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *AideSupprGroupe)
    {
        if (AideSupprGroupe->objectName().isEmpty())
            AideSupprGroupe->setObjectName(QStringLiteral("AideSupprGroupe"));
        AideSupprGroupe->setWindowModality(Qt::ApplicationModal);
        AideSupprGroupe->resize(800, 600);
        gridLayout = new QGridLayout(AideSupprGroupe);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(AideSupprGroupe);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(AideSupprGroupe);

        QMetaObject::connectSlotsByName(AideSupprGroupe);
    } // setupUi

    void retranslateUi(QWidget *AideSupprGroupe)
    {
        AideSupprGroupe->setWindowTitle(QApplication::translate("AideSupprGroupe", "Aide Suppression Groupe", 0));
        textEdit->setHtml(QApplication::translate("AideSupprGroupe", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pour supprimer un groupe il suffit de s\303\251lectionner le groupe que vous souhaitez supprimer puis de cliquer sur le bouton &quot;Supprimer Groupe&quot;.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Si vous cliquer sur le bouton de suppression alors que vous avez selectionner le nom d'un groupe cela va supprimer tous "
                        "les groupes qui ont ce nom.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Exemple: NO</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Tarnier,Pejoces</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		Nevers</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	Si vous s\303\251lectionnez NO cela supprime le groupe Tarnier,P\303\251joces et Nevers.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AideSupprGroupe: public Ui_AideSupprGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDESUPPRGROUPE_H
