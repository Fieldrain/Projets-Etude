#pragma once
#include "../Vecteur/Vecteur.h"

class Camera{
private: 
    Vect Position;
    Vect Direction;
    Vect Right;
    Vect Down;

public:
    Vect GetPosition();
    Vect GetDirection();
    Vect GetRight();
    Vect GetDown();

    Camera(Vect PositionCam,Vect DirectionCam,Vect RightCam,Vect DownCam);
    ~Camera();
};