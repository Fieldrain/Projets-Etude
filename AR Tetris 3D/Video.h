#pragma once

#include "Camera.h"
#include <iostream>
#include <GL/gl.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class Video
{
private:
	VideoCapture *vReader;
    bool lecture=true;

public:
	Video();
	~Video();

    bool GetLecture();
    void SetLecture();

	Mat GetFrame();
    Mat GetUndistortFrame(Mat theInputImage,CameraParameters* camParam);
    Mat GetResizeFrame(Mat theUndInputImage, Size theGlWindowSize);
};

