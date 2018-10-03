#ifndef SCENECONTROLEUR_H
#define SCENECONTROLEUR_H

#include "Sujet.h"
#include "Scene.h"
#include "FabriqueObject.h"

class SceneControleur : public Sujet{
private:
    Scene* scene;

public:
    SceneControleur(Scene* sceneCourante = new Scene());
    ~SceneControleur();

    void InitialisationScene();
    void KeyPress(int touche);
    void Mouse(GLFWwindow* window,int button, int action, int mods);
    void MouseMotion(GLFWwindow* window,double xpos, double ypos);
    void MouseWheel( double xoffset, double yoffset);
    void Resize(int iWidth, int iHeight);
};

#endif