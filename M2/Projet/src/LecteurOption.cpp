#include "LecteurScene.h"

LecteurOption::LecteurOption()
{
}

LecteurOption::~LecteurOption()
{
    Fermer();
}

void LecteurOption::Ouvrir()
{
    fichier = ifstream("ressources/options.txt", ios::in); // on ouvre le fichier en lecture
}

OptionScene LecteurOption::Lire()
{
    GestionRegex* gestReg = GestionRegex::Instance();
    OptionScene opScene;

    if (fichier)
    {
        string contenu((istreambuf_iterator<char>(fichier)), istreambuf_iterator<char>());

        string scene = gestReg->ApplyRegex(contenu,"Scene")[0];
        cout << scene <<endl;
        opScene.cheminFichier = gestReg->ApplyRegex(scene, "ValChemin")[0];       // recupere la valeur entre parenthese
        opScene.cheminFichier = gestReg->SupprimeChar(opScene.cheminFichier, '"');

        string iteration = gestReg->ApplyRegex(contenu,"Iteration")[0];
        cout << iteration <<endl;
        string ite = gestReg->ApplyRegex(iteration, "ValDoublePoint")[0];
        ite = gestReg->SupprimeChar(ite, ':');
        ite = gestReg->SupprimeChar(ite, ';');

        opScene.iterationModele = (int) stoi(ite);
        opScene.iterationTangente = opScene.iterationModele;

        string repere = gestReg->ApplyRegex(contenu,"Repere")[0];
        cout << repere <<endl;
        string rep = gestReg->ApplyRegex(repere, "ValDoublePoint")[0];
        rep = gestReg->SupprimeChar(rep, ':');
        rep = gestReg->SupprimeChar(rep, ';');
        rep = gestReg->SupprimeChar(rep, ' ');

        
        if(rep == "2D"){
            opScene.repere = DEUXD;
        }else{
            opScene.repere = TROISD;
        }

        string fragShader = gestReg->ApplyRegex(contenu,"FragShader")[0];
        cout << fragShader <<endl;
        opScene.fragShader = gestReg->ApplyRegex(fragShader, "ValChemin")[0];       // recupere la valeur entre parenthese
        opScene.fragShader = gestReg->SupprimeChar(opScene.fragShader, '"');

        string vertShader = gestReg->ApplyRegex(contenu,"VertShader")[0];
        cout << vertShader <<endl;
        opScene.vertShader = gestReg->ApplyRegex(vertShader, "ValChemin")[0];       // recupere la valeur entre parenthese
        opScene.vertShader = gestReg->SupprimeChar(opScene.vertShader, '"');

        string textures = gestReg->ApplyRegex(contenu,"Textures")[0];
        cout << textures <<endl;
        opScene.cheminTextures = gestReg->ApplyRegex(textures, "ValChemin")[0];       // recupere la valeur entre parenthese
        opScene.cheminTextures = gestReg->SupprimeChar(opScene.cheminTextures, '"');

    }
    else
    {
        cout << "Erreur Ouverture Fichier";
    }

    return opScene;
}

void LecteurOption::Fermer()
{
    fichier.close();
}