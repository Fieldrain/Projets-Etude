#ifndef OBJECT_H
#define OBJECT_H

#include "Vertices.h"
#include "Shader.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

#include <glm/glm.hpp>

#define PI 3.141592654

struct BufferId{
	GLuint bIDVert;
    GLuint bIDInd;
	GLuint bIDCoul;
	GLuint bIDNorm;
	GLuint bIDUv;
	GLuint bIDVao;
	GLuint bIDTexture;
	bool set = false;

	void BufferID(){
		glGenBuffers(1, &bIDVert);
    	glGenBuffers(1, &bIDCoul);
		glGenBuffers(1, &bIDNorm);
		glGenBuffers(1, &bIDUv);
    	glGenBuffers(1, &bIDInd);
    	glGenVertexArrays(1, &bIDVao);
		glGenTextures(1,&bIDTexture);
		set = true;
	}

	~BufferId(){
		glDeleteBuffers(1, &bIDVert);
    	glDeleteBuffers(1, &bIDCoul);
		glDeleteBuffers(1, &bIDNorm);
		glDeleteBuffers(1, &bIDUv);
    	glDeleteBuffers(1, &bIDInd);
    	glDeleteVertexArrays(1, &bIDVao);
		glDeleteTextures(1,&bIDTexture);
	}
};

class Object
{
protected:
	Vertices* points;
	Vertices* normales;
	Vertices* uv;
	int* indices;
	int nbIndice;
	BufferId bID;
	
	void ShowDefault(GLenum affichage,int pas);
	void ShowVBODefault(GLenum affichage);
	GLubyte *glmReadPPM(const char *filename, int *width, int *height);

public:
	void InitTexture(string fileName);

	void GenereVBO(Shader* shader);
	virtual void Show() =0;
	virtual void ShowVBO() =0;

	Object();
	~Object();
};

#endif

