#pragma once
#include "Observateur.h"

class Sujet
{
private:
	set<IObservateur*> listeObservateur;

public:
	void Abonne(IObservateur *o);
	Sujet();
	~Sujet();

protected:
	void Notifie();
};