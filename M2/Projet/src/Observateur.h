#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

class IObservateur
{
public:

	virtual ~IObservateur() {}

	virtual void MiseAJour() = 0;

};

#endif