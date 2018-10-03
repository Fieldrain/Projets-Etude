from Core.Element import C_Element

class C_Stations:

    def __init__(self,xmlFile):
        self._stations = {}
        self._vues = []
        listStations = xmlFile.searchXml("Stations")
        for station in listStations:
            nom = station.get("nom")
            couleur = station.get("couleur")
            
            newStation = C_Element(nom,couleur,"station")
                
            self._stations[nom]= newStation
        

    def abonne(self, vue):
        trouver = 0
        for v in self._vues:
            if (v == vue):
                trouver = 1

        if (trouver==0):
            self._vues.append(vue)

    def getListStation(self):
        listStations = []
        stations = list(sorted(self._stations.keys()))
        for station in stations:
            listStations.append(self._stations.get(station))
            
        return listStations

    def getListStation_Noms(self, listNom):
        listeStations = []
        for nom in listNom:
            listeStations.append(self.getStation(nom))
        return listeStations

    def getStation(self, nom):
        return self._stations.get(nom)

    def getListNomStation(self):
        return list(sorted(self._stations.keys()))

    def getListCouleur(self):
        listCouleur = []
        for station in self._stations.values():
            listCouleur.append(station.getCouleur())
        return listCouleur

    def getCouleurStation(self, nom):
        station = self._stations.get(nom)
        return station.getCouleur()
        
    def setCouleurStation(self, nom , couleur):
        station = self._stations.get(nom)
        station.setCouleur(couleur)
        
        self.update()

    def setNomStation(self, nomAvant, nomChanger):
        station = self._stations.get(nomAvant)
        station.setNom(nomChanger)
        
        self._stations[nomChanger] = self._stations.pop(nomAvant)
        
        self.update()
        
    def update(self):
        for vue in self._vues:
            vue.refresh()
