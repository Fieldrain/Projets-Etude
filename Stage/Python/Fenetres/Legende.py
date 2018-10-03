from PyQt5 import QtCore, QtGui, QtWidgets
from UI.UIlegende import Ui_Form

class F_Legende(QtWidgets.QWidget, Ui_Form):
 
    def __init__(self, xmlFile, model, parent=None):
        super(F_Legende, self).__init__(parent)
        self.model = model
        
        ## on abonne la fenetre au model pour quel recoive les modifications
        self.model.get("stations").abonne(self)
        self.model.get("parametres").abonne(self)
        
        self.setupUi(self)
        self.refresh()
    
    def refresh(self):
        self.init_Table()
        
        ## on connect l'evenement clicked des deux tableaux a la fonction getSelection
        self.tableViewStation.clicked.connect(self.getSelectionStation)
        self.tableViewParametre.clicked.connect(self.getSelectionParametre)
        
        ## on connect l'evenement doubleclicked des deux tableaux a la fonction getDoubleClicked
        self.tableViewStation.doubleClicked.connect(self.getDoubleClicked)
        self.tableViewParametre.doubleClicked.connect(self.getDoubleClicked)

        ## on connect l'evenement dataChanged des deux tableaux a la fonction getDataChanged
        self.tableViewStation.model().dataChanged.connect(self.getDataChangedStation)        
        self.tableViewParametre.model().dataChanged.connect(self.getDataChangedParametre)

        
    def init_Table(self):
        ## on recupere les models
        modelSta = self.model.get("stations")
        modelPar = self.model.get("parametres")
        
        ## on recupere la liste des stations       
        stations = modelSta.getListStation()

        ## on recupere la liste des parametres
        parametres = modelPar.getListParametre()
        
        listeHeader = ["Nom","Code Couleur"]

        ## on place les headers des deux model de tableau
        self.modelTabStation = QtGui.QStandardItemModel()
        self.modelTabStation.setHorizontalHeaderLabels(listeHeader)

        self.modelTabParametre = QtGui.QStandardItemModel()
        self.modelTabParametre.setHorizontalHeaderLabels(listeHeader)

        ## on lie les model aux vus
        self.tableViewStation.setModel(self.modelTabStation)
        self.tableViewParametre.setModel(self.modelTabParametre)

        ## on enleve les header verticale et un met les tableau en selection unique
        self.tableViewParametre.verticalHeader().setVisible(0)
        self.tableViewParametre.setSelectionMode(QtWidgets.QAbstractItemView.SingleSelection)

        self.tableViewStation.verticalHeader().setVisible(0)
        self.tableViewStation.setSelectionMode(QtWidgets.QAbstractItemView.SingleSelection)  

        ## on initialise le contenu des tableaux
        self.init_TabStations(stations, modelSta)
        self.init_TabParametres(parametres, modelPar) 

## fonction qui initialise le contenu du tableau station       
    def init_TabStations(self, stations , modelSta):
        
        for i in range(0,len(stations)):
           station = stations[i]
           itemNom = QtGui.QStandardItem(station.getNom())

           ## on recupere la couleur sous la forme 255,255,255
           couleurStation = station.getCouleur()

           ## on split la chaine pour avoir les valeurs separement
           codeRgb = couleurStation.split(",")

           ##on creer la couleur et le brush pour l'item
           couleur = QtGui.QColor(int(codeRgb[0]),int(codeRgb[1]),int(codeRgb[2]),255)
           brush = QtGui.QBrush(couleur)
           
           itemCouleur = QtGui.QStandardItem()
           itemCouleur.setBackground(brush)
           itemCouleur.setEditable(0)

           self.modelTabStation.insertRow(i,[itemNom,itemCouleur])

## fonction qui initialise le contenu du tableau parametre  
    def init_TabParametres(self, parametres, modelPar):
        for i in range(0,len(parametres)):
           parametre = parametres[i] 
           itemNom = QtGui.QStandardItem(parametre.getNom())

           ## on recupere la couleur sous la forme 255,255,255
           couleurParametre = parametre.getCouleur()

           ## on split la chaine pour avoir les valeurs separement
           codeRgb = couleurParametre.split(",")

           ## on creer la couleur et le brush pour l'item
           couleur = QtGui.QColor(int(codeRgb[0]),int(codeRgb[1]),int(codeRgb[2]),255)
           brush = QtGui.QBrush(couleur)
           
           itemCouleur = QtGui.QStandardItem()
           itemCouleur.setBackground(brush)
           itemCouleur.setEditable(0)

           ## on ajoute les item dans le model du tableau
           self.modelTabParametre.insertRow(i,[itemNom,itemCouleur])

## fonction appele quand l'on double clique dans le tableau
## on change la valeur de cureentItemData qui contient les donnees de l'objet sur lequel on a double clicquer
    def getDoubleClicked(self, item):
        if(item.column()==0):
            self.currentItemData = item.data()
            
## fonction appele quand une donne change dans le tableau station
    def getDataChangedStation(self,item):
        model = self.model.get("stations")
        
        if(item.column()==0):
           model.setNomStation(self.currentItemData,item.data())
           
## fonction appeler quand une donne change dans le tableau parametre           
    def getDataChangedParametre(self,item):
        model = self.model.get("parametres")
        
        if(item.column()==0):
           model.setNomParametre(self.currentItemData,item.data())
           
## fonction appele quand l'utilisateur clique sur un case de l'onglet Station
    def getSelectionStation(self,item):

        ## on regarde si l'item selectionne est dans la colonnes couleur
        if(item.column()==1):
            ## on recupere le model de l'item pour le changer
            itemMod = self.modelTabStation.item(item.row(),1)

            ## on change la couleur de l'item
            self.colorChange(itemMod)

        ## on deselectionne tous les items situees sur ou dans le rectangle(le tableau)  
        self.tableViewStation.setSelection(QtCore.QRect(0,0,2,item.row()+1),QtCore.QItemSelectionModel.Clear)

## fonction appele quand l'utilisateur clique sur un case de l'onglet Parametre    
    def getSelectionParametre(self, item):
        ## meme fonctionnement que la fonction getSelectionStation
        if(item.column()==1):
            itemMod = self.modelTabParametre.item(item.row(),1)
            self.colorChange(itemMod)
            
        self.tableViewParametre.setSelection(QtCore.QRect(0,0,2,item.row()+1),QtCore.QItemSelectionModel.Clear)

## fonction qui change la couleur de fond de l'item selectioner
## utilise un colordialog pour la selection de la couleur
    def colorChange(self, itemMod):
        colorDialog = QtWidgets.QColorDialog(self)
        brush = itemMod.background()

        color = colorDialog.getColor(brush.color())
        brush.setColor(color)
        itemMod.setBackground(brush)
                     
