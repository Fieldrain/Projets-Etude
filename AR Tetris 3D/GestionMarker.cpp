#include "GestionMarker.h"

GestionMarker::GestionMarker()
{
    mDetector = new MarkerDetector();
}


GestionMarker::~GestionMarker()
{
}

void GestionMarker::DetectMarkers(Mat theUndInputImage, CameraParameters* camParam){

    mDetector->detect(theUndInputImage,markers, camParam->CameraMatrix,Mat(),theMarkerSize,false);

}

void GestionMarker::Affiche(){
    double modelview_matrix[16];
    for (unsigned int m=0;m<markers.size();m++)
    {
        markers[m].glGetModelViewMatrix(modelview_matrix);// recupere coordonne reference de ce marqueur
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glLoadMatrixd(modelview_matrix);// change par celui du marqueurs

        glColor3f(1,0.4,0.4);

        glPushMatrix();
        glutWireCube( theMarkerSize);
        glPopMatrix();
    }
}

Marker GestionMarker::GetMarker(int id){

    Marker r;
    for(Marker m : markers){
        if(m.id == id)
            return m;
    }

    return r;
}

float GestionMarker::GetMarkerSize(){
    return theMarkerSize;
}