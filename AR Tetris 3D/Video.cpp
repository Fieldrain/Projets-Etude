#include "Video.h"

Video::Video()
{
    vReader = new VideoCapture("VID.mp4");
    if (!vReader->isOpened())
    {
        cerr<<"Could not open video"<<endl;
    }
}


Video::~Video()
{
}

bool Video::GetLecture(){
    return lecture;
}

void Video::SetLecture(){
    lecture = !lecture;
}

Mat Video::GetFrame(){
    Mat theInputImage;

    if(vReader->grab())
        vReader->retrieve(theInputImage);

    return theInputImage;
}

Mat Video::GetUndistortFrame(Mat theInputImage,CameraParameters* camParam){
    Mat theUndInputImage;

    theUndInputImage.create(theInputImage.size(),CV_8UC3);
    //transform color that by default is BGR to RGB because windows systems do not allow reading BGR images with opengl properly
    cvtColor(theInputImage,theInputImage,CV_BGR2RGB);
    //remove distorion in image
    undistort(theInputImage,theUndInputImage, camParam->CameraMatrix, camParam->Distorsion);

    return theUndInputImage;
}



Mat Video::GetResizeFrame(Mat theUndInputImage,Size theGlWindowSize){
    Mat theResizedImage;

    resize(theUndInputImage,theResizedImage,theGlWindowSize);

    return theResizedImage;
}
