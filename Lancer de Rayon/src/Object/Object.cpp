#include "Object.h"

Object::Object(Element* ElementObject, Englobant* EnglobantObject,Materiel* MaterielObject) : element(ElementObject), englobant(EnglobantObject),materiel(MaterielObject){

}

Object::~Object(){
    delete element;
    delete englobant;
}

Retour_Calcul Object::In(Rayon* rayon){

    return englobant->In(rayon);
}

PointIntersection Object::CalculIntersection(Rayon* rayon,map<string,double> calculs){

    PointIntersection point = element->CalculIntersection(rayon,calculs);

    return point;
}

Vect Object::Normal(PointIntersection point){

    return element->Normal(point);
}

void Object::Affiche(){

    glPushMatrix();

    Vect couleurRGB = materiel->GetCouleurEmission();
    glColor3d(couleurRGB[0],couleurRGB[1],couleurRGB[2]);

    element->Affiche();
    glPopMatrix();
}

Materiel* Object::GetMateriel() const{
    return materiel;
}