#ifndef MORCEAUBONHOMMENEIGE_H
#define MORCEAUBONHOMMENEIGE_H

#include "Sphere.h"

class MorceauBonhommeNeige {
    private:
        Sphere * morceau;
        MorceauBonhommeNeige* suivant;
        int id;

        glm::mat4 transformation = glm::mat4(1.0);

        double maxStretch = 1.5;
        double minStretch = 0.5;
        double maxTranslate = 5.0;

        double pas = 0.01;

        double currentStretch = 1;
        double currentTranslate = 0;
        bool selected = false;
        double *origin;

    public:

    void Animate(Shader* shader,double t);
    void Init(Shader *shader);
    void SetTransformation(glm::mat4 Transformation);
    void Selected(int Id);

    MorceauBonhommeNeige(float Taille,double*Origin,int Id,MorceauBonhommeNeige* Suivant);
    ~MorceauBonhommeNeige();
};

#endif