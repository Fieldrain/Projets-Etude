#include "Sphere.h"

Sphere::Sphere(float Diametre,int Parallele, int Meridien) : Object(),
    parallele(Parallele),
    meridien(Meridien),
    diametre(Diametre)
{
    initSommet();
    initIndice();
}


Sphere::~Sphere(){

}

void Sphere::initSommet(){

    float rayon = diametre / 2;
    float o = 0.f;
    double* color = new double[3];
    color[0] = 1;
    color[1] = 1;
    color[2] = 1;


    for (int i = 0; i < meridien; i++) {

        float y = (float) (-(PI / 2) + (PI / (parallele + 1)));

        for (int j = 0; j < parallele; j++) {

            double* value = new double[3];
            value[0] = (rayon * (cos(y) * sin(o))) ;
            value[1] = (rayon * sin(y));
            value[2] = (rayon * (cos(o) * cos(y)));

            
            Vertex* vertex = new Vertex(value,color);

            points->append(vertex);
            normales->append(vertex);

            y += (float) (PI / (parallele + 1));
        }
        o += (float) ((2 * PI) / meridien);
    }

    double* valueH = new double[3];
    valueH[0] = 0.0;
    valueH[1] = rayon;
    valueH[2] =  0.0;

    Vertex* vertexH = new Vertex(valueH,color);
    points->append(vertexH);
    normales->append(vertexH);

    double* valueB = new double[3];
    valueB[0] =  0.0;
    valueB[1] =  -rayon;
    valueB[2] =  0.0;

    Vertex* vertexB = new Vertex(valueB,color);
    points->append(vertexB);
    normales->append(vertexB);

}
void Sphere::initIndice(){

    for (int i = 0; i < parallele-1; i++) {
        for (int j = 0; j < meridien; j++) {

            indices.push_back(i + (j * parallele));
            indices.push_back((i + 1) + (j * parallele));
            indices.push_back(((i + 1) + ((j + 1) * parallele)) % (parallele * meridien));

            indices.push_back(((i + 1) + ((j + 1) * parallele)) % (parallele * meridien));
            indices.push_back(i + (j * parallele));
            indices.push_back((i + (j + 1) * parallele) % (parallele  * meridien));

        }
    }

    for (int j = 0; j < meridien; j++) {

        indices.push_back(points->length() - 1);
        indices.push_back(j * parallele);
        indices.push_back(((j + 1) * parallele) % (parallele * meridien));
    }

    for (int j = 0; j < meridien; j++) {

        indices.push_back(points->length() - 2);
        indices.push_back((parallele - 1) + (j * parallele));
        indices.push_back(((parallele - 1) + ((j + 1) * parallele)) % (parallele * meridien));
    }

}

void Sphere::Show() {
    glPushMatrix();

    Object::ShowDefault(GL_TRIANGLES,3);

    glPopMatrix();
}

void Sphere::ShowVBO(){

    Object::ShowVBODefault(GL_TRIANGLES);
}

float Sphere::getDiametre(){
    return diametre;
}
