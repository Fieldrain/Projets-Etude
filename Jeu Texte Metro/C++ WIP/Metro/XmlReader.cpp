#include "stdafx.h"
#include "XmlReader.h"


set<TiXmlElement*> XmlReader::GetXPathElementFromRoot(string requeteXpath, bool replace)
{
	set<TiXmlElement*> elements;

	string req = "count(" + requeteXpath + ")";
	xpath_processor procCount(root[fileName], req.c_str());
	uint8_t nbResult = procCount.i_compute_xpath();

	xpath_processor proc(root[fileName], requeteXpath.c_str());

	for (uint8_t i = 0; i < nbResult; i++)
	{
		TiXmlElement* el = (TiXmlElement*)proc.XNp_get_xpath_node(i);
		if (replace) {
			lastElement[fileName] = el;
		}

		elements.insert(el);
	}

	return elements;
}

set<TiXmlElement*> XmlReader::GetXPathElementFromElement(TiXmlElement * element, string requeteXpath, bool replace)
{
	set<TiXmlElement*> elements;

	string req = "count(" + requeteXpath + ")";
	xpath_processor procCount(element, req.c_str());
	uint8_t nbResult = procCount.i_compute_xpath();

	xpath_processor proc(element, requeteXpath.c_str());

	for (uint8_t i = 0; i < nbResult; i++)
	{
		TiXmlElement* el = (TiXmlElement*)proc.XNp_get_xpath_node(i);
		if (replace) {
			lastElement[fileName] = el;
		}

		elements.insert(el);
	}

	return elements;
}

set<TiXmlElement*> XmlReader::GetXPathElementFromLastElement(string requeteXpath, bool replace)
{
	set<TiXmlElement*> elements;

	string req = "count(" + requeteXpath + ")";
	xpath_processor procCount(lastElement[fileName], req.c_str());
	uint8_t nbResult = procCount.i_compute_xpath();

	xpath_processor proc(lastElement[fileName], requeteXpath.c_str());

	for (uint8_t i = 0; i < nbResult; i++)
	{
		TiXmlElement* el = (TiXmlElement*)proc.XNp_get_xpath_node(i);
		if (replace) {
			lastElement[fileName] = el;
		}

		elements.insert(el);
	}

	return elements;
}

string XmlReader::GetTextElementFromRoot(string requeteXpath)
{
	return GetTextElement(GetXPathElementFromRoot(requeteXpath,false).begin);
}

string XmlReader::GetTextElement(TiXmlElement * element)
{
	if (element) {
		return element->GetText();
	}
	else {
		return lastElement[fileName]->GetText();
	}
	
}

map<string, string> XmlReader::GetAttributeElement(TiXmlElement * element)
{
	if (!element)
		element = lastElement[fileName];

	map<string, string> listAttribut;

	TiXmlAttribute* courAt = element->FirstAttribute();

	while (courAt!=element->LastAttribute()) {

		listAttribut[courAt->Name()] = courAt->Value();

		courAt = courAt->Next();
	}

	return listAttribut;
}

string XmlReader::GetValueAttributeElement(string name ,TiXmlElement * element)
{
	if (element) {
		return element->Attribute(name.c_str());
	}
	else {
		return lastElement[fileName]->Attribute(name.c_str());
	}
	
}

XmlReader * XmlReader::Get(string file_name)
{
	if (!instance) {
		instance = new XmlReader(file_name);
	}
	else {
		if (listFileName.find(file_name) != listFileName.cend) {

			doc[file_name] = TiXmlDocument(file_name.data.c_str());
			if (!doc[file_name].LoadFile()) {
				cout << "Erreur de chargement fichier " + fileName << endl;
			}
			else {
				listFileName.insert(file_name);
				root[file_name] = doc[file_name].RootElement();
			}
		}
		
		fileName = file_name;
	}

	return instance;
}

XmlReader::XmlReader(string file_name)
{
	doc[file_name] = TiXmlDocument(file_name.data.c_str());
	if (!doc[file_name].LoadFile()) {
		cout << "Erreur de chargement fichier "+ fileName << endl;
	}
	else {
		fileName = file_name;
		listFileName.insert(file_name);
		root[fileName] = doc[fileName].RootElement();
		
	}
}


XmlReader::~XmlReader()
{
	for (auto d : doc)
		d.second.~TiXmlDocument();

	for (auto r : root)
		delete r.second;

	for (auto le : lastElement)
		delete le.second;
}
