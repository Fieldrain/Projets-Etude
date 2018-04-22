#include "FenetrePrincipal.h"

FenetrePrincipal::FenetrePrincipal(int *argc, char **argv, Scene *s, SceneControleur *c) : scene(s), controleur(c)
{
	/* Initialize the library */
    if (!glfwInit())
		exit(EXIT_FAILURE);
    
    /* Create a windowed mode window and its OpenGL context */
	fenetre = glfwCreateWindow(800, 600, "Fractal", NULL, NULL);
	
    if (!fenetre)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(fenetre);

    /* Initialisation d'OpenGL */
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1.f);
    
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) 
	{
		cout << "- glew Init failed :(" << endl;
		exit(EXIT_FAILURE);
	}
    
    std::cout << "Fabricant : " << glGetString (GL_VENDOR) << std::endl;
    std::cout << "Carte graphique: " << glGetString (GL_RENDERER) << std::endl;
    std::cout << "Version : " << glGetString (GL_VERSION) << std::endl;
    std::cout << "Version GLSL : " << glGetString (GL_SHADING_LANGUAGE_VERSION) << std::endl << std::endl;

	scene->InitShader();
    controleur->InitialisationScene();
	controleur->Abonne(this);

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
