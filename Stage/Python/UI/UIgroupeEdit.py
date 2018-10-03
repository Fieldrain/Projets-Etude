# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/adrien/git-repo/GraphXair/Design/groupeEdit.ui'
#
# Created: Thu Apr 16 15:40:30 2015
#      by: PyQt5 UI code generator 5.3.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(388, 503)
        self.gridLayout = QtWidgets.QGridLayout(Form)
        self.gridLayout.setObjectName("gridLayout")
        self.listViewCur = QtWidgets.QListView(Form)
        self.listViewCur.setObjectName("listViewCur")
        self.gridLayout.addWidget(self.listViewCur, 0, 0, 1, 1)
        self.listViewEle = QtWidgets.QListView(Form)
        self.listViewEle.setObjectName("listViewEle")
        self.gridLayout.addWidget(self.listViewEle, 0, 1, 1, 1)
        self.buttonEdit = QtWidgets.QPushButton(Form)
        self.buttonEdit.setObjectName("buttonEdit")
        self.gridLayout.addWidget(self.buttonEdit, 1, 0, 1, 2)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Edition Groupe"))
        self.buttonEdit.setText(_translate("Form", "Editer Groupe"))


