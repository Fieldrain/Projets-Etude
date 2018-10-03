#include "Scene.h"

Scene::Scene(){
    LecteurOption* lecteur = new LecteurOption();

    try 
    { 
        lecteur->Ouvrir();
        options = lecteur->Lire();
        lecteur->Fermer();
    } 
    catch ( const std::exception & e ) 
    { 
        lecteur->Fermer();
        delete lecteur;
        cerr << e.what() <<endl; 
    }

    delete lecteur;

    shader = new Shader();
}

Scene::~Scene(){
    delete shader;
}

void Scene::AddIfs(string label,Ifs* automate){
    ifsScene[label] = automate;
}

Ifs* Scene::GetIfs(string label){
    return ifsScene[label];
}

void Scene::Clear(){
    ifsScene.clear();
}

void Scene::Affiche(){

    for(pair<string,Ifs*> p : ifsScene){
        p.second->Render(options.repere,options.showTangente);
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

void Scene::Update(){
    for(pair<string,Ifs*> p : ifsScene){
        p.second->RequestUpdate(options.iterationModele,options.iterationTangente,shader,options.cheminTextures);
    }
}

void Scene::InitShader(vector<string> uniformShader){

    shader->loadShader(options.vertShader, Shader::VERTEX);
    shader->loadShader(options.fragShader, Shader::FRAGMENT);
    shader->create_link();

    shader->addAttribute("vVertex");
    shader->addAttribute("vColor");
    shader->addAttribute("vUv");
    
    shader->addUniform("VIEW");
    shader->addUniform("MODEL");
    shader->addUniform("PROJECTION");

    shader->addUniform("INDICEUV");
    shader->addUniform("TANGENTES1");
    shader->addUniform("TANGENTES2");

    for(string n : uniformShader){
        shader->addUniform(n);
    }

}

Shader* Scene::GetShader(){
    return shader;
}