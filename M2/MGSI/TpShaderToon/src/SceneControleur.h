#ifndef SCENECONTROLEUR_H
#define SCENECONTROLEUR_H

#include "Sujet.h"
#include "Scene.h"
#include "Torus.h"

class SceneControleur : public Sujet{
private:
    Scene* scene;

public:
    SceneControleur(Scene* sceneCourante = new Scene());
    ~SceneControleur();

    void InitialisationScene();
    void KeyPress(int touche);
};

#endif