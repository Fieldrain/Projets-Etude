from PyQt5 import QtCore, QtGui, QtWidgets
from UI.UImainwindow import Ui_MainWindow
from Fenetres.Legende import F_Legende
from Fenetres.GroupeEdit import F_Groupe
from Fenetres.GroupeAdd import F_GroupeAdd
import sys

class F_Fenetre(QtWidgets.QMainWindow, Ui_MainWindow):
 
    def __init__(self, xmlFile, model, parent=None):
        super(F_Fenetre, self).__init__(parent)
        self.model = model

        ## on abonne la fenetre au model pour quel recoive les modifications
        self.model.get("groupes").abonne(self)
        self.model.get("stations").abonne(self)
        self.model.get("parametres").abonne(self)
        
        self.setupUi(self)

        self.refresh()

        ## on cree les autres fenetres
        self.legende = F_Legende(xmlFile,model)
        self.groupeEdit = F_Groupe(xmlFile,model)
        self.groupeAdd = F_GroupeAdd(xmlFile,model)

        ## on connect les evenement a leur fonction
        self.buttonLegende.clicked.connect(self.buttonLegende_clicked)

        self.buttonAjoutGroupe.clicked.connect(self.buttonAjoutGroupe_clicked)

        self.buttonSupprGroupe.clicked.connect(self.buttonSupprGroupe_clicked)
        
        self.treeViewGroupe.doubleClicked.connect(self.treeView_doubleClicked)

        self.treeViewGroupe.clicked.connect(self.treeView_clicked)

## fonction appele quand les models sont modifies
    def refresh(self):
        ## on connect les evenements triggered aux l'actions Ouvrir,fermer (fichier/ouvir) a la fonction actionOuvrir_triggered et actionFermer_triggered
        self.actionOuvrir.triggered.connect(self.actionOuvrir_triggered)
        self.actionFermer.triggered.connect(self.actionFermer_triggered)

        ##on initialise les different elements de l'interface
        self.init_listViewParametre()
        self.init_listViewStation()
        self.init_treeViewGroupe()

## fonction qui initialise le contenu de la treeview qui correspond a la gestion des groupes
    def init_treeViewGroupe(self):
        ## on recupere le model groupe
        model = self.model.get("groupes")

        ## on recupere la liste des noms des parents des groupes
        parents = model.getListNomParent()

        listeHeader = ["Groupe"]

        ## on place l'header de la treeview
        self.modelTreeGroupe = QtGui.QStandardItemModel()
        self.modelTreeGroupe.setHorizontalHeaderLabels(listeHeader)

        ## on lie le model a ca vue
        self.treeViewGroupe.setModel(self.modelTreeGroupe)
        
        for i in range(0,len(parents)):
            
            ## on recupere le parent numero i puis on creer l'item avec comme donnee le nom du parent
            parent = parents[i]
            itemParent = QtGui.QStandardItem(parent)

            ## on recupere les fils du parent i
            fils = model.getFils(i)
            
            for labelFils in fils:
                
                if (labelFils!=""):
                    
                    ## on cree l'item fils avec comme donnee le nom des fils qui compose le groupe
                    itemFils = QtGui.QStandardItem(labelFils)

                    itemFils.setEditable(0)

                    ## on ajoute le fils au parent
                    itemParent.appendRow(itemFils)

                    itemParent.setEditable(0)
                    
            ## on ajoute le parent dans la treeView       
            self.modelTreeGroupe.insertRow(i,itemParent)

##fonction qui initialise le contenu de la listView des parametres  
    def init_listViewParametre(self):
        model = self.model.get("parametres")
        
        parametres = model.getListNomParametre()
        
        #on cree le model pour la listView puis on lui ajoute
        self.modelListParametre = QtCore.QStringListModel(self)
        self.listViewParametre.setModel(self.modelListParametre)
        
        #on ajoute les Parametre dans le model de la listView
        self.modelListParametre.setStringList(parametres)
        
        #on bloque l'edition dans la liste view
        self.listViewParametre.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)

        #on change le mode de selection pour avoir une selection multiple
        self.listViewParametre.setSelectionMode(QtWidgets.QAbstractItemView.MultiSelection)

##fonction qui initialise le contenu de la listView des stations       
    def init_listViewStation(self):
        model = self.model.get("stations")
        
        stations = model.getListNomStation()
        
        #on cree le model pour la list view puis on lui ajoute
        self.modelListStations = QtCore.QStringListModel(self)
        self.listViewStations.setModel(self.modelListStations)
        
        #on ajoute les Stations dans le model de la listView
        self.modelListStations.setStringList(stations)
        
        #on bloque l'edition dans la liste view
        self.listViewStations.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)

        #on change le mode de selection pour avoir une selection multiple
        self.listViewStations.setSelectionMode(QtWidgets.QAbstractItemView.MultiSelection)


