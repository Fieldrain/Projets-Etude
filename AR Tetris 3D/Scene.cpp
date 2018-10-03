#include "Scene.h"

Scene::Scene()
{
    compteurDeplacementPiece = 0;
    video = new Video();
    camera = new Camera();
    gestMarker = new GestionMarker();

    theInputImage = video->GetFrame();

    theUndInputImage = video->GetUndistortFrame(theInputImage, camera->GetCamParam());

    frame = new TetrisFrame(11);
}

Scene::~Scene()
{
    Clear();
}

void Scene::AddObjet(Objet *o)
{
    listeObjet.push_back(o);
}

void Scene::AfficheScene(Size theGlWindowSize, bool bMarker)
{
    if(!gameover){
        if(compteurDeplacementPiece == 2){
            DeplacePiece(Bas);
            compteurDeplacementPiece = 0;
        }else
            compteurDeplacementPiece++;
    }

    camera->SetCamera(theGlWindowSize, theResizedImage, theInputImage);

    if (bMarker)
	gestMarker->Affiche();

    double modelview_matrix[16];
    Marker m = gestMarker->GetMarker(701);
    
    m.glGetModelViewMatrix(modelview_matrix);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLoadMatrixd(modelview_matrix);

    frame->Affiche();

    if(gameover){
        string s = "GAME OVER";

        glColor3f(1.,0.,0.);
        glRasterPos2f(0.1,0.1);
        for(int i=0;i<s.length();i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s.data()[i]);
        }


    }

    for (Objet *o : listeObjet)
    {
		o->Affiche();
    }
}

void Scene::Lire(Size theGlWindowSize)
{
    if (video->GetLecture())
    {
		// recupere l'image
		theInputImage = video->GetFrame();

		if (theInputImage.rows != 0)
		{
			// recupere l'image sans la distorsion
			theUndInputImage = video->GetUndistortFrame(theInputImage, camera->GetCamParam());

			//recherche marker
			gestMarker->DetectMarkers(theUndInputImage, camera->GetCamParam());

			// recupere l'image recadrer
			theResizedImage = video->GetResizeFrame(theUndInputImage, theGlWindowSize);
		}
    }
}

void Scene::DeplacePiece(Sens s){
    if(!gameover){
        gameover = !frame->DeplacePiece(s);
    }
        
}

void Scene::RotatePiece(SensRotation s){
    if(!gameover)
        frame->RotatePiece(s);
}

void Scene::Clear()
{
    for (Objet *o : listeObjet)
    {
	delete o;
    }
    listeObjet.clear();
}

Camera *Scene::GetCamera()
{
    return camera;
}

Size Scene::GetSize()
{
    return theInputImage.size();
}

void Scene::Resize(Size theGlWindowSize)
{
    if (theUndInputImage.rows != 0)
	resize(theUndInputImage, theResizedImage, theGlWindowSize);
}

void Scene::SetLecture()
{
    video->SetLecture();
}
