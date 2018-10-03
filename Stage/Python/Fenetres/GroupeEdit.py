from PyQt5 import QtCore, QtGui, QtWidgets
from UI.UIgroupeEdit import Ui_Form

class F_Groupe(QtWidgets.QWidget, Ui_Form):
 
    def __init__(self, xmlFile, model, parent=None):
        super(F_Groupe, self).__init__(parent)
        self.model = model

        ## on abonne la fenetre au model pour quel recoive les modifications
        self.model.get("stations").abonne(self)
        self.model.get("parametres").abonne(self)

        self.listCur = None
        self.pere = None
        
        self.setupUi(self)

        ## on connecte les evenement a leur fonction
        self.buttonEdit.clicked.connect(self.buttonEdit_clicked)
        self.listViewCur.clicked.connect(self.listViewCur_clicked)
        self.listViewEle.clicked.connect(self.listViewEle_clicked)

## fonction appele quand les models sont modifiés
    def refresh(self):
        
        ## on regarde si la liste courante a ete initialise
        if(self.listCur!=None):
            modelS = self.model.get("stations")
            modelP = self.model.get("parametres")
            self.listNomCur = []
            self.listNomEle = []
            
            ## on recupere la liste element (stations ou parametres)
            if(self.listCur[0].getStatut()=="station"):
                self.listEle = modelS.getListStation()
                
            elif(self.listCur[0].getStatut()=="parametre"):
                self.listEle = modelP.getListParametre()
                
            ## on recupere la liste de nom de la liste courante 
            for elt in self.listCur:
                self.listNomCur.append(elt.getNom())

            ## on recupere la liste de nom de la liste element
            for elt in self.listEle:
                self.listNomEle.append(elt.getNom())
                
            self.init_table()
        
    def init_table(self):
        ## on cree les models des listView
        self.modelCur = QtCore.QStringListModel()
        self.modelEle = QtCore.QStringListModel()

        ## on lie les models aux listView
        self.listViewCur.setModel(self.modelCur)
        self.listViewEle.setModel(self.modelEle)

        #on ajoute les liste dans les models des listView
        self.modelCur.setStringList(self.listNomCur)
        self.modelEle.setStringList(self.listNomEle)

        #on bloque l'edition dans les listes view
        self.listViewCur.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)
        self.listViewEle.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)


    def listViewCur_clicked(self ,item):
        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")

        ## on recupere le nom de l'item selectionne (item.data() change suite au removeRow)
        nomItem = item.data()

        ## on verifie que l'on a au moins un item dans la liste courante
        if(self.modelCur.rowCount()>1):
            
            ## on supprime l'item selectionne
            self.modelCur.removeRow(item.row())

            ## on recupere l'element selectionne
            elt = modelS.getStation(nomItem)
            
            if(elt==None):
                elt = modelP.getParametre(nomItem)

            ## on enleve l'element selectionne de la liste courante
            self.listCur.pop(self.listCur.index(elt))

    def listViewEle_clicked(self, item):
        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")

        ## on recupere la liste courante                     
        liste = self.modelCur.stringList()

        ## on verifie que l'element ne soit pas deja dans la liste du model
        if((item.data() in liste)==0):
            
            ## on ajoute l'item dans la liste
            liste.append(item.data())              

            ## on recupere l'element selectionne
            elt = modelS.getStation(item.data())
            
            if(elt==None):
                elt = modelP.getParametre(item.data())

            ## on ajoute l'element selectionne de la liste courante
            self.listCur.append(elt)

        ## on change la liste du model        
        self.modelCur.setStringList(liste)

    def buttonEdit_clicked(self):
        modelG = self.model.get("groupes")
        modelS = self.model.get("stations")
        modelP = self.model.get("parametres")

        ## on recupere le statut (station ou parametre)
        e = self.listCur[0]
        statut = e.getStatut()

        ## si pere n'est pas nul on modifie donc un groupe
        if(self.pere!=None):
            if (statut == "station"):
                ## on recupere les elements de la liste courante initiale et la liste des elements de la nouvel liste
                listOldFils = modelS.getListStation_Noms(self.listNomCur)
                
            elif (statut == "parametre"):
                listOldFils = modelP.getListParametre_Noms(self.listNomCur)

            listFils = self.listCur

            ## on change le fils du groupe
            modelG.setFils(self.pere,listOldFils,listFils)
            self.close()
            
        else:
            ## on modifie le nom d'une groupe donc on verifie qu'il n'y ai qu'un element
            if(len(self.modelCur.stringList())==1):

                ## on recupere l'element qui correspond au nouveau pere
                nomPere = self.modelCur.stringList()[0]
                if (statut == "station"):
                    newPere = modelS.getStation(nomPere)
                    
                elif (statut == "parametre"):
                    newPere = modelP.getParametre(nomPere)

                ## on change le pere du groupe
                modelG.setPere(self.oldPere,newPere)
                self.close()
                
            else:
                messageBox = QtWidgets.QMessageBox()
                messageBox.setWindowTitle("Erreur")
                messageBox.setText("Vous devez avoir uniquement un nom.")
                messageBox.exec()

    def ouvrir(self, listCur , pere):
        ## on initialise les attributs de la classe
        self.listCur = listCur
        self.pere = pere

        ## on recupere l'ancien nom de groupe si l'on modifie le nom du groupe
        if (self.pere == None):
            self.oldPere = self.listCur[0]
            
        self.refresh()
        self.show()
        

        
