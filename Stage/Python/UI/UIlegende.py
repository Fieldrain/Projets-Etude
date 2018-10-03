# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/adrien/Projet/GraphXair/legende.ui'
#
# Created: Thu Apr  9 13:37:12 2015
#      by: PyQt5 UI code generator 5.3.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(521, 601)
        self.gridLayout_4 = QtWidgets.QGridLayout(Form)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.gridLayout_3 = QtWidgets.QGridLayout()
        self.gridLayout_3.setObjectName("gridLayout_3")
        
        self.tabWidget = QtWidgets.QTabWidget(Form)
        self.tabWidget.setMinimumSize(QtCore.QSize(440, 560))
        self.tabWidget.setObjectName("tabWidget")
        
        self.tabStation = QtWidgets.QWidget()
        self.tabStation.setObjectName("tabStation")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.tabStation)
        
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        
        self.tableViewStation = QtWidgets.QTableView(self.tabStation)
        self.tableViewStation.setObjectName("tableViewStation")
        self.gridLayout.addWidget(self.tableViewStation, 0, 0, 1, 1)
        
        self.verticalLayout_2.addLayout(self.gridLayout)
        self.tabWidget.addTab(self.tabStation, "")
        
        self.tabParametre = QtWidgets.QWidget()
        self.tabParametre.setObjectName("tabParametre")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.tabParametre)
        
        self.verticalLayout.setObjectName("verticalLayout")
        self.gridLayout_2 = QtWidgets.QGridLayout()
        self.gridLayout_2.setObjectName("gridLayout_2")
        
        self.tableViewParametre = QtWidgets.QTableView(self.tabParametre)
        self.tableViewParametre.setObjectName("tableViewParametre")
        self.gridLayout_2.addWidget(self.tableViewParametre, 0, 0, 1, 1)
        
        self.verticalLayout.addLayout(self.gridLayout_2)
        self.tabWidget.addTab(self.tabParametre, "")
        
        self.gridLayout_3.addWidget(self.tabWidget, 1, 1, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_3.addItem(spacerItem, 1, 2, 1, 1)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout_3.addItem(spacerItem1, 2, 1, 1, 1)
        spacerItem2 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout_3.addItem(spacerItem2, 0, 1, 1, 1)
        spacerItem3 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_3.addItem(spacerItem3, 1, 0, 1, 1)
        self.gridLayout_4.addLayout(self.gridLayout_3, 0, 0, 1, 1)

        
        self.retranslateUi(Form)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(Form)


    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Légende"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabStation), _translate("Form", "Station"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabParametre), _translate("Form", "Paramètre"))

    
