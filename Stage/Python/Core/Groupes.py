from Core.Groupe import C_Groupe

class C_Groupes:

    def __init__(self,listStation,listParametre, xmlFile):
        self._groupes = {}
        self._vues = []
        listParent = xmlFile.searchXml("Groupes")
        i = 0
        
        for parent in listParent:
            listFils = []
            pere = None
            
            if (self._estDans(parent.tag,listStation)==1):
                pere = self._rechercheElt(parent.tag,listStation)
                listFils = self._rechercheFils(parent,listParametre)
                
            elif (self._estDans(parent.tag,listParametre)==1):
                pere = self._rechercheElt(parent.tag,listParametre)
                listFils = self._rechercheFils(parent,listStation)
                
            if(pere):
                self._groupes[i] = C_Groupe(pere, listFils)
                i += 1
                

    def _estDans(self, nom, liste):
        trouver = 0
        
        for n in liste:
            
            if(nom==n.getNom()):
                trouver=1
                
        return trouver

    def _rechercheElt(self, nomElt , listEle):
        
        for elt in listEle:
            
            if (elt.getNom() == nomElt):
                return elt

    def _rechercheFils(self,parent, listEle):
        listFils = []
        
        for fils in parent:
            liste = []
            nomFils= fils.text.split(",")
            
            for nom in nomFils:
                eltFils = self._rechercheElt(nom , listEle)
                
                if(eltFils):
                    liste.append(eltFils)
                    
            listFils.append(liste)
            
        return listFils
                

    def abonne(self, vue):
        trouver = 0
        for v in self._vues:
            if (v == vue):
                trouver = 1

        if (trouver==0):
            self._vues.append(vue)

    def getListNomParent(self):
        listParent = []

        for groupe in self._groupes.values():
            parent = groupe.getParent()
            listParent.append(parent.getNom())

        return listParent

    def getGroupe(self, nomPere):
        groupe = None
        
        for g in list(self._groupes.values()):
            parent = g.getParent()
            
            if(parent.getNom()==nomPere):
                groupe = g
                
        return groupe

    def getFils(self, i):
        groupe = self._groupes.get(i)
        labelFils = []
        listFils = groupe.getFils()
        
        for listElt in listFils:
            label = ""
            
            for elt in listElt:
                label += elt.getNom()+" "
                
            labelFils.append(label)
            
        return labelFils

    def setFils(self, pere, fils , newFils):
        
        for groupe in list(self._groupes.values()):
            parent = groupe.getParent()
            
            if(parent.getNom()==pere.getNom()):
                index = groupe.getFils().index(fils)
                groupe.setFils(newFils, index)

        self.update()

    def setPere(self , pere, newPere):

        listeParent = []

        for groupe in list(self._groupes.values()):
            parent = groupe.getParent()
            listeParent.append(parent.getNom())

        if((newPere.getNom() in listeParent) == 1):
            groupe = self.getGroupe(newPere.getNom())
            oldGroupe = self.getGroupe(pere.getNom())
            fils = oldGroupe.getFils()
            
            for f in fils:
                groupe.addFils(f)

            self.removeGroupe(oldGroupe)
            
        else:
            for groupe in list(self._groupes.values()):
                parent = groupe.getParent()
                
                if(parent.getNom()==pere.getNom()):
                    groupe.setParent(newPere)
                
        self.update()

    def removeFils(self, pere, fils):
        groupes = list(self._groupes.values())
        for i in range(0,len(groupes)):
            groupe = groupes[i]
            parent = groupe.getParent()
            
            if(parent.getNom()==pere.getNom()):
                index = groupe.getFils().index(fils)
                groupe.removeFils(index)

            if(len(groupe.getFils())==0):
                self.removeGroupe(groupe)
                
        self.update()

    def removeGroupe(self, groupe):
        dictTemp = self._groupes.copy()
        self._groupes.clear()
        i = 0    
        for key in dictTemp.keys():
            g = dictTemp.get(key)
            if(g != groupe):
                self._groupes[i] = dictTemp.get(key)
                i += 1

    def addGroupe(self,newPere,newFils):
        ajout = 0
        for key in self._groupes.keys():
            groupe = self._groupes.get(key)
            pere = groupe.getParent()
            

            if(pere.getNom()==newPere.getNom()):
                ajout = 1
                
                if(newFils in groupe.getFils() == 0):
                    groupe.addFils(newFils)
                
                
        if (ajout==0):
            listFils = []
            listFils.append(newFils)
            newGroupe = C_Groupe(newPere,listFils)
            self._groupes[len(self._groupes)] = newGroupe
            
        self.update()

    def update(self):
        for vue in self._vues:
            vue.refresh()
