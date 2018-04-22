#include "SceneControleur.h"

SceneControleur::SceneControleur(Scene* sceneCourante) : scene(sceneCourante){

}

SceneControleur::~SceneControleur(){
    delete scene;
}

void SceneControleur::InitialisationScene(){

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
                exit(0);
            break;
        case GLFW_KEY_F5:
                scene->Clear();
                cout << "Scene nettoye" <<endl;
                InitialisationScene();
            break;
        case GLFW_KEY_ENTER:
                FabriqueObject* fo = new FabriqueObject();
                Object* ob = fo->ConstruitObject(TypeObject::FORME,scene->GetPointSouris());
                scene->AddObject(ob);
                delete fo;
            break;
    }
}

void SceneControleur::Mouse(GLFWwindow* window,int button, int action, int mods){
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        GLint viewport[4];	
        glGetIntegerv(GL_VIEWPORT, viewport);	

        double x,y;
        glfwGetCursorPos(window,&x,&y);
        
        y = viewport[3]-y;
        scene->AddPointSouris(x,y);
    }


    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);	

        double x,y;
        glfwGetCursorPos(window,&x,&y);
        y = viewport[3]-y;

        scene->currentIndice = scene->GetBoundingBox(0)->GetIndice(x,y);
    }
    
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE){
        int* indices = new int[2];
        indices[0] = -1;
        indices[1] = -1;
        scene->currentIndice = indices;
    }
}

void SceneControleur::MouseMotion(GLFWwindow* window,double xpos, double ypos){
    int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

    if (state == GLFW_PRESS)
    {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);	

        double x,y;
        glfwGetCursorPos(window,&x,&y);
        y = viewport[3]-y;

        if(scene->currentIndice[0] != -1 && scene->currentIndice[0]!= -1){
            scene->GetBoundingBox(0)->MovePointControl(scene->currentIndice[0],scene->currentIndice[1],x,y);
            scene->Update();
        }
    }
}

void SceneControleur::MouseWheel(double xoffset, double yoffset){

}

void SceneControleur::Resize(int iWidth, int iHeight){
    glViewport(0, 0, iWidth, iHeight);
}