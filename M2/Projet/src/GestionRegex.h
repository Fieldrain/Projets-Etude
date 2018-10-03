#ifndef GESTIONREGEX_H
#define GESTIONREGEX_H

#include <regex>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class GestionRegex{

public:
    static GestionRegex* Instance();
    vector<string> ApplyRegex(string chaine,string NomRegex);
    string SupprimeChar(string chaine,char c);
    bool FindChar(string chaine,char c);
    int CountMatchInRegex(string chaine, regex reg);

private:
    static GestionRegex *instance;
    map<string, string> dictionnaire;

    GestionRegex& operator= (const GestionRegex&){}
    GestionRegex (const GestionRegex&){}
    
    GestionRegex();
    ~GestionRegex();
};

#endif