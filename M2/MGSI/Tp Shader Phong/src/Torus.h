#ifndef TORUS_H
#define TORUS_H

#include "Object.h"

class Torus : public Object{
    private:
        int nb_R;
        int nb_r;

        void create();
        void createIndice();
    public:
        Torus(int Nb_R = 40,int Nb_r = 20);
        ~Torus();
        void Show();
        void ShowVBO();
};

#endif