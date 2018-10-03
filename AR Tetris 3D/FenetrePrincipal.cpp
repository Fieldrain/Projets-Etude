#include "FenetrePrincipal.h"

FenetrePrincipal::FenetrePrincipal(int *argc, char **argv, Scene *s, Controleur *c) : scene(s), controleur(c)
{
	theGlWindowSize=scene->GetSize();

	glutInit(argc, argv);
  	glutInitWindowPosition( 0, 0);
  	glutInitWindowSize(theGlWindowSize.width,theGlWindowSize.height);
  	glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
  	glutCreateWindow( "AruCoTestGl" );

  	Reshape(theGlWindowSize.width,theGlWindowSize.height);

	controleur->Abonne(this);
}

FenetrePrincipal::~FenetrePrincipal()
{
	delete scene;
	delete controleur;
}

void FenetrePrincipal::MiseAJour(){
	Affichage();
}

void FenetrePrincipal::Affichage(){

	// Initialisation de la scene
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	// Rendu de la scene
	scene->AfficheScene(theGlWindowSize,false);

	//On echange les buffers 
	glutSwapBuffers();
}

void FenetrePrincipal::Clavier(unsigned char touche, int x, int y){
	switch (touche)
	{
	case 'p': /* affichage plein */
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glutPostRedisplay();
		break;
	case 'f': /* affichage en mode fil de fer */
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutPostRedisplay();
		break;
	case 'm': /* Affichage en mode sommets seuls */
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glutPostRedisplay();
		break;
	case 'z': /* Avance la piece*/
		controleur->DeplacePiece(Avant);
		break;
	case 'q': /* Deplace a gauche la piece*/
		controleur->DeplacePiece(Gauche);
		break;
	case 's': /* Recule la piece*/
		controleur->DeplacePiece(Arriere);
		break;
	case 'd': /* Deplace a droite la piece*/
		controleur->DeplacePiece(Droite);
		break;

	case 'a': /* Sens suivant*/
		controleur->RotatePiece(Horaire);
		break;
	case 'e': /* Sens précédent*/
		controleur->RotatePiece(AntiHoraire);
		break;

	case 'x': /* Descend la piece*/
		controleur->DeplacePiece(Bas);
		break;
	case 'c': /*la touche 'e' permet de quitter le programme */
		exit(0);
	}
}

void FenetrePrincipal::Reshape(int iWidth, int iHeight){
	theGlWindowSize=Size(iWidth,iHeight);
    //not all sizes are allowed. OpenCv images have padding at the end of each line in these that are not aligned to 4 bytes
    if (iWidth*3%4!=0) {
        iWidth+=iWidth*3%4;//resize to avoid padding
        Reshape(iWidth,theGlWindowSize.height);
    }
    else {
        controleur->Resize(theGlWindowSize);//resize the image to the size of the GL window
    }
	glutPostRedisplay();
}

void FenetrePrincipal::Mouse(int button, int state, int x, int y){
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
		//controleur->SetLecture(); //change le statut du boolean lecture (pause,lecture)
    }
}


void FenetrePrincipal::Idle(){
	try{
		scene->Lire(theGlWindowSize);
		glutPostRedisplay();
	}
	catch(Exception e){
		cout<< "Erreur lecture"<<endl;
	}
    
}
