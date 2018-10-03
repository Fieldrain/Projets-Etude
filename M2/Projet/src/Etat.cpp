#include "Etat.h"

Etat::Etat(Object *Forme, vector<Transition*> TransitionSuivante, vector<Etat*> EtatSuivant) : forme(Forme),etSuivant(EtatSuivant),trSuivante(TransitionSuivante){

}

Etat::~Etat(){ 
    for(Etat* e: etSuivant)
        delete e;

    for(Transition* t: trSuivante)
        delete t;
}

void Etat::ContinueGeometry(Mat<double> multTransformation,int nombreIterationModele, int nombreIterationTangente, ResultatIFS* res){
    for(int i=0; i < etSuivant.size(); i++){
        Transition *tr = trSuivante[i];
        Etat *e = etSuivant[i];
        
        e->CalculGeometry(multTransformation * tr->GetMatTransition(),nombreIterationModele-1,nombreIterationTangente-1, res);
    }
}


void Etat::CalculGeometry(Mat<double> multTransformation,int nombreIterationModele, int nombreIterationTangente, ResultatIFS* res){

    if(nombreIterationModele==0){
        res->Append(forme->ApplyMat(multTransformation));
        res->Append(forme->GetIndices(res->nbEtape));
        res->nbEtape++;
    }else{
        if(nombreIterationModele>0){
            ContinueGeometry(multTransformation,nombreIterationModele,nombreIterationTangente,res);
        }
    }

    if(nombreIterationTangente==0){
        res->Append("tangentes",forme->CalculTangentes(res->tangentesInit,multTransformation));
    }else{
        ContinueGeometry(multTransformation,nombreIterationModele,nombreIterationTangente,res);
    }
}

void Etat::ContinueUv(Mat<double> multTransformationUV,int nombreIterationModele, int nombreIterationTangente, string adresse,ResultatIFS* res){
    for(int i=0; i < etSuivant.size(); i++){
        Transition *tr = trSuivante[i];
        Etat *e = etSuivant[i];

        multTransformationUV = multTransformationUV * tr->GetMatTransition();
        
        e->CalculUv(multTransformationUV,nombreIterationModele-1,nombreIterationTangente-1, adresse+to_string(i),res);
    }
}

void Etat::CalculUv(Mat<double> multTransformationUV,int nombreIterationModele, int nombreIterationTangente, string adresse,ResultatIFS* res){
    
    if(nombreIterationModele==0){
        res->Append("uv",forme->ApplyMat(multTransformationUV)->toVector());
    }else{
        if(nombreIterationModele>0){
            ContinueUv(multTransformationUV,nombreIterationModele,nombreIterationTangente,adresse,res);
        }
    }

    if(nombreIterationTangente==0){
        res->Append("uvTangente",forme->ApplyMat(multTransformationUV)->toVector());
        vector<string> newAdresse;
        for(int i=0;i<res->tangentesInit.size();i++){
            newAdresse.push_back(adresse+to_string(i));
        }

        res->Append(newAdresse);
    }else{
        ContinueUv(multTransformationUV,nombreIterationModele,nombreIterationTangente,adresse,res);
    }
}

void Etat::SetEtatSuivant(vector<Etat*> EtatSuivant){
    etSuivant = EtatSuivant;
}

Object* Etat::GetForme(){
    return forme;
}

int Etat::GetDimension(){
    return trSuivante[0]->GetDimension();
}

Etat* Etat::GetEtatSuivant(){
    return etSuivant[0];
}

vector<Transition*> Etat::GetTransition(){
    return trSuivante;
}

vector<string> Etat::Inverse(Col<double> uv, int profondeur){

    vector<string> adresse;

    if(etSuivant.size()==1){
        Etat *e = etSuivant[0];
        adresse = e->Inverse(uv,profondeur-1);
    }

    //evite plongement
    if(etSuivant.size() > 1 && profondeur>=0){

        for(int i=0; i < etSuivant.size(); i++){
            Transition *tr = trSuivante[i];
            // inversion transformation
            Col<double> newUV = tr->GetMatTransition().i() * uv;

            if((newUV(0) >= 0.0 && newUV(1) >= 0.0) && (newUV(0) <= 1.0 && newUV(1) <= 1.0)){
                // appartient
                if(profondeur>0){
                    //pour chaque adresse niveau inférieur
                    for(string ad : etSuivant[i]->Inverse(newUV,profondeur-1)){
                        adresse.push_back(to_string(i)+ad);
                    }
                }else{
                    adresse.push_back(to_string(i));
                }
            }
        }
    }

    return adresse;
}