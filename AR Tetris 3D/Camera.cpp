#include "Camera.h"

Camera::Camera()
{
	glClearColor( 0.0, 0.0, 0.0, 1.0 );
  	glClearDepth( 1.0 );

	camParam = new CameraParameters();
	camParam->readFromXMLFile("res.yml");
}


Camera::~Camera()
{
}

void Camera::SetCamera(Size theGlWindowSize, Mat theResizedImage, Mat theInputImage){

    if (theResizedImage.rows==0)
        return ;
        
	glOrtho(0, theGlWindowSize.width, 0, theGlWindowSize.height, -1.0, 1.0);
	glViewport(0, 0, theGlWindowSize.width , theGlWindowSize.height);
    glDisable(GL_TEXTURE_2D);
    glPixelZoom( 1, -1);
    glRasterPos3f( 0, theGlWindowSize.height  - 0.5, -1.0 );
    glDrawPixels( theGlWindowSize.width , theGlWindowSize.height , GL_RGB , GL_UNSIGNED_BYTE , theResizedImage.ptr(0) );

    ///Set the appropriate projection matrix so that rendering is done in a enrvironment
    //like the real camera (without distorsion)
    glMatrixMode(GL_PROJECTION);
    double proj_matrix[16];
    camParam->glGetProjectionMatrix(theInputImage.size(),theGlWindowSize,proj_matrix,0.05,10);
    glLoadIdentity();
    glLoadMatrixd(proj_matrix);

}

CameraParameters* Camera::GetCamParam(){
	return camParam;
}

void Camera::ResizeCamParam(Mat image){
	camParam->resize(image.size());
}