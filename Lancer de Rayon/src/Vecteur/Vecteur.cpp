#include "Vecteur.h"

Vect::Vect(): x(0.0),y(0.0),z(0.0){

}

Vect::Vect(double a,double b,double c) : x(a),y(b),z(c){

}

Vect::~Vect(){

}

double Vect::clamp(double v,double min,double max){
    if(v<min){
        return min;
    }else if(v>max){
        return max;
    }else{
        return v;
    }
}

double Vect::X() const{
    return x;
}
double Vect::Y() const{
    return y;
}
double Vect::Z() const{
    return z;
}

void Vect::setX(double newX){
    x = newX;
}
void Vect::setY(double newY){
    y = newY;
}
void Vect::setZ(double newZ){
    z = newZ;
}
void Vect::set(int i,double newVal){
    switch(i){
        case 0:
            setX(newVal);
        break;
        case 1:
            setY(newVal);
        break;
        case 2:
            setZ(newVal);
        break;
        default:
        break;
    }
}

double Vect::length(){
    return sqrt((x*x) + (y*y) + (z*z));
}
Vect Vect::normalize(){
    return Vect (x/length(), y/length(), z/length());
}
double Vect::dot(Vect v){
    return x*v.X() + y*v.Y() + z*v.Z();
}
Vect Vect::cross(Vect v){
    return Vect (y*v.Z() - z*v.Y(), z*v.X() - x*v.Z(), x*v.Y() - y*v.X());
}
double Vect::distance(Vect v){
    return sqrt(pow(v.X()-x,2) + pow(v.Y()-y,2) + pow(v.Z()-z,2));
}
Vect Vect::clamp(double min,double max){
    double xc = clamp(x,min,max);
    double yc = clamp(y,min,max);
    double zx = clamp(z,min,max);
    return Vect(xc,yc,zx);
}
Vect Vect::clip(){
    Vect clippedVect = Vect(x,y,z);
    if (x>1.01 || y>1.01 || z>1.01) {
        double all = x+y+z;
        clippedVect.setX(x/all);
        clippedVect.setY(y/all);
        clippedVect.setZ(z/all);
    }
    clippedVect = clippedVect.clamp(0,1);
    return clippedVect;
}

Vect Vect::reflect(Vect normal){
    return (*this - (normal * (dot(normal) * 2))).normalize();
}
Vect Vect::refract(Vect normal,double indice){
    double psN = dot(normal);
    double thetai = acos(psN);
    double thetat = asin(indice * sin(thetai));
    double coef = cos(thetat) + indice * psN;

	return (*this * indice) - (normal * coef);

}

void Vect::operator+=(const Vect v){
    x += v.X();
    y += v.Y();
    z += v.Z();
}
Vect Vect::operator*(double s){
    return Vect (x*s, y*s, z*s);
}
Vect Vect::operator*(const Vect v){
    return Vect(x*v.X(),y*v.Y(),z*v.Z());
}
Vect Vect::operator/(double s){
    return Vect (x/s, y/s, z/s);
}
Vect Vect::operator/(const Vect v){
    return Vect (x/v.X(), y/v.Y(), z/v.Z());
}
double Vect::operator[](unsigned i) const{
    switch(i){
        case 0:
            return X();
        break;
        case 1:
            return Y();
        break;
        case 2:
            return Z();
        break;
        default:
            return numeric_limits<double>::infinity();
        break;
    }
}

Vect operator-(const Vect first, const Vect second){
    return Vect (first.x - second.x, first.y - second.y, first.z - second.z);
}
Vect operator+(const Vect first, const Vect second){
    return Vect (first.x + second.x, first.y + second.y, first.z + second.z);
}
ostream& operator<<(ostream& os, const Vect& v){
    os << v.x << "," << v.y << "," << v.z ;
    return os; 
}