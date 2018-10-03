#include "FenetrePrincipal.h"

FenetrePrincipal* fenetre;

void clavier(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse(GLFWwindow* window, int button, int action, int mods);
void mousemotion(GLFWwindow* window, double xpos, double ypos);
void mouseWheel(GLFWwindow* window, double xoffset, double yoffset);
void resize(GLFWwindow* window, int iWidth, int iHeight);

int main(int argc, char **argv)
{
    Scene *s = new Scene();
	SceneControleur *c = new SceneControleur(s);

	fenetre = new FenetrePrincipal(&argc, argv,s,c);
    
    /* enregistrement des fonctions de rappel */

    GLFWwindow* window = fenetre->GetWindow();

    glfwSetKeyCallback(window,clavier);
    glfwSetCursorPosCallback(window,mousemotion);
    glfwSetMouseButtonCallback(window,mouse);
    glfwSetScrollCallback(window,mouseWheel);
    glfwSetWindowSizeCallback(window, resize);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        fenetre->MiseAJour();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    delete fenetre;
    exit(EXIT_SUCCESS);
}

void clavier(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    fenetre->Clavier(window, key, scancode, action, mods);
}

void mouse(GLFWwindow* window, int button, int action, int mods)
{
    fenetre->Mouse(window, button, action, mods);
}

void mousemotion(GLFWwindow* window, double xpos, double ypos)
{
    fenetre->MouseMotion(window , xpos, ypos);
}

void mouseWheel(GLFWwindow* window, double xoffset, double yoffset)
{
    fenetre->MouseWheel(window, xoffset , yoffset);
}

void resize(GLFWwindow* window, int iWidth, int iHeight){
    fenetre->Resize(window,iWidth,iHeight);
}