#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <aruco/aruco.h>


using namespace aruco;
using namespace cv;

class Camera
{
private:
	CameraParameters* camParam;

public:
	Camera();
	~Camera();

	void SetCamera(Size theGlWindowSize, Mat theResizedImage, Mat theInputImage);

	CameraParameters* GetCamParam();

	void ResizeCamParam(Mat image);
};

