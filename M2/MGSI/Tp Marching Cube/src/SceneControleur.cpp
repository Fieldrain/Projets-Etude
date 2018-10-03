#include "SceneControleur.h"

SceneControleur::SceneControleur(Scene* sceneCourante) : scene(sceneCourante){

}

SceneControleur::~SceneControleur(){
    delete scene;
}

void SceneControleur::InitialisationScene(){
    FabriqueObject* fabrique = new FabriqueObject();
    Object* d1 = fabrique->ConstruitObject(TypeObject::DISK,new Vertex(dvec({100.0,100.0})),50.0);
    Object* d2 = fabrique->ConstruitObject(TypeObject::DISK,new Vertex(dvec({400.0,300.0})),60.0);
    Object* d3 = fabrique->ConstruitObject(TypeObject::DISK,new Vertex(dvec({600.0,600.0})),30.0);
    Object* d4 = fabrique->ConstruitObject(TypeObject::DISK,new Vertex(dvec({500.0,450.0})),20.0);
    Object* d5 = fabrique->ConstruitObject(TypeObject::DISK,new Vertex(dvec({750.0,300.0})),10.0);

    vector<Object*> disques;
    disques.push_back(d1);
    disques.push_back(d2);
    disques.push_back(d3);
    disques.push_back(d4);
    disques.push_back(d5);

    scene->AddBlob((Blob*)fabrique->ConstruitObject(TypeObject::BLOB,disques));

    delete fabrique;

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
            exit(0);
            break;
        case GLFW_KEY_F5:
            scene->Clear();
            cout << "Scene nettoye" <<endl;
            InitialisationScene();
            break;
        case GLFW_KEY_UP:
            scene->lignes++;
            cout << "Lignes : "<<scene->lignes <<endl;
            scene->Clear();
            InitialisationScene();
            break;
        case GLFW_KEY_DOWN:
            scene->lignes--;
            cout << "Lignes : "<<scene->lignes <<endl;
            scene->Clear();
            InitialisationScene();
            break;
        case GLFW_KEY_LEFT:
            scene->colonnes--;
            cout << "Colonnes : "<<scene->colonnes <<endl;
            scene->Clear();
            InitialisationScene();
            break;
        case GLFW_KEY_RIGHT:
            scene->colonnes++;
            cout << "Colonnes : "<<scene->colonnes <<endl;
            scene->Clear();
            InitialisationScene();
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
        Vertex* point = new Vertex(dvec({x,y}));
        scene->selectedObject = scene->GetBlob()->GetDisk(point);
    }
    
}

void SceneControleur::MouseMotion(GLFWwindow* window,double xpos, double ypos){
    int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

    if (state == GLFW_PRESS)
    {
        GLint viewport[4];	
        glGetIntegerv(GL_VIEWPORT, viewport);	

        double x,y;
        glfwGetCursorPos(window,&x,&y);
        
        y = viewport[3]-y;
        Vertex* point = new Vertex(dvec({x,y}));

        if(scene->selectedObject)
            scene->selectedObject->Move(point);

        scene->Update();
    }
}

void SceneControleur::MouseWheel(double xoffset, double yoffset){

}

void SceneControleur::Resize(int iWidth, int iHeight){
    glViewport(0, 0, iWidth, iHeight);
}