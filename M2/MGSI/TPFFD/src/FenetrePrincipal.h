#ifndef FENETREPRINCIPAL_H
#define FENETREPRINCIPAL_H

#include "Observateur.h"
#include "SceneControleur.h"


class FenetrePrincipal : public IObservateur
{
private:
	Scene *scene;
	SceneControleur* controleur;
	GLFWwindow* fenetre;

public:
	void MiseAJour();

	GLFWwindow* GetWindow();
	void Affichage();
	void Clavier(GLFWwindow* window, int key, int scancode, int action, int mods);
	void Mouse(GLFWwindow* window, int button, int action, int mods);
	void MouseMotion(GLFWwindow* window, double xpos, double ypos);
	void MouseWheel(GLFWwindow* window, double xoffset, double yoffset);
	void Resize(GLFWwindow* window, int iWidth, int iHeight);

	FenetrePrincipal(int *argc, char **argv, Scene *s, SceneControleur *c);
	~FenetrePrincipal();
};

#endif