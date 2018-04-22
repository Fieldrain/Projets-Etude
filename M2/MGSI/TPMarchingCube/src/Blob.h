#pragma once

#include "Disk.h"

class Blob: public Object{
    private:
        vector<Disk*> disques;

    public:
        Blob();
        Blob(vector<Object*> Disques);
        ~Blob();

        void AddDisk(Disk* d);
        TypeObject GetType();

        Vertex* getCentre();
        void Move(Vertex* point);

	    pair<bool,double> In(Vertex* point);
        Disk* GetDisk(Vertex* point);
};