#include "FenetrePrincipal.h"

FenetrePrincipal *fenetre;

void affichage();
void clavier(unsigned char touche, int x, int y);
void reshape(int x, int y);
void mouse(int bouton, int etat, int x, int y);
void idle();


int main(int argc, char **argv)
{
	Scene *s = new Scene();
	Controleur *c = new Controleur(s);

	fenetre = new FenetrePrincipal(&argc, argv,s,c);

	glutDisplayFunc( affichage );
  	glutIdleFunc( idle );
  	glutReshapeFunc( reshape );
  	glutMouseFunc( mouse );
	glutKeyboardFunc( clavier );
	/* Entree dans la boucle principale glut */
	glutMainLoop();
}

void affichage()
{
	fenetre->MiseAJour();
}

void clavier(unsigned char touche, int x, int y)
{
	fenetre->Clavier(touche, x, y);
}

void reshape(int x, int y)
{
	fenetre->Reshape(x, y);
}

void mouse(int button, int state, int x, int y)
{
	fenetre->Mouse(button, state, x, y);
}

void idle(){
	fenetre->Idle();
}
