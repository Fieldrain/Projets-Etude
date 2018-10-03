#include "stdafx.h"
#include "DataEcranCombat.h"


string DataEcranCombat::GetCodeEcranSuivant(uint8_t choix)
{
	switch (choix) {
		case 0:
			return victoire->codeSuivant;
			break;
		case 1:
			return defaite->codeSuivant;
			break;
	}
}

set<S_Adversaire*> DataEcranCombat::GetAdversaires()
{
	return listAdversaire;
}

DataEcranCombat::DataEcranCombat(string code) : DataEcran(code)
{
	for each(auto ad in XmlReader::Get("Story.xml")->GetXPathElementFromLastElement("/Adversaires/Adversaire",false)) {
		S_Adversaire* adversaire = new S_Adversaire();

		adversaire->nom = XmlReader::Get("Story.xml")->GetTextElement(ad);
		adversaire->nombre = (uint8_t)stoi(XmlReader::Get("Story.xml")->GetValueAttributeElement("nb", ad));

		listAdversaire.insert(adversaire);
	}

	victoire = new S_Victoire();
	victoire->codeSuivant = (uint8_t)stoi(XmlReader::Get("Story.xml")->GetValueAttributeElement("ecranSuivant",XmlReader::Get("Story.xml")->GetXPathElementFromLastElement("/Victoire", false).begin));

	defaite = new S_Defaite();
	defaite->codeSuivant = (uint8_t)stoi(XmlReader::Get("Story.xml")->GetValueAttributeElement("ecranSuivant", XmlReader::Get("Story.xml")->GetXPathElementFromLastElement("/Defaite", false).begin));

}


DataEcranCombat::~DataEcranCombat()
{
}
