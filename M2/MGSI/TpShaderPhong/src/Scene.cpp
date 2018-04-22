#include "Scene.h"

Scene::Scene(){
    shader = new Shader();
}

Scene::~Scene(){
    objectScene.clear();
    delete shader;
}

void Scene::AddObject(string label,Object* o){
    objectScene[label] = o;
}

Object* Scene::GetObject(string label){
    return objectScene[label];
}

void Scene::Clear(){
    objectScene.clear();
}

void Scene::Affiche(){
    objectScene["torus"]->ShowVBO();
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
    objectScene["torus"]->GenereVBO(shader);
}

void Scene::InitShader(vector<string> uniformShader){

    shader->loadShader("shader/PhongShader.vert", Shader::VERTEX);
    shader->loadShader("shader/PhongShader.frag", Shader::FRAGMENT);

    shader->create_link();

    shader->addAttribute("vVertex");
    shader->addAttribute("vColor");
    shader->addAttribute("vNormal");
    shader->addAttribute("vUV");
    
    shader->addUniform("VIEW");
    shader->addUniform("MODEL");
    shader->addUniform("PROJECTION");

    shader->addUniform("TextureSampler");

    for(int i=0;i<uniformShader.size();i++){
        string n = uniformShader[i];
        shader->addUniform(n);
    }

}

Shader* Scene::GetShader(){
    return shader;
}