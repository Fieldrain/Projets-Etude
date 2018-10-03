#include "stdafx.h"
#include "DataObjetSoin.h"


DataObjetSoin::DataObjetSoin(string nom) : DataObjet(nom)
{
	Soin = (uint8_t)stoi(XmlReader::Get("Objets.xml")->GetTextElement(XmlReader::Get("Objets.xml")->GetXPathElementFromLastElement("/Soin", false).begin));
}


DataObjetSoin::~DataObjetSoin()
{
}
