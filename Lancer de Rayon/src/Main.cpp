#include "Lancer.h"
#include "Object/Element/ElementSphere.h"
#include "Object/Englobant/EnglobantSphere.h"
#include "Object/Element/ElementPlan.h"
#include "Object/Englobant/EnglobantPlan.h"


Scene *sceneCourante;
Lancer *lancerRayon;
Camera* camera;
Vect lookAt = Vect(0,0,0);
Vect camPos = Vect(3,1.5,-4);
Vect diff = camPos - lookAt;
Vect camDir = (diff*(-1)).normalize();
Vect camRight = Vect(0.0,1.0,0.0).cross(camDir).normalize();
Vect camDown = camRight.cross(camDir);

//Vect couleurFond = Vect(0.46, 0.70, 1.0);
Vect couleurFond = Vect(0, 0, 0);

char presse;
float anglex = 0.0f, angley = -10.f, zoom = 10.f;
int x, y, xold, yold;

void affichage();
void clavier(unsigned char touche, int x, int y);
void reshape(int x, int y);
void mouse(int bouton, int etat, int x, int y);
void mousemotion(int x, int y);
void mouseWheel(int button, int dir, int x, int y);

int main(int argc, char **argv)
{
    /* initialisation de glut et creation
     de la fenetre */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutCreateWindow("test");

    /* Initialisation d'OpenGL */
    glClearColor(couleurFond[0], couleurFond[1], couleurFond[2],0.0);
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);

    /* enregistrement des fonctions de rappel */
    glutDisplayFunc(affichage);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(clavier);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
    glutMouseWheelFunc(mouseWheel);
    
    camera = new Camera(camPos,camDir,camRight,camDown);

    sceneCourante = new Scene(Vect(1.0, 1.0, 1.0), couleurFond);
    lancerRayon = new Lancer(sceneCourante);

    //creation sphere
    Couleur* couleurSphere = new Couleur(Vect(1.0, 1.0, 1.0),Vect(0.5, 0.5, 0.5),Vect(0.5, 0.25, 0.25));
    Materiel* materielSphere = new Materiel(couleurSphere,Vect(0.5, 0.25, 0.25),0.25,Reflechissant);

    Object* sphere = new Object(new ElementSphere(0.5,Vect(1.75, -0.25, 0)), new EnglobantSphere(0.5,Vect(1.75, -0.25, 0)),materielSphere);
    sceneCourante->AddObject(sphere);

    Couleur* couleurPlan = new Couleur(Vect(1.0, 1.0, 1.0),Vect(1.0, 1.0, 1.0),Vect(1.0, 1.0, 1.0));
    Materiel* materielPlan = new Materiel(couleurPlan,Vect(1, 1, 1),1,Reflechissant);
    //creation plan y
    sceneCourante->AddObject(new Object(new ElementPlan(Vect(0.0, -1.0, 0.0), Vect(0.0, 1.0, 0.0)), new EnglobantPlan(Vect(0.0, -1.0, 0.0), Vect(0.0, 1.0, 0.0)), materielPlan));

    /*//creation plan x
    sceneCourante->AddObject(new Object(new ElementPlan(Vect(8.0, 0.0, 0.0), Vect(-1.0, 0.0, 0.0)), new EnglobantPlan(Vect(8.0, 0.0, 0.0), Vect(-1.0, 0.0, 0.0)), Reflechissant, couleurPlan,1.0));

    //creation plan z
    sceneCourante->AddObject(new Object(new ElementPlan(Vect(0.0, 0.0, -5.0), Vect(0.0, 0.0, 1.0)), new EnglobantPlan(Vect(0.0, 0.0, -5.0), Vect(0.0, 0.0, 1.0)), Reflechissant, couleurPlan,1.0));
*/

    Couleur* couleurLumiere = new Couleur(Vect(1.0, 1.0, 1.0),Vect(1.0, 1.0, 1.0),Vect(1.0, 1.0, 1.0));
    Lumiere* lumiere = new Lumiere(couleurLumiere,Vect(-7, 10.0, -10.0),Vect(0,0,1));
    sceneCourante->AddLumiere(lumiere);
    glutMainLoop();
    return 0;
}

void affichage()
{
    /* effacement de l'image avec la couleur de fond */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angley, 1.0f, 0.0f, 0.0f);
    glRotatef(anglex, 0.0f, 1.0f, 0.0f);
    glOrtho(-zoom, zoom, -zoom, zoom, -zoom, zoom);

    glPushMatrix();
    //Rep�re
    //axe x en rouge
    glBegin(GL_LINES);
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0, 0, 0.0);
    glVertex3d(1, 0, 0.0);
    glEnd();
    //axe des y en vert
    glBegin(GL_LINES);
    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(0, 0, 0.0);
    glVertex3d(0, 1, 0.0);
    glEnd();
    //axe des z en bleu
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, 0.0);
    glVertex3f(0, 0, 1.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(camera->GetPosition()[0], camera->GetPosition()[1], camera->GetPosition()[2]);
    glVertex3f(camera->GetDirection()[0], camera->GetDirection()[1], camera->GetDirection()[2]);
    glEnd();

    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(camera->GetPosition()[0], camera->GetPosition()[1], camera->GetPosition()[2]);
    glutSolidCube(0.10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(camera->GetDirection()[0], camera->GetDirection()[1], camera->GetDirection()[2]);
    glutWireCube(0.10);
    glPopMatrix();

    //dessine la scene
    sceneCourante->Affiche();

    glPopMatrix();

    //On echange les buffers
    glFlush();
    glutSwapBuffers();
}

void clavier(unsigned char touche, int x, int y)
{
    switch (touche)
    {
    case 'p': /* affichage du carre plein */
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glutPostRedisplay();
        break;
    case 'f': /* affichage en mode fil de fer */
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glutPostRedisplay();
        break;
    case 's': /* Affichage en mode sommets seuls */
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        glutPostRedisplay();
        break;
    case 'd':
        glEnable(GL_DEPTH_TEST);
        glutPostRedisplay();
        break;
    case 'D':
        glDisable(GL_DEPTH_TEST);
        glutPostRedisplay();
        break;
    case 'r':
        cout << "Debut Lancer" <<endl;
        lancerRayon->Main(1,camera);
        break;
    case 'q': /*la touche 'q' permet de quitter le programme */
        exit(0);
    }
}

void reshape(int x, int y)
{
    if (x < y)
        glViewport(0, (y - x) / 2, x, x);
    else
        glViewport((x - y) / 2, 0, y, y);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        presse = 1;
        xold = x;
        yold = y;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        presse = 0;
}

void mousemotion(int x, int y)
{
    if (presse)
    {
        anglex = anglex + (x - xold);
        angley = angley + (y - yold);
        glutPostRedisplay();
    }

    xold = x;
    yold = y;
}

void mouseWheel(int button, int dir, int x, int y)
{
    if (dir > 0)
    {
        zoom -= 0.2f;
    }
    else
    {
        zoom += 0.2f;
    }
    glutPostRedisplay();
}
