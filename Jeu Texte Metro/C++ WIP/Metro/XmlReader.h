#pragma once
#include <tinyxml.h>
#include <xpath_processor.h>

using namespace TinyXPath;

class XmlReader
{
private:
	static XmlReader* instance;
	static set<string> listFileName;
	static string fileName;
	static map<string, TiXmlDocument> doc;
	static map<string, TiXmlElement*> root;
	map<string, TiXmlElement*> lastElement;

	XmlReader(string file_name);
	XmlReader(const XmlReader&);
public:
	set<TiXmlElement*> GetXPathElementFromRoot(string requeteXpath, bool replace);

	set<TiXmlElement*> GetXPathElementFromElement(TiXmlElement* element, string requeteXpath, bool replace);

	set<TiXmlElement*> GetXPathElementFromLastElement(string requeteXpath, bool replace);

	string GetTextElementFromRoot(string requeteXpath);

	string GetTextElement(TiXmlElement* element=NULL);

	map<string,string> GetAttributeElement(TiXmlElement* element=NULL);

	string GetValueAttributeElement(string name, TiXmlElement* element=NULL);

	static XmlReader* Get(string file_name);
	
	~XmlReader();

	
};

