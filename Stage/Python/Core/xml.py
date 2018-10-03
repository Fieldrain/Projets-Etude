from lxml import etree

class XmlFile:
## Classe permettant de gerer le fichier xml stockant les legendes de l'application
    def __init__(self):
        self.xml = etree.parse("Config/legende.xml")
        self.root = self.xml.getroot()

    def searchXml(self, cible):
        ## function qui renvoie un dictionnaire avec les elements (cible) recherche dans le fichier xml
        ## exemple : si cible = Stations la fonction renvoie toutes les éléments Station
        cibles = []
        for child in self.root:
            if child.tag==cible:
                for elt in child:
                    cibles.append(elt)
        return cibles
