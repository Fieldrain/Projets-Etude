class C_Groupe:

    def __init__(self, parent , listFils):
        self._pere = parent
        self._fils = listFils

    def getFils(self):
        return self._fils

    def getParent(self):
        return self._pere

    def setFils(self, fils, index):
        self._fils[index] = fils

    def setParent(self, parent):
        self._pere = parent

    def removeFils(self,index):
        self._fils.pop(index)

    def addFils(self, fils):
        if((fils in self._fils)==0):
            self._fils.append(fils)
