#ifndef MARCHING_H
#define MARCHING_H

#include "Vertices.h"
#include "Grille.h"

struct BufferId{
	GLuint bIDVert;
    GLuint bIDInd;
	GLuint bIDCoul;
	GLuint bIDNorm;
	GLuint bIDVao;
	bool set = false;

	void BufferID(){
		glGenBuffers(1, &bIDVert);
    	glGenBuffers(1, &bIDCoul);
    	glGenBuffers(1, &bIDInd);
    	glGenVertexArrays(1, &bIDVao);
		set = true;
	}

	~BufferId(){
		glDeleteBuffers(1, &bIDVert);
    	glDeleteBuffers(1, &bIDCoul);
    	glDeleteBuffers(1, &bIDInd);
    	glDeleteVertexArrays(1, &bIDVao);
	}
};

class Marching
{
private:
	Vertices* points;
	Grille* grille = NULL;
	BufferId bID;
	vector<int> indices;

    int lignes;
    int colonnes;
    void generateVBO();

public:
    Marching(int L=60, int C=80);
    ~Marching();

	void CalculPoint(Object* objects);
    void ShowPoint();

	void CalculArrete(Object* objects);
	void ShowArrete();
};

#endif

