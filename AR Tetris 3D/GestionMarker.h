#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <aruco/aruco.h>
#include <aruco/cvdrawingutils.h>

using namespace cv;
using namespace std;
using namespace aruco;

class GestionMarker
{
private:
    float theMarkerSize=0.035;
    MarkerDetector* mDetector;
    vector<Marker> markers;

public:
	GestionMarker();
	~GestionMarker();

    void DetectMarkers(Mat theUndInputImage, CameraParameters* camParam);
    Marker GetMarker(int id);
    float GetMarkerSize();

    void Affiche();
};

