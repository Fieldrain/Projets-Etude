from Core.Element import C_Element

class C_Parametres:

    def __init__(self,xmlFile):
        self._parametres = {}
        self._vues = []
        listParametres = xmlFile.searchXml("Parametres")
        for parametre in listParametres:
            nom = parametre.get("nom")
            couleur = parametre.get("couleur")

            newParametre = C_Element(nom,couleur,"parametre")
            
            self._parametres[nom]= newParametre

    def abonne(self, vue):
        trouver = 0
        for v in self._vues:
            if (v == vue):
                trouver = 1

        if (trouver==0):
            self._vues.append(vue)

    def getListParametre(self):
        listParametres = []
        parametres = list(sorted(self._parametres.keys()))
        for parametre in parametres:
            listParametres.append(self._parametres.get(parametre))
            
        return listParametres

    def getListParametre_Noms(self, listNom):
        listeParametres = []
        for nom in listNom:
            listeParametres.append(self.getParametre(nom))
        return listeParametres

    def getParametre(self, nom):
        return self._parametres.get(nom)

    def getListNomParametre(self):
        return list(sorted(self._parametres.keys()))

    def getListCouleur(self):
        return list(self._parametres.values())

    def getCouleurParametre(self, nom):
        parametre = self._parametres.get(nom)
        return parametre.getCouleur()
        
    def setCouleurParametre(self, nom , couleur):
        parametre = self._parametres.get(nom)
        parametre.setCouleur(couleur)
        
        self.update()

    def setNomParametre(self, nomAvant, nomChanger):
        parametre = self._parametres.get(nomAvant)
        parametre.setNom(nomChanger)

        self._parametres[nomChanger] = self._parametres.pop(nomAvant)
        
        self.update()
        
    def update(self):
        for vue in self._vues:
            vue.refresh()
