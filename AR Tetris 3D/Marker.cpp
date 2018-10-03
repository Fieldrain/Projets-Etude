#include "Marker.h"

Marker::Marker()
{
    mDetector = new MarkerDetector();
}


Marker::~Marker()
{
}

void Marker::DetectMarkers(Mat theUndInputImage, CameraParameters* camParam){

    mDetector->detect(theUndInputImage,markers, camParam->CameraMatrix,Mat(),theMarkerSize,false);

}

void Marker::Affiche(){
    double modelview_matrix[16];
    for (unsigned int m=0;m<Markers.size();m++)
    {
        Markers[m].glGetModelViewMatrix(modelview_matrix);// recupere coordonne reference de ce marqueur
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glLoadMatrixd(modelview_matrix);// change par celui du marqueurs

        glColor3f(1,0.4,0.4);
        glTranslatef(0, theMarkerSize, 0);

        glPushMatrix();
        glutWireCube( theMarkerSize);
        glPopMatrix();
    }
}

Marker Marker::GetMarker(int id){

    Marker r;
    for(Marker m : markers){
        if(m.id == id)
            return m;
    }

    return r;
}

float Marker::GetMarkerSize(){
    return theMarkerSize;
}