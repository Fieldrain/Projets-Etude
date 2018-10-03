#pragma once

#include <set>
#include "Observateur.h"

class Sujet
{
private:
	std::set<IObservateur*> listeObservateur;

public:
	void Abonne(IObservateur *o);
	Sujet();
	~Sujet();

protected:

	void Notifie();
};

