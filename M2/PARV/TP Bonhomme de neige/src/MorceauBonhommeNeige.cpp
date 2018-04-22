#include "MorceauBonhommeNeige.h"

MorceauBonhommeNeige::MorceauBonhommeNeige(float Taille,double*Origin,int Id,MorceauBonhommeNeige* Suivant) :
    morceau(new Sphere(Taille)),
    suivant(Suivant),
    id(Id),
    origin(Origin)
{
}

MorceauBonhommeNeige::~MorceauBonhommeNeige(){
    delete morceau;
    delete suivant;
}

void MorceauBonhommeNeige::Init(Shader *shader){
    morceau->GenereVBO(shader);
    if(suivant)
        suivant->Init(shader);
}

void MorceauBonhommeNeige::Animate(Shader* shader,double t){
    glm::vec3 translateOrigin = glm::vec3(origin[0],origin[1],origin[2]);
    transformation = glm::translate(transformation,translateOrigin);

    if(selected && t!=0){
        if(currentStretch < maxStretch && currentStretch > minStretch){
            //strech
            currentStretch += pas*t;
        }

        if(currentStretch>=maxStretch && currentTranslate< maxTranslate){
            //translate
            currentTranslate += pas*t;
            if(currentTranslate <= 0){
                currentTranslate = 0;
                currentStretch += pas*t;
            }
        }else{
            currentTranslate = 0;
        }

        glm::vec3 scale = glm::vec3(-1.0/sqrt(currentStretch),currentStretch,1.0/sqrt(currentStretch));
        transformation = glm::scale(transformation,scale);
       
        glm::vec3 translateS = glm::vec3(0,currentStretch*morceau->getDiametre() - morceau->getDiametre(),0);
        transformation = glm::translate(transformation,translateS);

        glm::vec3 translate = glm::vec3(0,currentTranslate,0);
        transformation = glm::translate(transformation,translate);
    }

    glUniformMatrix4fv(shader->getLocation("transformation"), 1, GL_FALSE, glm::value_ptr(transformation));
    glUniform1i(shader->getLocation("selected"),selected);
    morceau->ShowVBO();

    if(suivant){
        suivant->SetTransformation(transformation);
        suivant->Animate(shader,t);
    }

    
    transformation = glm::mat4(1.0);    
}

void MorceauBonhommeNeige::SetTransformation(glm::mat4 Transformation){
    transformation = Transformation;
}

void MorceauBonhommeNeige::Selected(int Id){
    if(id == Id)
        selected = true;
    else
        selected = false;

    currentStretch = 1;
    currentTranslate = 0;
    transformation = glm::mat4(1.0);

    if(suivant)
        suivant->Selected(Id);
}