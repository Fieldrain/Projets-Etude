#pragma once

#include "Camera.h"
#include "Video.h"
#include "GestionMarker.h"
#include "TetrisFrame.h"

class Scene
{
private:
	std::vector<Objet*> listeObjet;
	Mat theInputImage,theUndInputImage,theResizedImage;

	Video* video;
	Camera* camera;
	GestionMarker* gestMarker;
	TetrisFrame* frame;

	bool gameover = false;
	int compteurDeplacementPiece;
public:

	Scene();
	~Scene();

	void AddObjet(Objet *);
	void Clear();
	void AfficheScene(Size theGlWindowSize, bool bMarker);
	void Lire(Size theGlWindowSize);
	void DeplacePiece(Sens s);
	void RotatePiece(SensRotation s);

	Camera* GetCamera();
	Size GetSize();
	void Resize(Size theGlWindowSize);
	void SetLecture();

	
};

