#include "Camera.h"


Camera::Camera(Vect PositionCam,Vect DirectionCam,Vect RightCam,Vect DownCam) : Position(PositionCam), Direction(DirectionCam),Right(RightCam),Down(DownCam)
{

}

Camera::~Camera(){

}


Vect Camera::GetPosition(){
    return Position;
}

Vect Camera::GetDirection(){
    return Direction;
}

Vect Camera::GetRight(){
    return Right;
}

Vect Camera::GetDown(){
    return Down;
}