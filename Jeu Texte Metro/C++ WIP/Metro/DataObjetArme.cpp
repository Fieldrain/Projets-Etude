#include "stdafx.h"
#include "DataObjetArme.h"


DataObjetArme::DataObjetArme(string nom) : DataObjet(nom)
{
	Degat = (uint8_t)stoi(XmlReader::Get("Objets.xml")->GetTextElement(XmlReader::Get("Objets.xml")->GetXPathElementFromLastElement("/Degat",false).begin));
	DegatCritique = (uint8_t)stoi(XmlReader::Get("Objets.xml")->GetTextElement(XmlReader::Get("Objets.xml")->GetXPathElementFromLastElement("/DegatCritique",false).begin));

	Munition = XmlReader::Get("Objets.xml")->GetTextElement(XmlReader::Get("Objets.xml")->GetXPathElementFromLastElement("/Munition",false).begin);
}


DataObjetArme::~DataObjetArme()
{
}
