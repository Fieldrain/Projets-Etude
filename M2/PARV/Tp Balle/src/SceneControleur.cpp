#include "SceneControleur.h"

SceneControleur::SceneControleur(Scene* sceneCourante) : scene(sceneCourante){

}

SceneControleur::~SceneControleur(){
    delete scene;
}

void SceneControleur::InitialisationScene(){
    double* origin = new double[3];
    origin[0] = 0.0;
    origin[1] = 0.0;
    origin[2] = 0.0;

    scene->AddObject(new Balle(0.5,origin));
    scene->Update();
    scene->UpdateProperties();
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
        case GLFW_KEY_KP_8:
                scene->LightPosition.y += 0.5;
            break;
        case GLFW_KEY_KP_2: 
                scene->LightPosition.y -= 0.5;
            break;
        case GLFW_KEY_KP_4: 
                scene->LightPosition.x -= 0.5;
            break;
        case GLFW_KEY_KP_6: 
                scene->LightPosition.x += 0.5;
            break;
        case GLFW_KEY_KP_9: 
                scene->LightPosition.z -= 0.5;
            break;
        case GLFW_KEY_KP_3: 
                scene->LightPosition.z += 0.5;
            break;
    }
    scene->UpdateProperties();
}

void SceneControleur::Mouse(GLFWwindow* window,int button, int action, int mods){
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
		glfwGetCursorPos(window,&scene->xold,&scene->yold);
        scene->UpdateProperties();
    }
    
}

void SceneControleur::MouseMotion(GLFWwindow* window,double xpos, double ypos){
    int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    if (state == GLFW_PRESS)
    {
        scene->cameraAngleY = scene->cameraAngleY + (xpos - scene->xold);
        scene->cameraAngleX = scene->cameraAngleX + (ypos - scene->yold);
        scene->UpdateProperties();
    }

    scene->xold = xpos;
    scene->yold = ypos;
    
}

void SceneControleur::MouseWheel(double xoffset, double yoffset){
    if (yoffset < 0)
    {
        scene->cameraDistance -= 0.2f;
    }
    else
    {
        scene->cameraDistance += 0.2f;
    }
    scene->UpdateProperties();
}

void SceneControleur::Resize(int iWidth, int iHeight){
    if(iHeight == 0) iHeight = 1;
		float ratio = iWidth / float(iHeight);
		glViewport(0, 0, iWidth, iHeight);
		scene->Projection = glm::perspective(60.f,ratio, 1.0f, 100.f);
}