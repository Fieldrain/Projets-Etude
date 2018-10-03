#include "stdafx.h"
#include "DataEcran.h"


DataEcran::DataEcran(string code) : codeEcranCourant(code)
{
	XmlReader::Get("Story.xml")->GetXPathElementFromRoot("/Ecran[@code=" + code + "]", true);

	type = XmlReader::Get("Story.xml")->GetValueAttributeElement("type");

	res = XmlReader::Get("Story.xml")->GetValueAttributeElement("res");
}


DataEcran::~DataEcran()
{
}

string DataEcran::GetCodeEcran()
{
	return codeEcranCourant;
}

string DataEcran::GetTypeEcran()
{
	return type;
}

string DataEcran::GetResEcran()
{
	return res;
}
