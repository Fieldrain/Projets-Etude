#include "Scene.h"

Scene::Scene(){
    pointSouris = new Vertices();
}

Scene::~Scene(){
    delete pointSouris;
    boundingBoxs.clear();
}

void Scene::AddObject(Object* o){
    boundingBoxs.push_back(new BoundingBox(o));
}

void Scene::Clear(){
    pointSouris = new Vertices();
    boundingBoxs.clear();
}

void Scene::Affiche(){
    //AfficheRepere();
    AffichePoint();
    for(BoundingBox* bb : boundingBoxs){
        bb->Show();
    }  
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

void Scene::AffichePoint(){
    glPointSize(2.0);
    glBegin(GL_POINTS);
        for(Vertex* v : pointSouris->getList()){
            v->printGL();
        }
    glEnd();
}

void Scene::Update(){
    for(BoundingBox* bb:boundingBoxs){
        bb->Deform();
    }
}

void Scene::AddPointSouris(double x,double y){
    pointSouris->append(new Vertex(dvec({x,y})));
}

Vertices* Scene::GetPointSouris(){
    return pointSouris;
}

BoundingBox* Scene::GetBoundingBox(int i){
    return boundingBoxs[i];
}