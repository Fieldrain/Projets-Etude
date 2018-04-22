#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <armadillo>
#include <vector>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159
#endif

using namespace arma;
using namespace std;

/*
CHANGER TYPE VARIABLE POUR FAIRE CALCULE AVEC ARMADILLO
ET CHANGER SVD POUR ARMADILLO
*/

#define N 10 /* Nombre de morceaux du bras */

/* Matrices et vecteurs */
Mat<float> Jacobien(N,2);
float Theta[N];
float Longueurs[N];
Mat<float> Pivots(N+1,2);

int width, height;
int xmin, ymin;
float beginPoint[2];
float pos = 1;

void myinit();
void display();
//extern void svdcmp(float **a, int m, int n, float w[], float **v);
float getMax();

float getMax(float* lambda){
  float val = (2.f/180.f); 

  for(int i=0;i<N;i++){
    if(lambda[i]>val){
      val = lambda[i];
    }
  }

  return val;
}

void drawObject()
{
  int i;

  glPointSize(8.0);
  glLineWidth(5.0);

  glPushMatrix();
  glTranslatef(0, -0.9, 0);
  /* Le sol */
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2f(-1.0, 0.0);
  glVertex2f(1.0, 0.0);
  glEnd();

  glRotatef(-90.0, 0, 0, 1);
  glBegin(GL_POINTS);
  glVertex2f(0.0, 0.0);
  glEnd();

  for (i = 0; i < N; i++)
  {
    glColor3f(0.0, 1.0, 0.0);
    glRotatef((180.0f / M_PI) * Theta[i], 0, 0, 1);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, Longueurs[i]);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.0, Longueurs[i], 0.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();
  }
  glPopMatrix();
}

void computePivotCoordinates()
{
  Pivots(0,0) = 0.f;
  Pivots(0,1) = 0.f;
  float angle = 0.f;

  for (int i = 1; i <= N; i++)
  {
    angle += Theta[i - 1]; // car pas le même repere pour chaque pivot
    Pivots(i,0) = Pivots(i - 1,0) + Longueurs[i - 1] * cos(angle);
    Pivots(i,1) = Pivots(i - 1,1) + Longueurs[i - 1] * sin(angle);
  }
}

float norm(float E[2])
{
  return sqrt(E[0] * E[0] + E[1] * E[1]);
}

void computeCoordinates(float xp, float yp)
{
  Mat<float> JacInverse(2, N);
  float lambda[N];

  float E[2];
  float epsilon = 1e-2;
  float lMax;
  int k, kmax = 50;

  /* 1. Calcul vecteur diff�rence de position */
  E[0] = xp - Pivots(N,0);
  E[1] = yp - Pivots(N,1);

  k=0;

  while(k < kmax && norm(E) > epsilon)
  {
    /* 2. Calcul du Jacobien taille N-1*/
    for (int i = 0; i < N; i++)
    { // comme petit angle prend la normal des pivots xx' + yy' = 0
      Jacobien(i, 0) = -(Pivots(N,1) - Pivots(i,1));
      Jacobien(i, 1) = Pivots(N,0) - Pivots(i,0);
    }

    JacInverse = pinv(Jacobien);

    for (int i = 0; i < N; i++)
    {
      /* 5. Application du pseudo-inverse du Jacobien */
      lambda[i] = JacInverse(0, i) * E[0] + JacInverse(1, i) * E[1];
    }

    lMax = getMax(lambda);
    //borne lambda a 2 degre M_PI*2/180
    if(lMax*180.f > 2.f){
      for(int i=0;i<N;i++){
        lambda[i] = (lambda[i]/lMax) * (2.f/180.f);
      }
    }

    for(int i=0;i<N;i++){
      /* Addition du d�placement calcul�: */     
      Theta[i] = Theta[i] + lambda[i];
    }

    computePivotCoordinates();
    E[0] = xp - Pivots(N,0);
    E[1] = yp - Pivots(N,1);

    k++;
  }
}

void mouse(int button, int state, int x, int y)
{
  float d;
  float cos_t;
  float xp, yp;

  if (state == GLUT_DOWN)
  {
    xp = -1 + (2.0 * (x - xmin)) / (float)height;
    yp = 1.9 - (2.0 * (y - ymin)) / (float)height;

    /* Calcul des coordonnees */
    computeCoordinates(xp, yp);
  }
  glutPostRedisplay();
}

void motion(int x, int y)
{
  float d;
  float cos_t;
  float xp, yp;

  xp = -1 + (2.0 * (x - xmin)) / (float)height;
  yp = 1.9 - (2.0 * (y - ymin)) / (float)height;

  /* Calcul des coordonnees */
  computeCoordinates(xp, yp);

  glutPostRedisplay();
}

void printHelp()
{
  printf("A small program to show N-link Inverse Kinematics\n\n");
}

void parsekey(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    exit(0);
  case ' ':
    myinit();
    break;
  case 'h':
    printHelp();
    break;
  default:
    return;
  }
  glutPostRedisplay();
}

void parsekey_special(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_UP:
    break;
  case GLUT_KEY_DOWN:
    break;
  case GLUT_KEY_RIGHT:
    break;
  case GLUT_KEY_LEFT:
    break;
  default:
    return;
  }
  glutPostRedisplay();
}

void myReshape(int w, int h)
{
  xmin = 0;
  ymin = 0;
  if (w > h)
  {
    xmin = (w - h) / 2;
    w = h;
  }
  else
  {
    ymin = (h - w) / 2;
    h = w;
  }
  width = w;
  height = h;
  glViewport(xmin, ymin, w, h);
  glutPostRedisplay();
}

void display(void)
{
  glPushMatrix();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

  drawObject();

  glPopMatrix();

  glutSwapBuffers();
}

void myinit(void)
{
  int i;

  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.6, 1.0);

  for (i = 0; i < N; i++)
  {
    Longueurs[i] = 1.5f / N;
    Theta[i] = 0.0f;
  }
  Theta[0] = 3.14f/2.f;
  computePivotCoordinates();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE |
                      GLUT_STENCIL);
  glutCreateWindow("Inverse Kinematics, N links");
  glutDisplayFunc(display);
  glutInitWindowSize(1200, 1200);
  glutInitWindowPosition(200, 0);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutKeyboardFunc(parsekey);
  glutSpecialFunc(parsekey_special);
  glutReshapeFunc(myReshape);
  myinit();
  printHelp();

  glutSwapBuffers();
  glutMainLoop();
  return 0;
}
