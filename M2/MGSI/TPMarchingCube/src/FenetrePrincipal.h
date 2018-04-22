#ifndef FENETREPRINCIPAL_H
#define FENETREPRINCIPAL_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Observateur.h"
#include "Scene.h"
#include "SceneControleur.h"

class FenetrePrincipal : public IObservateur
{
private:
	Scene *scene;
	SceneControleur* controleur;
	GLFWwindow* fenetre;

	bool presse = false;
	double cameraAngleX = 0.0, cameraAngleY = 0.0, cameraDistance = 0.0;
	double xold, yold;
	vector<Vertex*> pointSouris;

	glm::vec3 cameraPosition,LightPosition;
	glm::mat4 Model, View, Projection;    // Matrices constituant MVP

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