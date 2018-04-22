#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cle{
    private:
        int numFrame;
        glm::vec3 rotationInit;
        glm::vec3 rotationObj;
        glm::vec3 position;
        bool modifie;

    public:
        Cle(int NumeroFrame, glm::vec3 RotationInit, glm::vec3 RotationObj, glm::vec3 Position,bool Modifie = false);
        ~Cle();

        int getNumFrame();
        glm::vec3 getAngleInit();
        glm::vec3 getAngleObj();
        glm::vec3 getPosition();
        bool change();
};