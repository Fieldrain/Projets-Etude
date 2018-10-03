#include "FenetrePrincipal.h"

FenetrePrincipal::FenetrePrincipal(int *argc, char **argv, Scene *s, SceneControleur *c) : scene(s), controleur(c)
{
	/* Initialize the library */
    if (!glfwInit())
		exit(EXIT_FAILURE);
    
    /* Create a windowed mode window and its OpenGL context */
	fenetre = glfwCreateWindow(800, 600, "MarchingSquare", NULL, NULL);
	
    if (!fenetre)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(fenetre);
    //glfwSetCursor(fenetre, GLFW_CROSSHAIR_CURSOR);

    /* Initialisation d'OpenGL */
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.15f, 0.15f, 0.15f, 1.f);

	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) 
	{
		cout << "- glew Init failed :(" << endl;
		exit(EXIT_FAILURE);
	}

    controleur->InitialisationScene();
	controleur->Abonne(this);
    
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(0.0, viewport[2], 0.0, viewport[3], -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

FenetrePrincipal::~FenetrePrincipal()
{
	delete controleur;
}

void FenetrePrincipal::MiseAJour(){
	Affichage();
}

void FenetrePrincipal::Affichage(){                       
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Rendu de la scene
	//scene->AfficheRepere();
    
    scene->Affiche();
    
	/* Swap front and back buffers */
    glfwSwapBuffers(fenetre);
    /* Poll for and process events */
    glfwPollEvents();
}

void FenetrePrincipal::Clavier(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS){
        controleur->KeyPress(key);
    }
}

void FenetrePrincipal::Mouse(GLFWwindow* window, int button, int action, int mods){
    controleur->Mouse(window,button,action,mods);
}

void FenetrePrincipal::MouseMotion(GLFWwindow* window, double xpos, double ypos){
	controleur->MouseMotion(window,xpos,ypos);
}

void FenetrePrincipal::MouseWheel(GLFWwindow* window, double xoffset, double yoffset){
	controleur->MouseWheel(xoffset,yoffset);
}

void FenetrePrincipal::Resize(GLFWwindow* window, int iWidth, int iHeight){
    controleur->Resize(iWidth, iHeight);
}

GLFWwindow* FenetrePrincipal::GetWindow(){
	return fenetre;
}
