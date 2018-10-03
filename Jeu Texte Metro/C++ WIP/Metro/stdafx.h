// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
//

#pragma once

#include "targetver.h"

#if defined(_WIN32)
#define OS 0
#else
#define OS 1
#endif

#include <iostream>
#include <tchar.h>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <stdarg.h>

using namespace std;

struct Retour
{
	uint8_t code; // numero 1,2,3,4 pour les choix 
	string message;
};

set<string> split(const string &s, char delim) {
	set<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.insert(item);
	}
	return elems;
}

// TODO: faites référence ici aux en-têtes supplémentaires nécessaires au programme
