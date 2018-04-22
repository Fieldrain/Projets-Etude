#ifndef SUJET_H
#define SUJET_H

#include <set>
#include "Observateur.h"

using namespace std;

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

#endif
