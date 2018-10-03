#pragma once
#include "Constructeur.h"


class Fabrique
{
private:
	Fabrique(const Fabrique&);
	void operator=(const Fabrique&) {};
protected:
	map<string, Constructeur*> constructeurs;
public:
	set<string> Types() const;
	Fabrique();
	~Fabrique();
};

