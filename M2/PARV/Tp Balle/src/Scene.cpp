#include "Scene.h"

Scene::Scene(){
    shader = new Shader();
    // Projection matrix : 65 Field of View, 1:1 ratio, display range : 1 unit <-> 1000 units
    // ATTENTIOn l'angle est donné en radians si f GLM_FORCE_RADIANS est défini sinon en degré
    Projection = glm::perspective( 60.f, 1.0f, 1.0f, 100.f);

    cameraPosition = glm::vec3(3.5/2.0,1.,5.);
    LightPosition = glm::vec3(0.,1.,2.5);

    // le matériau
    //---------------
    materialShininess=1.;
    materialSpecularColor = glm::vec3(1.,1.,1.);  // couleur du materiau

    // la lumière
    //-----------
    LightIntensities=glm::vec3(1.,1.,1.);// couleur la lumiere
    LightAttenuation =1.;
    LightAmbientCoefficient=.1f;
}

Scene::~Scene(){
    delete shader;
}

void Scene::AddObject(Balle* b){
    balle = b;
}

Balle* Scene::GetObject(){
    return balle;
}

void Scene::Clear(){
    delete balle;
}

void Scene::Affiche(){
    GLuint idView = shader->getLocation("VIEW");
    GLuint idModel = shader->getLocation("MODEL");
    GLuint idProj = shader->getLocation("PROJECTION");

    GLuint idCpos = shader->getLocation("cameraPosition");
    GLuint idMatShi = shader->getLocation("materialShininess");
    GLuint idMatSpe = shader->getLocation("materialSpecularColor");
    GLuint idLPos = shader->getLocation("light.position");
    GLuint idLInt= shader->getLocation("light.intensities");
    GLuint idLAtt = shader->getLocation("light.attenuation");
    GLuint idLAmC = shader->getLocation("light.ambientCoefficient");

    shader->enable();
    glUniformMatrix4fv(idView, 1, GL_FALSE, glm::value_ptr(View));
	glUniformMatrix4fv(idModel, 1, GL_FALSE, glm::value_ptr(Model));
	glUniformMatrix4fv(idProj, 1, GL_FALSE, glm::value_ptr(Projection));

    glUniform3f(idCpos,cameraPosition.x, cameraPosition.y, cameraPosition.z);
    glUniform1f(idMatShi,materialShininess);
    glUniform3f(idMatSpe,materialSpecularColor.x,materialSpecularColor.y,materialSpecularColor.z);
    glUniform3f(idLPos,LightPosition.x,LightPosition.y,LightPosition.z);
    glUniform3f(idLInt,LightIntensities.x,LightIntensities.y,LightIntensities.z);
    glUniform1f(idLAtt,LightAttenuation);
    glUniform1f(idLAmC,LightAmbientCoefficient);

    //AfficheRepere();
    balle->Show(shader);
    shader->disable();
    
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
    balle->Init(shader);
}

void Scene::UpdateProperties(){
    View       = glm::lookAt(   cameraPosition, // Camera is at (0,0,3), in World Space
                                            glm::vec3(3.5/2.0,1,0), // and looks at the origin
                                            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                             );
    Model = glm::mat4(1.0f);
    Model = glm::translate(Model,glm::vec3(0,0,cameraDistance));

    Model = glm::rotate(Model,(float)cameraAngleX,glm::vec3(1, 0, 0));
    Model = glm::rotate(Model,(float)cameraAngleY,glm::vec3(0, 1, 0));

    Model = glm::scale(Model,glm::vec3(.8, .8, .8));
}

void Scene::InitShader(){
    vector<string> uniformShader;
    uniformShader.push_back("cameraPosition");
    uniformShader.push_back("materialShininess");
    uniformShader.push_back("materialSpecularColor");
    uniformShader.push_back("light.position");
    uniformShader.push_back("light.intensities");
    uniformShader.push_back("light.attenuation");
    uniformShader.push_back("light.ambientCoefficient");
    uniformShader.push_back("transformation");

    shader->loadShader("shader/PhongShader.vert", Shader::VERTEX);
    shader->loadShader("shader/PhongShader.frag", Shader::FRAGMENT);
    
    shader->create_link();

    shader->addAttribute("vVertex");
    shader->addAttribute("vColor");
    shader->addAttribute("vNormal");
    
    shader->addUniform("VIEW");
    shader->addUniform("MODEL");
    shader->addUniform("PROJECTION");

    for(int i=0;i<uniformShader.size();i++){
        string n = uniformShader[i];
        shader->addUniform(n);
    }

}

Shader* Scene::GetShader(){
    return shader;
}