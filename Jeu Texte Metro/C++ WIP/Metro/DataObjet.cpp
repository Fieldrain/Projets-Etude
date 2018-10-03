#include "stdafx.h"
#include "DataObjet.h"


DataObjet::DataObjet(string nom) : Nom(nom)
{
	XmlReader::Get("Objets.xml")->GetXPathElementFromRoot("/Objet[@nom=" + nom + "]", true);

	Categorie = XmlReader::Get("Objets.xml")->GetValueAttributeElement("categorie");
}


DataObjet::~DataObjet()
{
}