##fonction appele lorsque l'on clique sur ouvrir dans l'onglet fichier
##on ouvre une boite de dialogue pour choisir le fichier et on change le nom de la fenetre par le nom du fichier
    def actionOuvrir_triggered(self):
        _translate = QtCore.QCoreApplication.translate
        filename = QtWidgets.QFileDialog.getOpenFileName()
        fen.setWindowTitle(_translate("MainWindow", filename[0]))

##fonction appele lorsque l'on clique sur fermer dans l'onglet fichier
##on ferme l'application
##nb:pense a ajouter un boite de dialog pour sauvegarder si besoin  
    def actionFermer_triggered(self):
        sys.exit()

##fonction appele lorsque l'on clique sur le bouton Légende
##on ouvrir la legende
    def buttonLegende_clicked(self):
        if self.legende.isVisible():
            self.legende.close()
        else:
            self.legende.show()

##fonction appele lorsque l'on clique sur le bouton Ajouter Groupe
##on ouvrir la fenetre de creation de groupe 
    def buttonAjoutGroupe_clicked(self):
        if self.groupeAdd.isVisible():
            self.groupeAdd.close()
        else:
            self.groupeAdd.show()


##fonction appele lorsque l'on clique sur le bouton Supprimer Groupe
    def buttonSupprGroupe_clicked(self):
        modelG = self.model.get("groupes")
        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")

        ## on recupere l'item selectionner dans la treeView qui correspond au groupe a supprimer
        item = self.treeViewGroupe.selectedIndexes()[0]

        ## on verifie qu'il s'agit d'un groupe a pas du nom du groupe
        if(item.child(0,0).data()==None):

            ## on recupere la liste des noms des elements du groupe
            nomFils = item.data().split(" ")
            nomFils.pop(nomFils.index(""))

            ## on recupere le nom de groupe
            nomPere = item.parent().data()

            firstFils = nomFils[0]

            ## on regarde si le premier nom de la liste est une station
            if(modelS.getStation(firstFils)!=None):
                ## on recupere l'element qui correspond au nom de groupe
                pere = modelP.getParametre(nomPere)
                
                ## on recupere les elements qui correspondent au groupe
                fils = modelS.getListStation_Noms(nomFils)

            else:
                pere = modelS.getStation(nomPere)
                fils = modelP.getListParametre_Noms(nomFils)

            ## on supprime le groupe
            modelG.removeFils(pere,fils)

                
## fonction appele lorsque l'on double clique sur la treeView
## ouvre la fenetre d'edition de groupe
    def treeView_doubleClicked(self,item):
        modelG = self.model.get("groupes")
        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")

        ## on recupere la liste des stations et des parametres
        listStation = modelS.getListStation()
        listParametre = modelP.getListParametre()

        ## on recupere la liste contenu dans l'item selectionné (groupe ou nomgroupe)
        listCur = item.data()

        listNomCur = []
        ## on regarde si il s'agit du groupe et pas du nom du groupe
        if(item.child(0,0).data()==None):

            ## on decoupe le label pour avoir une liste de noms
            listNomCur = listCur.split(" ")
            listNomCur.pop(listNomCur.index(""))
            
            ## on recupere le nom du groupe
            pere = item.parent().data()
            
        else:
            listNomCur.append(listCur)
            pere = None

        firstEle = listNomCur[0]
        
        if(modelS.getStation(firstEle)!=None):
            ## on recupere les elements stations
            listEleCur = modelS.getListStation_Noms(listNomCur)
            
            ## on recupere l'element pere
            eltPere = modelP.getParametre(pere)
        else:
            listEleCur = modelP.getListParametre_Noms(listNomCur)

            eltPere = modelS.getStation(pere)

        self.groupeEdit.ouvrir(listEleCur, eltPere)

    def treeView_clicked(self,item):
        
        self.listViewStations.setSelection(self.listViewStations.rect(),QtCore.QItemSelectionModel.Clear)
        self.listViewParametre.setSelection(self.listViewStations.rect(),QtCore.QItemSelectionModel.Clear)

        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")
        
        if(item.child(0,0).data()==None):
            listItem = item.data()

            nomPere = item.parent().data()

            pere = modelS.getStation(nomPere)

            if(pere == None):
                modelPere = self.modelListParametre
                modelFils = self.modelListStations
                viewFils = self.listViewStations
                viewPere = self.listViewParametre
            else:
                modelFils = self.modelListParametre
                modelPere = self.modelListStations
                viewFils = self.listViewParametre
                viewPere = self.listViewStations
            
            for i in range(0,modelFils.rowCount()):
                index = modelFils.index(i)
                if((index.data() in listItem) ==1):
                    viewFils.setCurrentIndex(index)

            for i in range(0,modelPere.rowCount()):
                index = modelPere.index(i)
                if(index.data() == nomPere):
                    viewPere.setCurrentIndex(index)
        
     
##surcharge de l'evenement close pour pouvoir fermer toutes les fenetres quand on ferme la fenetre principal
    def closeEvent(self, event):
        if self.legende.isVisible():
            self.legende.close()
        if self.groupeEdit.isVisible():
            self.groupeEdit.close()
        if self.groupeAdd.isVisible():
            self.groupeAdd.close()
        event.accept()
