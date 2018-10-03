#ifndef SUJET_H
#define SUJET_H

#include <vector>
#include "Observateur.h"

using namespace std;

class Sujet
{
private:
	vector<IObservateur*> listeObservateur;

public:
	void Abonne(IObservateur *o);
	Sujet();
	~Sujet();

protected:

	void Notifie();
};

#endif
