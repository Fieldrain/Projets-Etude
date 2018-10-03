#include "SceneControleur.h"

SceneControleur::SceneControleur(Scene* sceneCourante) : scene(sceneCourante){

}

SceneControleur::~SceneControleur(){
    delete scene;
}

void SceneControleur::InitialisationScene(){

    LecteurScene* lecteur = new LecteurScene(scene->options.cheminFichier);
    try 
    { 
        lecteur->Ouvrir();
        lecteur->Lire(scene);
        lecteur->Fermer();

        cout << "Scene initialise" <<endl;
    } 
    catch ( const std::exception & e ) 
    { 
        lecteur->Fermer();
        delete lecteur;
        cerr << e.what() <<endl; 
    }

    delete lecteur;

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
        case GLFW_KEY_UP:
            scene->options.iterationModele++;
            scene->options.iterationTangente = scene->options.iterationModele;
            scene->Update();
            break;
        case GLFW_KEY_DOWN:
            scene->options.iterationModele--;
            if(scene->options.iterationModele < 0)
                scene->options.iterationModele = 0;
            scene->options.iterationTangente = scene->options.iterationModele;
            scene->Update();
            break;
        case GLFW_KEY_KP_ADD:
            scene->options.iterationTangente++;
            scene->Update();
        break;
        case GLFW_KEY_KP_SUBTRACT:
            scene->options.iterationTangente--;
            if(scene->options.iterationTangente < scene->options.iterationModele)
                scene->options.iterationTangente = scene->options.iterationModele;
            scene->Update();
        break;
        case GLFW_KEY_T:
            scene->options.showTangente = !scene->options.showTangente;
            break;
        case GLFW_KEY_ESCAPE: /*la touche 'echap' permet de quitter le programme*/
            delete scene;
            glfwTerminate();
            exit(0);
            break;
        case GLFW_KEY_F5:
            scene->Clear();
            cout << "Scene nettoye" <<endl;
            InitialisationScene();
            break;
    }
}