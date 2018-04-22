#ifndef BALLE_H
#define BALLE_H

#include "Sphere.h"
#include "Cle.h"

class Balle {
    private:
        Sphere * morceau;
        
        glm::mat4 transformation = glm::mat4(1.0);
        double *origin;

        double maxStretch = 2.0;
        double minStretch = -0.5;

        vector<Cle*> cles;
        int currentFrame = 0;
        int oldCleFrame = 0;
        int currentCle = 0;

    public:

    void Animate(Shader* shader);
    void Init(Shader *shader);
    void SetTransformation(glm::mat4 Transformation);
    void Show(Shader* shader);

    Balle(float Taille,double*Origin);
    ~Balle();
};

#endif