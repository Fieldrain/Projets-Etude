#ifndef BONHOMMENEIGE_H
#define BONHOMMENEIGE_H

#include "MorceauBonhommeNeige.h"

class BonhommeNeige {
    private:
        MorceauBonhommeNeige* root;
        double t = 0;
        int selectionCourante = 0;
    public:

    void Init(Shader* shader);
    void Show(Shader* shader);
    void Up();
    void Down();
    void SelectionUp();
    void SelectionDown();

    BonhommeNeige();
    ~BonhommeNeige();
};

#endif