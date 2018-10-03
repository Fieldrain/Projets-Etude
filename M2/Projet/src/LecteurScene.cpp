#include "LecteurScene.h"

LecteurScene::LecteurScene(string CheminFichier) : chemin(CheminFichier)
{
}

LecteurScene::~LecteurScene()
{
    Fermer();
}

void LecteurScene::Ouvrir()
{
    fichier = ifstream(chemin, ios::in); // on ouvre le fichier en lecture
}

void LecteurScene::Lire(Scene *scene)
{
    GestionRegex* gestReg = GestionRegex::Instance();

    if (fichier)
    {
        string contenu((istreambuf_iterator<char>(fichier)), istreambuf_iterator<char>());

        
        map<string, Object *> formes;
        map<string, Etat *> etats;
        for (string ensemble : gestReg->ApplyRegex(contenu, "Ensemble"))
        {
            /*
                Recupere toutes les formes
            */
            formes = LireObject(ensemble, formes);

            /*
                Recupere tous les etats
            */
            etats = LireAutomate(ensemble, formes, etats);
        }
        if(etats.find("Uv") != etats.end())
            scene->AddIfs("Root", new Ifs(etats["Geometry"],etats["Uv"]));
        else
            scene->AddIfs("Root", new Ifs(etats["Geometry"]));
    }
    else
    {
        cout << "Erreur Ouverture Fichier";
    }
}

map<string, Object *> LecteurScene::LireObject(string ensemble, map<string, Object *> formes)
{
    GestionRegex* gestReg = GestionRegex::Instance();

    FabriqueObject *fabriqueObj = new FabriqueObject();

    for (string objet : gestReg->ApplyRegex(ensemble, "Objet"))
    {

        string type = gestReg->ApplyRegex(objet, "Type")[0]; // recupere la ligne qui contient type d'objet exemple : 'class': [
        type = gestReg->ApplyRegex(type, "ValCote")[0];      // recupere la valeur entre simple cote
        type = gestReg->SupprimeChar(type, '\'');
        transform(type.begin(), type.end(), type.begin(), toupper);

        string proprietes = gestReg->ApplyRegex(objet, "Proprietes")[0]; //recupere ce qui est entre crochet

        string labelObjet = gestReg->ApplyRegex(proprietes, "Label")[0]; // recupere la ligne qui contient le label de l'objet exemple : label : (valeur),
        labelObjet = gestReg->ApplyRegex(labelObjet, "ValDoublePoint")[0]; // recupere la valeur entre parenthese
        labelObjet = gestReg->SupprimeChar(labelObjet, ':');
        labelObjet = gestReg->SupprimeChar(labelObjet, ',');

        TypeObject typeObj = fabriqueObj->StringToType(type);
        Object *obj = fabriqueObj->ConstruitObject(typeObj, proprietes);

        formes[labelObjet] = obj;
    }

    delete fabriqueObj;
    return formes;
}

