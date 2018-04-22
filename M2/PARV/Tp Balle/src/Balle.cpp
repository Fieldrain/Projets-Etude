#include "Balle.h"

Balle::Balle(float Taille,double*Origin) :
    morceau(new Sphere(Origin,Taille)),
    origin(Origin)
{

    //creation image cle

    cles.push_back(new Cle(0,glm::vec3(0,0,90),glm::vec3(0,0,90),glm::vec3(0,0,0)));

    cles.push_back(new Cle(40,glm::vec3(0,0,180),glm::vec3(0,0,0),glm::vec3(2,0,0),true));
    cles.push_back(new Cle(60,glm::vec3(0,0,180),glm::vec3(0,0,0),glm::vec3(1,0,0),true));

    cles.push_back(new Cle(140,glm::vec3(0,0,180),glm::vec3(0,0,0),glm::vec3(1,0,0),true));
    cles.push_back(new Cle(160,glm::vec3(0,0,180),glm::vec3(0,0,0),glm::vec3(0.5,0,0),true));
    
    cles.push_back(new Cle(240,glm::vec3(0,0,180),glm::vec3(0,0,0),glm::vec3(0.5,0,0),true));
}

Balle::~Balle(){
    delete morceau;
}

void Balle::Init(Shader *shader){
    morceau->GenereVBO(shader);
}

void Balle::Animate(Shader* shader){

    if(currentCle<(cles.size()-1)){
        transformation = glm::mat4(1.0);

        double t = (double)(currentFrame-oldCleFrame)/(double)(cles[currentCle+1]->getNumFrame()-oldCleFrame);

        glm::vec3 translateOri = glm::vec3(origin[0],origin[1],origin[2]);
        transformation = glm::translate(transformation,translateOri);

        //interpolation angle
        double currentRotation = (1-t)*cles[currentCle]->getAngleInit().z + cles[currentCle+1]->getAngleObj().z*t;

        //translation
        double currentTranslateX = cles[currentCle+1]->getPosition().x;

        // si balle touche le sol stretch and squash
        if((currentFrame >40 && currentFrame <=60) || (currentFrame >140 && currentFrame <=160) ){
            //aplatie
            double currentStretch;
            if(t<=0.5){
                currentStretch = (1.0-t/2.0) * 1.0 + minStretch * t/2.0; 
            }else{ // etire
                currentStretch = (1.0-t/2.0) * minStretch + maxStretch * t/2.0; 
            }
            
            glm::vec3 translateS = glm::vec3(0,currentStretch*morceau->getDiametre() - morceau->getDiametre(),0);
            transformation = glm::translate(transformation,translateS);

            glm::vec3 scale = glm::vec3(-1/sqrt(currentStretch),currentStretch,1/sqrt(currentStretch));
            transformation = glm::scale(transformation,scale);

        }else{ // rotation de la balle
            transformation = glm::rotate(transformation,(float)currentRotation,glm::vec3(0.0,0.0,1.0));
        
            glm::vec3 translate = glm::vec3(currentTranslateX,0,0);
            transformation = glm::translate(transformation,translate); 
        }

        if(currentFrame == cles[currentCle+1]->getNumFrame()){
            if(cles[currentCle+1]->change())
                origin[0] += cles[currentCle+1]->getPosition().x;

            oldCleFrame = currentFrame;
            currentCle++;
            
        }
    }

    glUniformMatrix4fv(shader->getLocation("transformation"), 1, GL_FALSE, glm::value_ptr(transformation));
    morceau->ShowVBO();
        
}

void Balle::SetTransformation(glm::mat4 Transformation){
    transformation = Transformation;
}

void Balle::Show(Shader* shader){
    Animate(shader);
    currentFrame++;
}
