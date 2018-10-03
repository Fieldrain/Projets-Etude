#include "Scene.h"

Scene::Scene(Vect ValueCouleurAmbiante, Vect ValueCouleurFond) : objects(new vector<Object*>()), lumieres(new vector<Lumiere*>()),LumiereAmbiante(ValueCouleurAmbiante),CouleurFond(ValueCouleurFond){
}

Scene::~Scene(){
    for(int i=0;i<objects->size();i++){
        delete objects->at(i);
    }

    delete objects;

    for(int i=0;i<lumieres->size();i++){
        delete lumieres->at(i);
    }

    delete lumieres;
}

void Scene::AddObject(Object* NewObject){
    objects->push_back(NewObject);
}

Object* Scene::GetObject(int Index){
    return objects->at(Index);
}

int Scene::NbObject(){
    return objects->size();
}

void Scene::AddLumiere(Lumiere* NewLumiere){
    lumieres->push_back(NewLumiere);
}

Lumiere* Scene::GetLumiere(int Index){
    return lumieres->at(Index);
}

int Scene::NbLumiere(){
    return lumieres->size();
}

Vect Scene::GetCouleurAmbiante(){
    return LumiereAmbiante;
}

Vect Scene::GetCouleurFond(){
    return CouleurFond;
}

void Scene::Affiche(){
    for(int i=0;i<objects->size();i++){
        objects->at(i)->Affiche();
    }
}