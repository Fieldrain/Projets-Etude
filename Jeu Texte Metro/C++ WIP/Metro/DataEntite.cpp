#include "stdafx.h"
#include "DataEntite.h"


DataEntite::DataEntite(string nom) : Nom(nom)
{
	XmlReader::Get("Bestiaire.xml")->GetXPathElementFromRoot("/Entite[@nom=" + nom + "]", true);

	Statistique = new S_Stat();

	Statistique->vie = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Vie",false).begin));
	Statistique->maxVie = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetValueAttributeElement("max",XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Energie", false).begin));

	Statistique->energie = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Energie", false).begin));
	Statistique->maxEnergie = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetValueAttributeElement("max",XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Energie", false).begin));

	Statistique->esquive = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Esquive", false).begin));
	Statistique->resistance = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Resistance", false).begin));
	Statistique->force = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Force", false).begin));
	Statistique->concentration = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Concentration", false).begin));
	Statistique->vitesse = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Vitesse", false).begin));
	Statistique->precision = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Precision", false).begin));
	Statistique->discretion = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetTextElement(XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/Statistique/Discretion", false).begin));

	for each(auto loot in XmlReader::Get("Bestiaire.xml")->GetXPathElementFromLastElement("/LootTable/Objet", false)) {

		S_Objet* objet = new S_Objet();

		objet->nom = XmlReader::Get("Bestiaire.xml")->GetTextElement(loot);
		objet->drop = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetValueAttributeElement("drop", loot));
		objet->quantite = (uint8_t)stoi(XmlReader::Get("Bestiaire.xml")->GetValueAttributeElement("quantite", loot));

		LootTable->objets.insert(objet);
	}

}


DataEntite::~DataEntite()
{
}
