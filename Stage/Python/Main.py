from PyQt5 import QtCore, QtGui, QtWidgets
from UI.UImainwindow import Ui_MainWindow
from Core.xml import XmlFile
from Core.Stations import C_Stations
from Core.Parametres import C_Parametres
from Core.Groupes import C_Groupes
from Fenetres.Fenetre import F_Fenetre
import sys

if __name__ == "__main__":
    
    app = QtWidgets.QApplication(sys.argv)
    model = {}
    xmlFile = XmlFile()

    ##on creer les differents models
    model["stations"]=C_Stations(xmlFile)
    model["parametres"]=C_Parametres(xmlFile)
    
    listStation = model.get("stations").getListStation()
    listParametre = model.get("parametres").getListParametre()
    
    model["groupes"]=C_Groupes(listStation,listParametre,xmlFile)
    
    fen = F_Fenetre(xmlFile,model)
    fen.show()
    sys.exit(app.exec_())
