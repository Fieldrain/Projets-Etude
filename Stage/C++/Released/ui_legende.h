/********************************************************************************
** Form generated from reading UI file 'legende.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEGENDE_H
#define UI_LEGENDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Legende
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tabStation;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QTableView *tableViewStation;
    QWidget *tabParametre;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QTableView *tableViewParametre;

    void setupUi(QWidget *Legende)
    {
        if (Legende->objectName().isEmpty())
            Legende->setObjectName(QStringLiteral("Legende"));
        Legende->setWindowModality(Qt::WindowModal);
        Legende->resize(521, 601);
        gridLayout_4 = new QGridLayout(Legende);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        tabWidget = new QTabWidget(Legende);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(440, 560));
        tabStation = new QWidget();
        tabStation->setObjectName(QStringLiteral("tabStation"));
        verticalLayout_2 = new QVBoxLayout(tabStation);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableViewStation = new QTableView(tabStation);
        tableViewStation->setObjectName(QStringLiteral("tableViewStation"));

        gridLayout->addWidget(tableViewStation, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        tabWidget->addTab(tabStation, QString());
        tabParametre = new QWidget();
        tabParametre->setObjectName(QStringLiteral("tabParametre"));
        verticalLayout = new QVBoxLayout(tabParametre);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableViewParametre = new QTableView(tabParametre);
        tableViewParametre->setObjectName(QStringLiteral("tableViewParametre"));

        gridLayout_2->addWidget(tableViewParametre, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        tabWidget->addTab(tabParametre, QString());

        gridLayout_3->addWidget(tabWidget, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(Legende);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Legende);
    } // setupUi

    void retranslateUi(QWidget *Legende)
    {
        Legende->setWindowTitle(QApplication::translate("Legende", "Legende", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabStation), QApplication::translate("Legende", "Station", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabParametre), QApplication::translate("Legende", "Param\303\250tre", 0));
    } // retranslateUi

};

namespace Ui {
    class Legende: public Ui_Legende {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEGENDE_H
