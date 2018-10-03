#ifndef MODELE_H
#define MODELE_H

#include "vue.h"
#include <QList>

class Modele
{
private:
    QList<Vue*> vues;
public:
    Modele();

    void abonne(Vue *vue);
    void update();
};

#endif // MODELE_H