map<string, Etat *> LecteurScene::LireAutomate(string ensemble, map<string, Object *> formes, map<string, Etat *> etats)
{
    GestionRegex* gestReg = GestionRegex::Instance();
    FabriqueAutomate *fabriqueAut = new FabriqueAutomate();
    map<string, vector<string>> etat_etatsSuivant;
    
    for (string etat : gestReg->ApplyRegex(ensemble, "Etat"))
    {

        string labelEtat = gestReg->ApplyRegex(etat, "LabelAutomate")[0]; // recupere la ligne qui contient le label de l'automate @label: [
        labelEtat = gestReg->ApplyRegex(labelEtat, "ValA")[0];            // recupere la valeur apres @
        labelEtat = gestReg->SupprimeChar(labelEtat, '@');

        string proprietes = gestReg->ApplyRegex(etat, "Proprietes")[0];

        string ligneEtatsSuivante = gestReg->ApplyRegex(proprietes, "EtatsSuivant")[0];// recupere la ligne qui contient la liste des etats suivants
        vector<string> etatsSuivant ; 

        for (string eS : gestReg->ApplyRegex(ligneEtatsSuivante,"ValCote")){// recupere le label des etats suivant
            eS = gestReg->SupprimeChar(eS, '\'');
            etatsSuivant.push_back(eS);
        }
        
        etat_etatsSuivant[labelEtat] = etatsSuivant;

        map<string,Mat<double>> matrices;
        for (string attribut : gestReg->ApplyRegex(proprietes, "CoupleNomMat"))
        {
            
            string nomAttribut = gestReg->ApplyRegex(attribut, "ValCote")[0];
            nomAttribut = gestReg->SupprimeChar(nomAttribut, '\'');

            string valMat = gestReg->ApplyRegex(attribut, "ValMat")[0];
            valMat = gestReg->SupprimeChar(valMat, ':');
            valMat = gestReg->SupprimeChar(valMat, ';');

            string first = gestReg->ApplyRegex(valMat,"Mat")[0];
            Mat<double> valeur = GetValTransition(first);

            matrices[nomAttribut] = valeur;
        }

        string ligneTransitions = gestReg->ApplyRegex(proprietes, "Transition")[0];
        vector<string> ensembleTransitions = gestReg->ApplyRegex(ligneTransitions, "EnsembleTransition");

        vector<Transition *> transitions;
        for (string etransition : ensembleTransitions)
        {
            etransition.pop_back();
            vector<string> mats;

            if(matrices.empty()){
                mats = gestReg->ApplyRegex(etransition,"Mat");
            }else{
                mats = gestReg->ApplyRegex(etransition,"NomMat");
            }

            Mat<double> valeur = GetValTransition(mats[0],matrices);

            if(mats.size() > 1){ // calcul de matrice
                vector<string> operateurs = gestReg->ApplyRegex(etransition,"Operateur");

                int i=1;
                for(string ope : operateurs){
                    ope = gestReg->SupprimeChar(ope, '(');
                    ope = gestReg->SupprimeChar(ope, ')');

                    Mat<double> mat2;
                    mat2 = GetValTransition(mats[i],matrices);

                    if(ope == "*"){
                        valeur = valeur * mat2;
                    }else if(ope == "+"){
                        valeur = valeur + mat2;
                    }else if(ope == "-"){
                        valeur = valeur - mat2;
                    }else if(ope == "/"){
                        valeur = valeur / mat2;
                    }else if(ope == "%"){
                        valeur = kron(valeur,mat2);
                    }
                    i++;
                }

                
            }
            transitions.push_back(new Transition(valeur));
        }

        string ligneforme = gestReg->ApplyRegex(proprietes, "Forme")[0];
        string labelForme = gestReg->ApplyRegex(ligneforme, "ValDoublePoint")[0]; // recupere le label de la forme pour l'etat
        labelForme = gestReg->SupprimeChar(labelForme, ':');
        labelForme = gestReg->SupprimeChar(labelForme, ';');
        
        etats[labelEtat] = fabriqueAut->ConstruitAutomate(TypeAutomate::CLASSIQUE, formes[labelForme], transitions);
    }
    
    /*
        Lie les etats entre eux
    */

    for (pair<string, vector<string>> pEtat : etat_etatsSuivant)
    {
        vector<Etat *> etatsSuivant;

        for (string labelEtatSuivant : pEtat.second)
        {
            etatsSuivant.push_back(etats[labelEtatSuivant]);
        }

        etats[pEtat.first]->SetEtatSuivant(etatsSuivant);
    }

    return etats;
    delete fabriqueAut;
}

Mat<double> LecteurScene::GetValTransition(string Matrice,map<string,Mat<double>> matrices)
{
    GestionRegex* gestReg = GestionRegex::Instance();
    Mat<double> matTransition;
    if(matrices.empty()){
        vector<vector<double>> valMat;
        int i=0,j;

        for (string ligne : gestReg->ApplyRegex(Matrice, "ValLigneMat"))
        {
            vector<double> valLigne;
            j = 0;
            for (string nb : gestReg->ApplyRegex(ligne, "ValPoint"))
            {
                if(gestReg->FindChar(nb,'/')){
                    vector<string> nbs = gestReg->ApplyRegex(nb, "ValSlash");
                    valLigne.push_back((double)stof(nbs[0]) / (double)stof(nbs[1]));
                }else{
                    valLigne.push_back((double)stof(nb));
                }
                j++;
            }
            valMat.push_back(valLigne);
            i++;
        }

        matTransition.zeros(i,j);
        int x=0;
        int y=0;

        for(vector<double> l : valMat){
            y = 0;
            for(double v : l){
                matTransition(x,y) = v;
                y++;
            }
            x++;
        }

    }else{
        Matrice = gestReg->SupprimeChar(Matrice, ')');
        Matrice = gestReg->SupprimeChar(Matrice, '(');
        matTransition = matrices[Matrice];
    }
    
    return matTransition;
}

void LecteurScene::Fermer()
{
    fichier.close();
}