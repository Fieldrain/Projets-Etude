#include "GestionRegex.h"

GestionRegex *GestionRegex::instance = nullptr;

GestionRegex::GestionRegex(){
    dictionnaire["Ensemble"] = "\\{[\\s\\S]+?\\}";
    dictionnaire["Objet"] = "\\'\\w+\\'(.*)\\:(\\s*)\\[[\\s\\S]*?\\]";
    dictionnaire["Type"] = "\\'\\w+\\'(.*)\\:(\\s*)\\[";
    dictionnaire["Proprietes"] = "\\[[\\s\\S]*?\\]";
    dictionnaire["Label"] = "label\\s*:\\s*\\w*\\,?";
    dictionnaire["Point"] = "point[\\s\\S]*\\)\\,?";
    dictionnaire["Dimension"] = "dimension\\s*:\\s*\\w*\\,?";
    dictionnaire["CoupleNomValeur"] = "\\'[\\s\\S]*?\\'\\:[\\s\\S]*\\,?";
    dictionnaire["EnsemblePoint"] = "\\((\\,?\\d+(\\.\\d+)?)+\\)";
    
    dictionnaire["Etat"] = "\\@\\w+(.*)\\:(\\s*)\\[[\\s\\S]*?\\]";
    dictionnaire["LabelAutomate"] = "\\@\\w+(.*)\\:(\\s*)\\[";
    dictionnaire["EtatsSuivant"] = "etats[\\s\\S]*?\\;";
    dictionnaire["Transition"] = "transitions[\\t\\ \\S\\s]*\\)*\\)\\'?\\;";
    dictionnaire["CoupleNomMat"] = "\\'[\\S]*?\\'\\:[\\s\\S]*?\\)\\;";
    dictionnaire["Forme"] = "forme\\s*:\\s*\\w*\\;?";
    dictionnaire["EnsembleTransition"] = "\\([\\s\\S]*?(\\),|\\);)";
    dictionnaire["Mat"] = "\\([\\.\\d\\s\\,\\;\\/\\-]*\\)";
    dictionnaire["NomMat"] = "\\([\\S]*?\\)";
    dictionnaire["Operateur"] = "\\).\\(";

    dictionnaire["ValMat"] = ":\\s*[\\s\\S]*\\)\\;";
    dictionnaire["ValDoublePoint"] = ":\\s*[\\d\\w]*(\\;|\\,)?";
    dictionnaire["ValA"] = "\\@\\w+";
    dictionnaire["ValCote"] = "\\'\\w+\\'";
    dictionnaire["ValPar"] = "\\(\\w+\\)";
    dictionnaire["ValPoint"] = "\\-?\\d+(\\.\\d+)?(\\/\\-?\\d+(\\.\\d+)?)?";
    dictionnaire["ValLigneMat"] = "(\\,?\\-?\\d+(\\.\\d+)?\\/?)+";
    dictionnaire["ValSlash"] = "\\d+(\\.\\d+)?";

    dictionnaire["Scene"] = "scene\\s*:\\s*\\S*\\;";
    dictionnaire["Iteration"] = "iteration\\s*:\\s*\\w*\\;";
    dictionnaire["Repere"] = "repere\\s*:\\s*\\w*\\;";
    dictionnaire["ValChemin"] = "\"\\S*\"";
    dictionnaire["FragShader"] = "fragShader\\s*:\\s*\\S*\\;";
    dictionnaire["VertShader"] = "vertShader\\s*:\\s*\\S*\\;";
    dictionnaire["Textures"] = "textures\\s*:\\s*\\S*\\;";
}

GestionRegex* GestionRegex::Instance(){
    if(!instance){
        instance = new GestionRegex();
    }

    return instance;
}

vector<string> GestionRegex::ApplyRegex(string chaine,string NomRegex){
    vector<string> chainesMatch;
    smatch ensembles;

    regex reg(dictionnaire.at(NomRegex));

    string::const_iterator searchStart(chaine.cbegin());
    while (regex_search(searchStart, chaine.cend(), ensembles, reg))
    {
        chainesMatch.push_back(ensembles[0]);
        searchStart += ensembles.position() + ensembles.length();
    }

    return chainesMatch;
}

string GestionRegex::SupprimeChar(string chaine,char c){
    
    chaine.erase(remove(chaine.begin(), chaine.end(), c), chaine.end());

    return chaine;
}

bool GestionRegex::FindChar(string chaine,char c){
    return chaine.find(c) != string::npos;
}

int GestionRegex::CountMatchInRegex(string chaine, regex reg)
{
    return (int)distance(sregex_iterator(chaine.begin(), chaine.end(), reg), sregex_iterator());
}