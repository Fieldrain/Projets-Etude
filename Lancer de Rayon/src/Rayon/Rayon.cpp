#include "Rayon.h"

Rayon::Rayon(Vect OriginRayon,Vect DirectionRayon,bool Secondaire) : Origin(OriginRayon),Direction(DirectionRayon),RayonSecondaire(Secondaire){

}

Rayon::~Rayon(){
    
}

Vect Rayon::GetOrigin(){
    return Origin;
}

Vect Rayon::GetDirection(){
    return Direction;
}

Vect Rayon::T(double t){
    return Origin + (Direction*t);
}

bool Rayon::IsSecondaire(){
    return RayonSecondaire;
}

