#include "stdafx.h"
#include "Sujet.h"

Sujet::Sujet()
{
}

Sujet::~Sujet()
{
	for (IObservateur* o : listeObservateur) {
		delete o;
	}

}

void Sujet::Notifie() {
	for (IObservateur* o : listeObservateur) {
		o->MiseAJour();
	}
}

void Sujet::Abonne(IObservateur *o) {
	listeObservateur.insert(o);
}
