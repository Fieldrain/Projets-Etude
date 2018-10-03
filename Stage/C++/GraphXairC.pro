#-------------------------------------------------
#
# Project created by QtCreator 2015-04-17T16:35:44
#
#-------------------------------------------------
QT += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphXairC
TEMPLATE = app

SOURCES += main.cpp\
    Core/element.cpp \
    Core/groupe.cpp \
    Core/groupes.cpp \
    Core/modele.cpp \
    Core/parametres.cpp \
    Core/stations.cpp \
    Core/vue.cpp \
    Core/xml.cpp \
    Ui/groupeadd.cpp \
    Ui/groupeedit.cpp \
    Ui/legende.cpp \
    Ui/mainwindow.cpp \
    Core/scene.cpp \
    Core/configscene.cpp \
    Core/csv.cpp \
    Core/gestiondate.cpp \
    Ui/configtest.cpp \
    Ui/fullscreen.cpp \
    Ui/configstationparametre.cpp \
    Ui/Aide/aideajoutgroupe.cpp \
    Ui/Aide/aidesupprgroupe.cpp \
    Ui/Aide/aideeditgroupe.cpp \
    Ui/Aide/aideparametretest.cpp \
    Ui/Aide/aidegraph.cpp \
    Ui/configechelle.cpp \
    Ui/emplacementxml.cpp \
    Core/station.cpp \
    Core/parametre.cpp

HEADERS  += Core/element.h \
    Core/groupe.h \
    Core/groupes.h \
    Core/modele.h \
    Core/parametres.h \
    Core/stations.h \
    Core/vue.h \
    Core/xml.h \
    Ui/groupeadd.h \
    Ui/groupeedit.h \
    Ui/legende.h \
    Ui/mainwindow.h \
    Core/scene.h \
    Core/configscene.h \
    Core/csv.h \
    Core/gestiondate.h \
    Ui/configtest.h \
    Ui/fullscreen.h \
    Ui/configstationparametre.h \
    Ui/Aide/aideajoutgroupe.h \
    Ui/Aide/aidesupprgroupe.h \
    Ui/Aide/aideeditgroupe.h \
    Ui/Aide/aideparametretest.h \
    Ui/Aide/aidegraph.h \
    Ui/configechelle.h \
    Ui/emplacementxml.h \
    Core/station.h \
    Core/parametre.h

FORMS    += Design/mainwindow.ui \
    Design/legende.ui \
    Design/groupeedit.ui \
    Design/groupeadd.ui \
    Design/configtest.ui \
    Design/fullscreen.ui \
    Design/configstationparametre.ui \
    Design/Aide/aideajoutgroupe.ui \
    Design/Aide/aidesupprgroupe.ui \
    Design/Aide/aideeditgroupe.ui \
    Design/Aide/aideparametretest.ui \
    Design/Aide/aidegraph.ui \
    Design/configechelle.ui \
    Design/emplacementxml.ui

