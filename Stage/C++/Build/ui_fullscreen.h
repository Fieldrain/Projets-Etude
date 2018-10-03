/********************************************************************************
** Form generated from reading UI file 'fullscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLSCREEN_H
#define UI_FULLSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FullScreen
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *FullScreen)
    {
        if (FullScreen->objectName().isEmpty())
            FullScreen->setObjectName(QStringLiteral("FullScreen"));
        FullScreen->setWindowModality(Qt::WindowModal);
        FullScreen->resize(781, 515);
        gridLayout = new QGridLayout(FullScreen);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(FullScreen);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(FullScreen);

        QMetaObject::connectSlotsByName(FullScreen);
    } // setupUi

    void retranslateUi(QWidget *FullScreen)
    {
        FullScreen->setWindowTitle(QApplication::translate("FullScreen", "Graph", 0));
    } // retranslateUi

};

namespace Ui {
    class FullScreen: public Ui_FullScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLSCREEN_H
