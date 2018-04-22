#include "Scene.h"

Scene::Scene(){
    marching = new Marching(lignes,colonnes);
}

Scene::~Scene(){
    delete marching;
    delete blob;
}

void Scene::AddBlob(Blob* o){
    blob = o;
}

Blob* Scene::GetBlob(){
    return blob;
}

void Scene::Clear(){
    delete blob;
    delete marching;
    selectedObject = NULL;
    marching = new Marching(lignes,colonnes);
}

void Scene::Affiche(){
    //marching->ShowPoint();
    marching->ShowArrete();
}

void Scene::AfficheRepere(){
    glPushMatrix();
    //Rep�re
    //axe x en rouge
    glBegin(GL_LINES);
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0, 0, 0.0);
    glVertex3d(1, 0, 0.0);
    glEnd();
    //axe des y en vert
    glBegin(GL_LINES);
    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(0, 0, 0.0);
    glVertex3d(0, 1, 0.0);
    glEnd();
    //axe des z en bleu
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, 0.0);
    glVertex3f(0, 0, 1.0);
    glEnd();

    glPopMatrix();
}

void Scene::Update(){
    marching->CalculArrete(blob);
}