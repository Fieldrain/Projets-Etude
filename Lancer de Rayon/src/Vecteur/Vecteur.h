#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

using namespace std;

class Vect{

private:
    double x,y,z;

    double clamp(double v,double min,double max);

public:
    Vect();
    Vect(double a, double b,double c);
    ~Vect();
    
    double X() const;
    double Y() const;
    double Z() const;

    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);
    void set(int i,double newVal);

    double length();
    Vect normalize();
    double dot(Vect v);
    Vect cross(Vect v);
    double distance(Vect v);
    Vect clamp(double min,double max);
    Vect clip();

    Vect reflect(Vect normal);
    Vect refract(Vect normal,double indice);

    void operator+=(const Vect v);
    Vect operator*(double s);
    Vect operator/(double s);
    Vect operator/(const Vect v);
    Vect operator*(const Vect v);
    double operator[](unsigned i) const;
    
    friend Vect operator+(const Vect first, const Vect second);
    friend Vect operator-(const Vect first, const Vect second);
    friend ostream& operator<<(ostream& os, const Vect& v);
};


