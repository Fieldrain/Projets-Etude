/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOuvrir;
    QAction *actionFermer;
    QAction *actionParam_tre_Test;
    QAction *actionAjouter_un_groupe;
    QAction *actionSupprimer_un_groupe;
    QAction *actionEditer_un_groupe;
    QAction *actionParam_tres_de_test;
    QAction *actionManipulation_des_Graphs;
    QAction *actionEmplacement_XMl;
    QWidget *centralWidget;
    QGridLayout *gridLayout_11;
    QTabWidget *tabFenPrinc;
    QWidget *tabGraph;
    QGridLayout *gridLayout_9;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_5;
    QLabel *labelTabStations;
    QTreeView *listViewStation;
    QGraphicsView *graphView;
    QGridLayout *gridLayout_4;
    QLabel *labelTabParametre;
    QTreeView *listViewParametre;
    QGridLayout *gridLayout_6;
    QLabel *labelTaux;
    QLineEdit *lineEditMinMax;
    QDateTimeEdit *dateTimeDate;
    QLabel *labelDate;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QLineEdit *lineEditNomGraph;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditTaux;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frameTop;
    QGridLayout *gridLayout;
    QTreeView *treeViewGroupe;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxIntervalleX;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonSupprGroupe;
    QPushButton *buttonLegende;
    QPushButton *buttonAjoutGroupe;
    QPushButton *buttonActualiser;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label;
    QDateTimeEdit *dateTimeEditXmin;
    QDateTimeEdit *dateTimeEditXmax;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxYmin;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxYmax;
    QLabel *labelechelleY;
    QDoubleSpinBox *doubleSpinBoxPasY;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxMarquageY;
    QLabel *label_7;
    QPushButton *buttonEchelle;
    QPushButton *buttonEditerGroupe;
    QCheckBox *checkBoxHidePoint;
    QWidget *tabDonneInvalide;
    QGridLayout *gridLayout_14;
    QTextEdit *textEditDonneInvalide;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuConfiguration;
    QMenu *menuHelp;
    QMenu *menuGroupes;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1176, 902);
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionParam_tre_Test = new QAction(MainWindow);
        actionParam_tre_Test->setObjectName(QStringLiteral("actionParam_tre_Test"));
        actionAjouter_un_groupe = new QAction(MainWindow);
        actionAjouter_un_groupe->setObjectName(QStringLiteral("actionAjouter_un_groupe"));
        actionSupprimer_un_groupe = new QAction(MainWindow);
        actionSupprimer_un_groupe->setObjectName(QStringLiteral("actionSupprimer_un_groupe"));
        actionEditer_un_groupe = new QAction(MainWindow);
        actionEditer_un_groupe->setObjectName(QStringLiteral("actionEditer_un_groupe"));
        actionParam_tres_de_test = new QAction(MainWindow);
        actionParam_tres_de_test->setObjectName(QStringLiteral("actionParam_tres_de_test"));
        actionManipulation_des_Graphs = new QAction(MainWindow);
        actionManipulation_des_Graphs->setObjectName(QStringLiteral("actionManipulation_des_Graphs"));
        actionEmplacement_XMl = new QAction(MainWindow);
        actionEmplacement_XMl->setObjectName(QStringLiteral("actionEmplacement_XMl"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_11 = new QGridLayout(centralWidget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        tabFenPrinc = new QTabWidget(centralWidget);
        tabFenPrinc->setObjectName(QStringLiteral("tabFenPrinc"));
        tabFenPrinc->setStyleSheet(QStringLiteral(""));
        tabGraph = new QWidget();
        tabGraph->setObjectName(QStringLiteral("tabGraph"));
        tabGraph->setStyleSheet(QStringLiteral(""));
        gridLayout_9 = new QGridLayout(tabGraph);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        frame = new QFrame(tabGraph);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 550));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelTabStations = new QLabel(frame);
        labelTabStations->setObjectName(QStringLiteral("labelTabStations"));
        labelTabStations->setMaximumSize(QSize(200, 16777215));

        gridLayout_5->addWidget(labelTabStations, 0, 0, 1, 1);

        listViewStation = new QTreeView(frame);
        listViewStation->setObjectName(QStringLiteral("listViewStation"));
        listViewStation->setMinimumSize(QSize(200, 350));
        listViewStation->setMaximumSize(QSize(200, 700));
        listViewStation->setMouseTracking(false);
        listViewStation->setContextMenuPolicy(Qt::DefaultContextMenu);
        listViewStation->setStyleSheet(QStringLiteral(""));
        listViewStation->setDragDropMode(QAbstractItemView::NoDragDrop);

        gridLayout_5->addWidget(listViewStation, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 0, 0, 1, 1);

        graphView = new QGraphicsView(frame);
        graphView->setObjectName(QStringLiteral("graphView"));
        graphView->setMinimumSize(QSize(700, 490));
        graphView->setStyleSheet(QStringLiteral(""));
        graphView->setInteractive(true);
        graphView->setDragMode(QGraphicsView::NoDrag);
        graphView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

        gridLayout_3->addWidget(graphView, 0, 1, 1, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        labelTabParametre = new QLabel(frame);
        labelTabParametre->setObjectName(QStringLiteral("labelTabParametre"));
        labelTabParametre->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(labelTabParametre, 0, 0, 1, 1);

        listViewParametre = new QTreeView(frame);
        listViewParametre->setObjectName(QStringLiteral("listViewParametre"));
        listViewParametre->setMinimumSize(QSize(200, 350));
        listViewParametre->setMaximumSize(QSize(200, 700));
        listViewParametre->setContextMenuPolicy(Qt::DefaultContextMenu);
        listViewParametre->setStyleSheet(QStringLiteral(""));

        gridLayout_4->addWidget(listViewParametre, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 3, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        labelTaux = new QLabel(frame);
        labelTaux->setObjectName(QStringLiteral("labelTaux"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTaux->sizePolicy().hasHeightForWidth());
        labelTaux->setSizePolicy(sizePolicy);
        labelTaux->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(labelTaux, 0, 6, 1, 1);

        lineEditMinMax = new QLineEdit(frame);
        lineEditMinMax->setObjectName(QStringLiteral("lineEditMinMax"));
        lineEditMinMax->setReadOnly(true);

        gridLayout_6->addWidget(lineEditMinMax, 0, 10, 1, 1);

        dateTimeDate = new QDateTimeEdit(frame);
        dateTimeDate->setObjectName(QStringLiteral("dateTimeDate"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateTimeDate->sizePolicy().hasHeightForWidth());
        dateTimeDate->setSizePolicy(sizePolicy1);
        dateTimeDate->setMinimumSize(QSize(200, 0));
        dateTimeDate->setReadOnly(false);

        gridLayout_6->addWidget(dateTimeDate, 0, 4, 1, 1);

        labelDate = new QLabel(frame);
        labelDate->setObjectName(QStringLiteral("labelDate"));

        gridLayout_6->addWidget(labelDate, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        lineEditNomGraph = new QLineEdit(frame);
        lineEditNomGraph->setObjectName(QStringLiteral("lineEditNomGraph"));
        lineEditNomGraph->setEnabled(true);
        lineEditNomGraph->setReadOnly(true);

        gridLayout_6->addWidget(lineEditNomGraph, 0, 1, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_6->addWidget(label_8, 0, 9, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        lineEditTaux = new QLineEdit(frame);
        lineEditTaux->setObjectName(QStringLiteral("lineEditTaux"));
        lineEditTaux->setReadOnly(true);

        gridLayout_6->addWidget(lineEditTaux, 0, 7, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 0, 8, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 1, 1, 1, 1);


        gridLayout_9->addWidget(frame, 1, 0, 1, 1);

        frameTop = new QFrame(tabGraph);
        frameTop->setObjectName(QStringLiteral("frameTop"));
        frameTop->setMinimumSize(QSize(0, 0));
        frameTop->setMaximumSize(QSize(16777215, 170));
        frameTop->setFrameShape(QFrame::StyledPanel);
        frameTop->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameTop);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeViewGroupe = new QTreeView(frameTop);
        treeViewGroupe->setObjectName(QStringLiteral("treeViewGroupe"));
        treeViewGroupe->setMinimumSize(QSize(100, 140));
        treeViewGroupe->setMaximumSize(QSize(650, 16777215));

        gridLayout->addWidget(treeViewGroupe, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBoxIntervalleX = new QComboBox(frameTop);
        comboBoxIntervalleX->setObjectName(QStringLiteral("comboBoxIntervalleX"));

        gridLayout_2->addWidget(comboBoxIntervalleX, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 4, 1, 1);

        buttonSupprGroupe = new QPushButton(frameTop);
        buttonSupprGroupe->setObjectName(QStringLiteral("buttonSupprGroupe"));

        gridLayout_2->addWidget(buttonSupprGroupe, 2, 0, 1, 1);

        buttonLegende = new QPushButton(frameTop);
        buttonLegende->setObjectName(QStringLiteral("buttonLegende"));

        gridLayout_2->addWidget(buttonLegende, 0, 10, 1, 1);

        buttonAjoutGroupe = new QPushButton(frameTop);
        buttonAjoutGroupe->setObjectName(QStringLiteral("buttonAjoutGroupe"));

        gridLayout_2->addWidget(buttonAjoutGroupe, 0, 0, 1, 1);

        buttonActualiser = new QPushButton(frameTop);
        buttonActualiser->setObjectName(QStringLiteral("buttonActualiser"));

        gridLayout_2->addWidget(buttonActualiser, 3, 10, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 9, 1, 1);

        label_2 = new QLabel(frameTop);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 1, 1, 1);

        label = new QLabel(frameTop);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        dateTimeEditXmin = new QDateTimeEdit(frameTop);
        dateTimeEditXmin->setObjectName(QStringLiteral("dateTimeEditXmin"));

        gridLayout_2->addWidget(dateTimeEditXmin, 0, 3, 1, 1);

        dateTimeEditXmax = new QDateTimeEdit(frameTop);
        dateTimeEditXmax->setObjectName(QStringLiteral("dateTimeEditXmax"));

        gridLayout_2->addWidget(dateTimeEditXmax, 1, 3, 1, 1);

        label_3 = new QLabel(frameTop);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 6, 1, 1);

        doubleSpinBoxYmin = new QDoubleSpinBox(frameTop);
        doubleSpinBoxYmin->setObjectName(QStringLiteral("doubleSpinBoxYmin"));
        doubleSpinBoxYmin->setMinimum(-100);
        doubleSpinBoxYmin->setMaximum(100);

        gridLayout_2->addWidget(doubleSpinBoxYmin, 0, 8, 1, 1);

        label_4 = new QLabel(frameTop);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 6, 1, 1);

        doubleSpinBoxYmax = new QDoubleSpinBox(frameTop);
        doubleSpinBoxYmax->setObjectName(QStringLiteral("doubleSpinBoxYmax"));
        doubleSpinBoxYmax->setMaximum(1e+06);
        doubleSpinBoxYmax->setValue(100);

        gridLayout_2->addWidget(doubleSpinBoxYmax, 1, 8, 1, 1);

        labelechelleY = new QLabel(frameTop);
        labelechelleY->setObjectName(QStringLiteral("labelechelleY"));
        labelechelleY->setMaximumSize(QSize(16777215, 20));

        gridLayout_2->addWidget(labelechelleY, 2, 6, 1, 1);

        doubleSpinBoxPasY = new QDoubleSpinBox(frameTop);
        doubleSpinBoxPasY->setObjectName(QStringLiteral("doubleSpinBoxPasY"));
        doubleSpinBoxPasY->setSingleStep(0.1);
        doubleSpinBoxPasY->setValue(1);

        gridLayout_2->addWidget(doubleSpinBoxPasY, 2, 8, 1, 1);

        label_6 = new QLabel(frameTop);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 3, 6, 1, 1);

        doubleSpinBoxMarquageY = new QDoubleSpinBox(frameTop);
        doubleSpinBoxMarquageY->setObjectName(QStringLiteral("doubleSpinBoxMarquageY"));
        doubleSpinBoxMarquageY->setMaximum(100);
        doubleSpinBoxMarquageY->setValue(10);

        gridLayout_2->addWidget(doubleSpinBoxMarquageY, 3, 8, 1, 1);

        label_7 = new QLabel(frameTop);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 2, 2, 1, 1);

        buttonEchelle = new QPushButton(frameTop);
        buttonEchelle->setObjectName(QStringLiteral("buttonEchelle"));

        gridLayout_2->addWidget(buttonEchelle, 1, 10, 1, 1);

        buttonEditerGroupe = new QPushButton(frameTop);
        buttonEditerGroupe->setObjectName(QStringLiteral("buttonEditerGroupe"));

        gridLayout_2->addWidget(buttonEditerGroupe, 1, 0, 1, 1);

        checkBoxHidePoint = new QCheckBox(frameTop);
        checkBoxHidePoint->setObjectName(QStringLiteral("checkBoxHidePoint"));
        checkBoxHidePoint->setChecked(true);

        gridLayout_2->addWidget(checkBoxHidePoint, 3, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);


        gridLayout_9->addWidget(frameTop, 0, 0, 1, 1);

        tabFenPrinc->addTab(tabGraph, QString());
        tabDonneInvalide = new QWidget();
        tabDonneInvalide->setObjectName(QStringLiteral("tabDonneInvalide"));
        gridLayout_14 = new QGridLayout(tabDonneInvalide);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        textEditDonneInvalide = new QTextEdit(tabDonneInvalide);
        textEditDonneInvalide->setObjectName(QStringLiteral("textEditDonneInvalide"));
        textEditDonneInvalide->setReadOnly(true);

        gridLayout_14->addWidget(textEditDonneInvalide, 0, 0, 1, 1);

        tabFenPrinc->addTab(tabDonneInvalide, QString());

        gridLayout_11->addWidget(tabFenPrinc, 1, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        gridLayout_11->addWidget(progressBar, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1176, 27));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuConfiguration = new QMenu(menuBar);
        menuConfiguration->setObjectName(QStringLiteral("menuConfiguration"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuGroupes = new QMenu(menuHelp);
        menuGroupes->setObjectName(QStringLiteral("menuGroupes"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuConfiguration->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionFermer);
        menuConfiguration->addAction(actionParam_tre_Test);
        menuConfiguration->addAction(actionEmplacement_XMl);
        menuHelp->addAction(menuGroupes->menuAction());
        menuHelp->addAction(actionParam_tres_de_test);
        menuHelp->addAction(actionManipulation_des_Graphs);
        menuGroupes->addAction(actionAjouter_un_groupe);
        menuGroupes->addAction(actionSupprimer_un_groupe);
        menuGroupes->addAction(actionEditer_un_groupe);

        retranslateUi(MainWindow);

        tabFenPrinc->setCurrentIndex(0);
        comboBoxIntervalleX->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GraphXair", 0));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir", 0));
        actionFermer->setText(QApplication::translate("MainWindow", "Fermer", 0));
        actionParam_tre_Test->setText(QApplication::translate("MainWindow", "Param\303\250tre Test", 0));
        actionAjouter_un_groupe->setText(QApplication::translate("MainWindow", "Ajouter un groupe", 0));
        actionSupprimer_un_groupe->setText(QApplication::translate("MainWindow", "Supprimer un groupe", 0));
        actionEditer_un_groupe->setText(QApplication::translate("MainWindow", "Editer un groupe", 0));
        actionParam_tres_de_test->setText(QApplication::translate("MainWindow", "Configuration des param\303\250tres de test", 0));
        actionManipulation_des_Graphs->setText(QApplication::translate("MainWindow", "Manipulation des Graphs", 0));
        actionEmplacement_XMl->setText(QApplication::translate("MainWindow", "Emplacement XMl", 0));
        labelTabStations->setText(QApplication::translate("MainWindow", "Stations", 0));
        labelTabParametre->setText(QApplication::translate("MainWindow", "Param\303\250tres", 0));
        labelTaux->setText(QApplication::translate("MainWindow", "Taux", 0));
        dateTimeDate->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd hh:mm:ss", 0));
        labelDate->setText(QApplication::translate("MainWindow", "Date", 0));
        label_5->setText(QApplication::translate("MainWindow", "Nom", 0));
        label_8->setText(QApplication::translate("MainWindow", "Min/Max", 0));
        comboBoxIntervalleX->clear();
        comboBoxIntervalleX->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "15 min", 0)
         << QApplication::translate("MainWindow", "1 h", 0)
         << QApplication::translate("MainWindow", "12 h", 0)
         << QApplication::translate("MainWindow", "1 jour", 0)
         << QApplication::translate("MainWindow", "1 semaine", 0)
        );
        buttonSupprGroupe->setText(QApplication::translate("MainWindow", "Supprimer Groupe", 0));
        buttonLegende->setText(QApplication::translate("MainWindow", "L\303\251gende", 0));
        buttonAjoutGroupe->setText(QApplication::translate("MainWindow", "Ajouter Groupe", 0));
        buttonActualiser->setText(QApplication::translate("MainWindow", "Actualiser", 0));
        label_2->setText(QApplication::translate("MainWindow", "Xmax :", 0));
        label->setText(QApplication::translate("MainWindow", "Xmin :", 0));
        dateTimeEditXmin->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd hh:mm:ss", 0));
        dateTimeEditXmax->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd hh:mm:ss", 0));
        label_3->setText(QApplication::translate("MainWindow", "Ymin :", 0));
        label_4->setText(QApplication::translate("MainWindow", "Ymax :", 0));
        labelechelleY->setText(QApplication::translate("MainWindow", "Pas Y :", 0));
        label_6->setText(QApplication::translate("MainWindow", "Marquage Y :", 0));
        label_7->setText(QApplication::translate("MainWindow", "Intervalle", 0));
        buttonEchelle->setText(QApplication::translate("MainWindow", "Echelle", 0));
        buttonEditerGroupe->setText(QApplication::translate("MainWindow", "Editer Groupe", 0));
        checkBoxHidePoint->setText(QApplication::translate("MainWindow", "Afficher points", 0));
        tabFenPrinc->setTabText(tabFenPrinc->indexOf(tabGraph), QApplication::translate("MainWindow", "Graphique", 0));
        tabFenPrinc->setTabText(tabFenPrinc->indexOf(tabDonneInvalide), QApplication::translate("MainWindow", "R\303\251sultats Test", 0));
        progressBar->setFormat(QApplication::translate("MainWindow", "%v%", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configuration", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Aide", 0));
        menuGroupes->setTitle(QApplication::translate("MainWindow", "Groupes", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
