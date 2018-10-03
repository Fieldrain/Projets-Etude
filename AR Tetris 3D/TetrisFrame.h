#pragma once

#include "FabriquePiece.h"
#include <opencv2/opencv.hpp>
#include <stdlib.h> 
#include <time.h> 

using namespace cv;

class TetrisFrame : public Objet
{
private:
	int departPiece[3];

    vector<vector<vector<int>>>* frame; 
    int taille; // nombre impair
	Piece* pieceCourante;
	FabriquePiece* fabrique;

public:
	TetrisFrame(int Taille);
	~TetrisFrame();

	void CreatePiece();
    bool AddPiece();
	bool IsColide(Piece* p, int* d);
	bool IsValide(Piece* p, int* d);
	
	bool DeplacePiece(Sens s);
	void RotatePiece(SensRotation s);

    void Affiche();
	void Translate(float x, float y, float z) ;
	void Rotate(int type);
	void Scale();
};
