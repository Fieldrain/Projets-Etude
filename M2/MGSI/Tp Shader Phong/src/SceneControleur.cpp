#include "SceneControleur.h"

SceneControleur::SceneControleur(Scene* sceneCourante) : scene(sceneCourante){

}

SceneControleur::~SceneControleur(){
    delete scene;
}

void SceneControleur::InitialisationScene(){
    scene->AddObject("torus",new Torus());
    scene->Update();
}

void SceneControleur::KeyPress(int touche){
    switch (touche){
        case GLFW_KEY_P: /* affichage du carre plein */
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        case GLFW_KEY_F: /* affichage en mode fil de fer */
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case GLFW_KEY_S: /* Affichage en mode sommets seuls */
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            break;
        case GLFW_KEY_D:
            glEnable(GL_DEPTH_TEST);
            break;
        case GLFW_KEY_C:
            glDisable(GL_DEPTH_TEST);
            break;
        case GLFW_KEY_ESCAPE: /*la touche 'echap' permet de quitter le programme*/
            delete scene;
            glfwTerminate();
            break;
        case GLFW_KEY_F5:
            scene->Clear();
            cout << "Scene nettoye" <<endl;
            InitialisationScene();
            break;
    }
}