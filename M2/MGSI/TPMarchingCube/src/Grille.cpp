#include "Grille.h"

Grille::Grille(int Ligne, int Colonne, double Hauteur, double Largeur){

    double pasHorizontal = (double)(Largeur/Colonne);
    double pasVertical = (double)(Hauteur/Ligne);

    double x= 0.0;
    double y = 0.0;

    for(int i =0; i<Ligne;i++){
        x=0.0;
        for(int j=0;j<Colonne;j++){
            vector<Vertex*> points; // 0-> BG, 1->BD, 2->HD, 3->HG

            points.push_back(new Vertex(dvec({x,y+pasVertical}))); // BG
            points.push_back(new Vertex(dvec({x+pasHorizontal,y+pasVertical}))); // BD
            points.push_back(new Vertex(dvec({x+pasHorizontal,y}))); // HD
            points.push_back(new Vertex(dvec({x,y}))); // HG

            carreaux.push_back(new Carreau(points));
            x += pasHorizontal;
        }
        y+=pasVertical;
    }
}

Grille::~Grille(){
    carreaux.clear();
}

vector<Arrete*> Grille::getListArrete(Object* objects){
    vector<Arrete*> arretes;

    for(Carreau* c : carreaux){
        for(Arrete* a:c->getArrete(objects)){
            arretes.push_back(a);
        }
    }

    return arretes;
}