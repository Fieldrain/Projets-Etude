// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s
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

// TODO: faites r�f�rence ici aux en-t�tes suppl�mentaires n�cessaires au programme
