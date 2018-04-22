#ifndef SCENE_H
#define SCENE_H

#include <map>
#include "BonhommeNeige.h"

using namespace std;

class Scene{
private:
    BonhommeNeige* bonhomme;
    Shader* shader;  

public:
    double cameraAngleX = 0.0, cameraAngleY = 0.0, cameraDistance = 0.0;
    glm::vec3 cameraPosition,LightPosition;

    GLfloat materialShininess;
    glm::vec3 materialSpecularColor;

    glm::vec3 LightIntensities;
    GLfloat LightAttenuation;
    GLfloat LightAmbientCoefficient;
    
	glm::mat4 Model, View, Projection; // Matrices constituant MVP
    double xold, yold;

    void AddObject(BonhommeNeige* b);
    BonhommeNeige* GetObject();
    
    void Clear();
    void Affiche();
    void AfficheRepere();
    void Update();
    void UpdateProperties();
    void InitShader();
    Shader* GetShader();

    Scene();
    ~Scene();
};

#endif