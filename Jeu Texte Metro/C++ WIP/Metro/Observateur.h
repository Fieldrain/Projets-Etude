#pragma once
#include "Sujet.h"

class IObservateur
{
public:

	virtual ~IObservateur() {}

	virtual void MiseAJour() = 0;

};