#include "Ifs.h"

Ifs::Ifs(Etat* Geometry,Etat* Uv) : geometry(Geometry),uv(Uv){
    FabriqueObject *fabriqueObj = new FabriqueObject();

    fractal = fabriqueObj->ConstruitObject(geometry->GetForme()->GetType(),new Vertices(),vector<int>());

    delete fabriqueObj;
}

Ifs::Ifs(Etat* Geometry) : geometry(Geometry){
    FabriqueObject *fabriqueObj = new FabriqueObject();

    fractal = fabriqueObj->ConstruitObject(geometry->GetForme()->GetType(),new Vertices(),vector<int>());

    delete fabriqueObj;
}


Ifs::~Ifs(){
    delete geometry;
    delete uv;
    delete fractal;
}

void Ifs::CalculTangentesInitial(ResultatIFS *res){

    //on recupere l'etat apres celui des points de controle
    Etat* init = geometry->GetEtatSuivant();

    for(Transition *tr : init->GetTransition()){
        Col<cx_double> eigval;
        Mat<cx_double> eigvec;
        
        bool find = eig_gen(eigval, eigvec, tr->GetMatTransition());

        if(find){
            uvec indices = sort_index(eigval,"descend");

            pair<Col<double>,Col<double>> tangente;

            tangente.first = real(eigvec.col(indices(1)));
            tangente.second = real(eigvec.col(indices(2)));

            res->tangentesInit.push_back(tangente);
        }
    }
}

void Ifs::Make(int iterationModele,int iterationTangente,Shader* shader,string cheminTextures){
    cout << "Generation Ifs i="<< iterationModele<< " | "<< iterationTangente<<endl;
    
    ResultatIFS* res = new ResultatIFS();

    CalculTangentesInitial(res);

    Mat<double> I = mat(geometry->GetDimension(),geometry->GetDimension(),fill::eye);
    pas = 1.0/double(2^iterationTangente);

    thread t(&Ifs::CalculAdresseUV,this,iterationModele,iterationTangente,res);
    geometry->CalculGeometry(I,iterationModele,iterationTangente,res);

    cout << "Generation termine" <<endl;
    t.join();

    fractal->SetVertices(res->points);
    fractal->SetIndices(res->indices);
    fractal->SetTangentes(new Tangentes(res->tangentes));
    fractal->SetUv(new Uv(res->uv,uvToAdresse));

    fractal->GenereVBO(shader);
    
    delete res;
}

void Ifs::RequestUpdate(int iterationModele,int iterationTangente,Shader* shader,string cheminTextures){
    Make(iterationModele,iterationTangente,shader,cheminTextures);
}

void Ifs::Render(int repere,bool showTangente){
    if(showTangente){
        glPushMatrix();
        fractal->ShowTangentes(repere);
        glPopMatrix();
    }
    fractal->ShowVBO();
}

void Ifs::CalculAdresseUV(int iterationModele,int iterationTangente,ResultatIFS *res){

    if(uv!=NULL){
        cout << "Calcul adresse" <<endl; 
        
        Mat<double> I = mat(uv->GetDimension(),uv->GetDimension(),fill::eye);
        uv->CalculUv(I,iterationModele,iterationTangente,"",res);

        // Discretisation de uv [0,1]^2
        // pas = 1.0/double(2^iterationTangente*4)

        string test = "3333";
        int indicetest = 0;
        int n1 = iterationTangente;
        int nbBranche1 = (int)uv->GetEtatSuivant()->GetTransition().size();
        for(char c : test){
            indicetest += (int)(c-48) * (int)pow(nbBranche1,(n1));
            n1--;
        }

        cout << indicetest << endl;

        for(double u=0.0;u<1.0;u+=pas){
            vector<vector<int>> ligne;
            for(double v=0.0;v<1.0;v+=pas){
                int dim = uv->GetEtatSuivant()->GetDimension();
                Col<double> Cuv = dvec(dim,fill::zeros);
                Cuv(0) = u;
                Cuv(1) = v;
                Cuv(2) = 1;

                vector<string> adresses = uv->Inverse(Cuv,iterationTangente);
                vector<int> indices;

                for(string adresse : adresses){
                    
                    int indice = 0;
                    int n = iterationTangente;
                    int nbBranche = (int)uv->GetEtatSuivant()->GetTransition().size();
                    for(char c : adresse){
                        indice += (int)(c-48) * (int)pow(nbBranche,(n--));
                    }
                    indices.push_back(indice);
                }

                ligne.push_back(indices);
            }

            uvToAdresse.push_back(ligne);
        }

        cout << "Calcul adresse terminé" <<endl;
    }
}

double Ifs::GetPas(){
    return pas;
}