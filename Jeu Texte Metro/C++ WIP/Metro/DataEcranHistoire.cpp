#include "stdafx.h"
#include "DataEcranHistoire.h"

S_Script * DataEcranHistoire::GetScript()
{
	return script;
}

S_Choix * DataEcranHistoire::GetChoix(uint8_t choix)
{
	for each (S_Choix* c in listChoix)
	{
		if (c->numero == choix) {
			return c;
		}
	}

	return NULL;
}

string DataEcranHistoire::GetCodeEcranSuivant(uint8_t choix)
{
	return GetChoix(choix)->codeSuivant;
}


DataEcranHistoire::DataEcranHistoire(string code) : DataEcran(code)
{
	script = new S_Script();
	script->text = XmlReader::Get("Story.xml")->GetTextElement(XmlReader::Get("Story.xml")->GetXPathElementFromLastElement("/Script", false).begin);

	map<string,string> attributs = XmlReader::Get("Story.xml")->GetAttributeElement(XmlReader::Get()->GetXPathElementFromLastElement("/Script", false).begin);

	for each (auto attribut in attributs)
	{
		if (attribut.first == "variable") {
			script->variable = split(attribut.second.data, ';');
		}
		else if (attribut.first == "loot" && attribut.second == "true") {
			loot = new S_ListObjet();
			for each(auto ad in XmlReader::Get("Story.xml")->GetXPathElementFromLastElement("/Loot/Objet", false)) {
				S_Objet* objet = new S_Objet();

				objet->nom = XmlReader::Get("Story.xml")->GetTextElement(ad);
				objet->quantite = (uint8_t)stoi(XmlReader::Get("Story.xml")->GetValueAttributeElement("nb", ad));

				loot->objets.insert(objet);
			}
		}
	}

	listChoix = new S_ListChoix();

	listChoix->nbChoix = (uint8_t)stoi(XmlReader::Get("Story.xml")->GetValueAttributeElement("nbChoix",XmlReader::Get("Story.xml")->GetXPathElementFromLastElement("/Choices", false).begin));

	for each (auto e_choix in XmlReader::Get("Story.xml")->GetXPathElementFromLastElement("/Choices/Choix",false))
	{
		S_Choix* choix = new S_Choix();

		choix->codeSuivant = XmlReader::Get("Story.xml")->GetValueAttributeElement("codeSuivant",e_choix);
		choix->numero = (uint8_t)stoi(XmlReader::Get("Story.xml")->GetValueAttributeElement("numero", e_choix));
		choix->position = (uint8_t)stoi(XmlReader::Get("Story.xml")->GetValueAttributeElement("position", e_choix));
		choix->text = XmlReader::Get("Bestiaire.xml")->GetTextElement(e_choix);

		listChoix->choices.insert(choix);
	}


}


DataEcranHistoire::~DataEcranHistoire()
{
}
