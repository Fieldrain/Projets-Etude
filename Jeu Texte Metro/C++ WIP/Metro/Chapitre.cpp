#include "stdafx.h"
#include "Chapitre.h"


DataEcran* Chapitre::GetEcranCourant()
{
	return ecranCourant;
}

uint8_t Chapitre::GetNumeroChapitre()
{
	return numeroChapitre;
}

bool Chapitre::EcranSuivant(uint8_t choix)
{
	string codeEcranSuivant = ecranCourant->GetCodeEcranSuivant(choix);
	string res = ecranCourant->GetResEcran();

	delete ecranCourant;

	if (res == "FinChapitre") {
		return ChangerChapitre(numeroChapitre, codeEcranSuivant);
	}
	else if(res =="GameOver"){
		return false;
	}
	else {
		string type = XmlReader::Get("Story.xml")->GetValueAttributeElement("Type", XmlReader::Get("Story.xml")->GetXPathElementFromRoot("/Ecran[@code=" + codeEcranSuivant + "]", false).begin);
		fabrique->Get(type, codeEcranSuivant);

		//change elementCourant par le chapitre
		string num = (char*)numeroChapitre;
		XmlReader::Get("Story.xml")->GetXPathElementFromRoot("/Story/Chapitre[@numero=" + num + "]", true);

		return true;
	}
}

bool Chapitre::ChangerChapitre(uint8_t numeroAncienChapitre, string codeEcran)
{
	uint8_t nbChapitre = (uint8_t)atoi((XmlReader::Get("Story.xml")->GetTextElementFromRoot("/Story/NbChapitre").data()));

	if (numeroAncienChapitre+1 <= nbChapitre) {
		string num = (char*)numeroAncienChapitre+1;
		XmlReader::Get("Story.xml")->GetXPathElementFromRoot("/Story/Chapitre[@numero=" + num + "]",true).begin;

		if (codeEcran == "null") {
			codeEcran = (char*)((numeroAncienChapitre + 1)*10);
		}

		string type = XmlReader::Get("Story.xml")->GetValueAttributeElement("Type", XmlReader::Get("Story.xml")->GetXPathElementFromRoot("/Ecran[@code=" + codeEcran + "]", false).begin);
		ecranCourant = (DataEcran*)fabrique->Get(type,codeEcran);

		//change elementCourant par le chapitre
		XmlReader::Get("Story.xml")->GetXPathElementFromRoot("/Story/Chapitre[@numero=" + num + "]", true).begin;
		return true;
	}
	else {
		return false;
	}
}

Chapitre::Chapitre() : fabrique(new FabriqueData())
{
	ChangerChapitre(0, "00");
}

Chapitre::Chapitre(uint8_t numero, string ecran) : fabrique(new FabriqueData())
{
	ChangerChapitre(numero,ecran);
}

Chapitre::~Chapitre()
{
	delete fabrique;
	delete ecranCourant;
}
