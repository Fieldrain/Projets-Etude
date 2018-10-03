#include "Sujet.h"


Sujet::Sujet()
{
}


Sujet::~Sujet()
{
	listeObservateur.clear();
}


void Sujet::Notifie(){
	for(int i=0;i<listeObservateur.size();i++){
		listeObservateur[i]->MiseAJour();
	}
}

void Sujet::Abonne(IObservateur *o){
	listeObservateur.push_back(o);
}