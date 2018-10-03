#include "modele.h"

// classse mere de groupes,stations,parametres

/*--------------------------------CONSTRUCTEURS--------------------------------*/
Modele::Modele()
{
}

/*--------------------------------FONCTIONS PUBLIC--------------------------------*/
void Modele::abonne(Vue *vue){
    vues.append(vue);
}

void Modele::update(){
    foreach(Vue *vue, vues){
        vue->refresh();
    }
}
