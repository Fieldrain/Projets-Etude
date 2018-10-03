#pragma once

#include "Arrete.h"
#include "Object.h"
#include <vector>

using namespace std;

class Carreau{
    private:
        vector<Vertex*> points; //0 -> HG, 1 -> HD, 2-> BD, 3-> BG

        double interpolation(double v0,double v1,double p0,double p1);

    public:
        Carreau(vector<Vertex*> Points);
        ~Carreau();

        vector<Arrete*> getArrete(Object* objects);

};