#include "Torus.h"

Torus::Torus(int Nb_R, int Nb_r):
    nb_R(Nb_R),
    nb_r(Nb_r)
{
    points = new Vertices((nb_R+1)*(nb_r+1),3);
    normales = new Vertices((nb_R+1)*(nb_r+1),3);
    uv = new Vertices((nb_R+1)*(nb_r+1),2);
    indices = new int[nb_R * nb_r * 6 *sizeof(int)];

    nbIndice = nb_R * nb_r * 6;

    create();
    createIndice();
}

Torus::~Torus(){

}

void Torus::create(){
    double R=0.7;
    double r=0.3;

	double theta, phi;
	theta = ((double)glm::radians(360.0))/((double)nb_R);
	phi = ((double)glm::radians(360.0))/((double)nb_r);

	double pasU, pasV;
    pasU= 1./nb_R;
    pasV= 1./nb_r;

    double* color = new double[3*sizeof(double)];
    color[0] = 1.0;
    color[1] = 0.5;
    color[2] = 0.3;

    for (int i = 0; i <= nb_R; i++){
        for (int j = 0; j <= nb_r; j++){

            int indiceSommet = (i * (nb_r + 1) * 3) + (j * 3);
            double* sommets = new double[3 * sizeof(double)];
            sommets[0] = (R + r * cos((double)j * phi)) * cos((double)i * theta); //x
            sommets[1] = (R + r * cos((double)j * phi)) * sin((double)i * theta); //y
            sommets[2] = r * sin((double)j * phi); // z

            int indiceNormal = (i * (nb_r + 1) * 3) + (j * 3);
            double* normals = new double[3 *sizeof(double)];
            normals[0] = cos((double)j * phi) * cos((double)i * theta); //x
            normals[1] = cos((double)j * phi) * sin((double)i * theta); //y
            normals[2] = sin((double)j * phi); // z

            int indiceUV = (i * (nb_r + 1) * 2) + (j * 2);
            double* uvPoint = new double[3 *sizeof(double)];
            uvPoint[0] = ((double)i) * pasV;
            uvPoint[1] = ((double)j) * pasV;

            points->set(indiceSommet,sommets,color);
            normales->set(indiceNormal,normals);
            uv->set(indiceUV,uvPoint);
        }
    }
}

void Torus::createIndice(){
    for (int i = 0; i < nb_R; i++){
        for (int j = 0; j < nb_r; j++){

            indices[(i * nb_r * 6) + (j * 6)] = (int)((i * (nb_r + 1)) + j);
            indices[(i * nb_r * 6) + (j * 6) + 1] = (int)((i + 1) * (nb_r + 1) + (j));
            indices[(i * nb_r * 6) + (j * 6) + 2] = (int)(((i + 1) * (nb_r + 1)) + (j + 1));
            indices[(i * nb_r * 6) + (j * 6) + 3] = (int)((i * (nb_r + 1)) + j);
            indices[(i * nb_r * 6) + (j * 6) + 4] = (int)(((i + 1) * (nb_r + 1)) + (j + 1));
            indices[(i * nb_r * 6) + (j * 6) + 5] = (int)(((i) * (nb_r + 1)) + (j + 1));
        }
    }

}
void Torus::Show(){
    Object::ShowDefault(GL_TRIANGLES,3);
}

void Torus::ShowVBO(){
    Object::ShowVBODefault(GL_TRIANGLES);
}