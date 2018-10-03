#pragma once
#include "Objet.h"
#include <math.h>

enum SensRotation{Horaire,AntiHoraire};
enum Sens{Gauche,Droite,Bas,Avant,Arriere};
enum TypePiece{I,O,T,L,J,Z,S,NbPiece = 7}; // voir wikipedia https://fr.wikipedia.org/wiki/Tetris#Pi.C3.A8ces_du_jeu

class Piece : public Objet //implemtation basee sur celle de ce site http://codeincomplete.com/posts/javascript-tetris/
{
private:
	TypePiece type;
	int direction;
	vector<unsigned short> combinaison;


public:
	Piece();
	Piece(Piece* p);
	Piece(vector<unsigned short> Combinaison, TypePiece Type);
	~Piece();

	vector<vector<int>> *GetShape();
	TypePiece GetType();

    void Affiche();
	void Translate(float x, float y, float z) ;
	void Translate(int *pos) ;
	void Rotate(int type);
	void Scale();
};
