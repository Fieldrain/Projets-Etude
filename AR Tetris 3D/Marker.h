#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <aruco/aruco.h>
#include <aruco/cvdrawingutils.h>

using namespace cv;
using namespace std;
using namespace aruco;

class Marker
{
private:
    float theMarkerSize=0.035;
    MarkerDetector* mDetector;
    vector<Marker> markers;

public:
	Marker();
	~Marker();

    void DetectMarkers(Mat theUndInputImage, CameraParameters* camParam);
    Markers GetMarker(int id);
    float GetMarkerSize();

    void Affiche();
};

