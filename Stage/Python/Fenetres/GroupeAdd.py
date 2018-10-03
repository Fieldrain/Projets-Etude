from PyQt5 import QtCore, QtGui, QtWidgets
from UI.UIgroupeAdd import Ui_Form

class F_GroupeAdd(QtWidgets.QWidget, Ui_Form):
 
    def __init__(self, xmlFile, model, parent=None):
        super(F_GroupeAdd, self).__init__(parent)
        self.model = model

        ## on abonne la fenetre au model pour quel recoive les modifications
        self.model.get("stations").abonne(self)
        self.model.get("parametres").abonne(self)
        
        self.setupUi(self)
        self.refresh()

        ## on connecte les evenement a leur fonction
        self.buttonCreer.clicked.connect(self.buttonCreer_clicked)
        self.checkBoxNom.clicked.connect(self.checkBoxNom_clicked)
        self.checkBoxGroupe.clicked.connect(self.checkBoxGroupe_clicked)
        self.listViewStations.clicked.connect(self.listViewSelections_clicked)
        self.listViewParametres.clicked.connect(self.listViewSelections_clicked)
        self.listViewGroupe.clicked.connect(self.listViewGroupe_clicked)
        
## fonction appele quand les models sont modifiés
    def refresh(self):
        self.init_listView()
        self.lineEditNom.clear()
        self.modelListGroupe.setStringList([])
        self.checkBoxNom.setCheckState(QtCore.Qt.Unchecked)
        self.checkBoxGroupe.setCheckState(QtCore.Qt.Unchecked)
        self.listViewStations.setEnabled(1)
        self.listViewParametres.setEnabled(1)

        if(self.checkBoxNom.checkState() == 0):
            self.listViewGroupe.setEnabled(0)
            self.checkBoxGroupe.setEnabled(0)
        

    def init_listView(self):
        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")

        ## on recupere les listes des stations et des parametres
        stations = modelS.getListNomStation()
        parametres = modelP.getListNomParametre()

        ## on cree puis lie les model aux listView
        self.modelListGroupe = QtCore.QStringListModel(self)
        self.listViewGroupe.setModel(self.modelListGroupe)

        self.modelListStations = QtCore.QStringListModel(self)
        self.listViewStations.setModel(self.modelListStations)
        
        self.modelListParametre = QtCore.QStringListModel(self)
        self.listViewParametres.setModel(self.modelListParametre)

        ## on initialise le model avec les listes
        self.modelListStations.setStringList(stations)
        self.modelListParametre.setStringList(parametres)

        ## on enleve l'edition et la selection des listView
        self.listViewGroupe.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)
        self.listViewGroupe.setSelectionMode(QtWidgets.QAbstractItemView.NoSelection)

        self.listViewStations.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)
        self.listViewStations.setSelectionMode(QtWidgets.QAbstractItemView.NoSelection)

        self.listViewParametres.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)
        self.listViewParametres.setSelectionMode(QtWidgets.QAbstractItemView.NoSelection)
            

    def listViewSelections_clicked(self,item):
        modelS = self.model.get("stations")

        ## on regarde si le nom du groupe n'est pas validé
        if (self.checkBoxNom.checkState() == 0):
            self.lineEditNom.clear()

            ## on ajoute l'item selectionne 
            self.lineEditNom.insert(item.data())

            ## on recupere l'element qui correspond au nom du groupe
            elt = modelS.getStation(self.lineEditNom.text())

            ## on recupere la liste du groupe
            groupe = self.modelListGroupe.stringList()

            ## si la liste n'est pas vide
            if(len(groupe) > 0):
                firstGroupe  = groupe[0]

                ## si le premiere element du groupe est du meme type que celui du nom du groupe on vide le groupe
                if(elt==modelS.getStation(firstGroupe)):
                    self.modelListGroupe.setStringList([])
                    
        else:
            ## si le nom du groupe est validé

            ## on recupere la liste du groupe
            liste = self.modelListGroupe.stringList()

            ## si l'item sellectionne n'est pas dans le groupe on l'ajoute
            if((item.data() in liste)==0):
                liste.append(item.data())

            ## on change la liste du model
            self.modelListGroupe.setStringList(liste)

    def checkBoxNom_clicked(self):
        modelS = self.model.get("stations")

        ## si le nom du groupe est vide on bloque la validation
        if(self.lineEditNom.text()==""):
            self.checkBoxNom.setCheckState(QtCore.Qt.Unchecked)
            
        elif(self.checkBoxNom.checkState() == 2):
            
            ## on active la listView groupe et la validation de la partie groupe
            self.listViewGroupe.setEnabled(1)
            self.checkBoxGroupe.setEnabled(1)

            nom = self.lineEditNom.text()

            ## on recupere l'element qui correspond au nom du groupe et on desactive la listView du meme type
            if(modelS.getStation(nom)==None):
                self.listViewParametres.setEnabled(0)
            else:
                self.listViewStations.setEnabled(0)
                
        elif(self.checkBoxNom.checkState() == 0):
            ## on desactive la listView du groupe et la validation du groupe que l'on decoche egalement
            self.listViewGroupe.setEnabled(0)
            self.checkBoxGroupe.setCheckState(QtCore.Qt.Unchecked)
            self.checkBoxGroupe.setEnabled(0)

            ## on reactive les deux listView stations et parametres
            self.listViewStations.setEnabled(1)
            self.listViewParametres.setEnabled(1)
        
    def checkBoxGroupe_clicked(self):
        modelS = self.model.get("stations")

        ## si le groupe est validé
        if(self.checkBoxGroupe.checkState() == 2):
            ## on recupere la liste du groupe
            groupe = self.modelListGroupe.stringList()

            ## si le groupe n'est pas vide
            if(len(groupe) > 0):
                nom = groupe[0]

                ## on recupere le type des element du groupe et on desactive la vue qui correspond
                if(modelS.getStation(nom)==None):
                    self.listViewParametres.setEnabled(0)
                else:
                    self.listViewStations.setEnabled(0)
                    
            else:
                ## on bloque la validation du groupe
                self.checkBoxGroupe.setCheckState(QtCore.Qt.Unchecked)
                    
        else:
            ## on recupere la liste du groupe
            groupe = self.modelListGroupe.stringList()

            ## si le groupe n'est pas vide
            if(len(groupe) > 0):
                nom = groupe[0]

                ## on recupere le type des element du groupe et on reactive la vue qui correspond
                if(modelS.getStation(nom)==None):
                    self.listViewParametres.setEnabled(1)
                else:
                    self.listViewStations.setEnabled(1)
                    
            else:
                ## on bloque la validation du groupe
                self.checkBoxGroupe.setCheckState(QtCore.Qt.Unchecked)

    def listViewGroupe_clicked(self ,item):
        modelS = self.model.get("stations")

        ## on enleve l'item selectionne
        self.modelListGroupe.removeRow(item.row())

        ## on regarde si la liste est vide
        if(len(self.modelListGroupe.stringList())==0):
            ## on enleve la validation du groupe 
            self.checkBoxGroupe.setCheckState(QtCore.Qt.Unchecked)
            nom = self.lineEditNom.text()

            ## on reactive la listView
            if(modelS.getStation(nom)==None):
                self.listViewStations.setEnabled(1)
            else:
                self.listViewParametres.setEnabled(1)

    def buttonCreer_clicked(self):
        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")
        modelG = self.model.get("groupes")

        ## on verifie que le nom du groupe et les groupes sont validés
        if(self.checkBoxGroupe.checkState() == 2 and self.checkBoxNom.checkState() == 2):

            ## on recupere l'element qui correspond au nom du groupe et les elements qui compose le groupe
            nomGroupe = self.lineEditNom.text()
            
            listNomEltGroupe = self.modelListGroupe.stringList()

            firstEltGroupe = modelS.getStation(listNomEltGroupe[0])

            if(firstEltGroupe == None):
                fils = modelP.getListParametre_Noms(listNomEltGroupe)
                pere = modelS.getStation(nomGroupe)
                
            else:
                fils = modelS.getListStation_Noms(listNomEltGroupe)
                pere = modelP.getParametre(nomGroupe)

            ## on ajoute le groupe                
            modelG.addGroupe(pere,fils)
            self.close()
        else:
            messageBox = QtWidgets.QMessageBox()
            messageBox.setWindowTitle("Erreur")
            messageBox.setText("Vous devez valider le nom et le groupe.")
            messageBox.exec()
            
    def showEvent(self, event):
        self.refresh()
        event.accept()
            
