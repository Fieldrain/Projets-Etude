#include "stdafx.h"
#include "Fabrique.h"


set<string> Fabrique::Types() const
{
	set<string> types;

	for each (auto cons in constructeurs)
	{
		types.insert(cons.first);
	}

	return types;
}

Fabrique::Fabrique()
{
}


Fabrique::~Fabrique()
{
	for (auto p : constructeurs)
		delete p.second;
}
