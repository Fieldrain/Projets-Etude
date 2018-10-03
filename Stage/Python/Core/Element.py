class C_Element:

    def __init__(self,nom,couleur,statut):
        self._nom=nom
        self._couleur=couleur
        self._statut=statut

    
    def getStatut(self):
        return self._statut

    def getNom(self):
        return self._nom

    def getCouleur(self):
        return self._couleur

    def setStatut(self, s):
        self._statut = s

    def setNom(self, n):
        self._nom = n

    def setCouleur(self, c):
        self._couleur = c
