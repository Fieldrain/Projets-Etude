#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cmath>
#include "Vertices.h"

enum TypeObject{FORME};
#define PI 3.141592654

struct BufferId{
	GLuint bIDVert;
    GLuint bIDInd;
	GLuint bIDCoul;
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

class Object
{
protected:
	Vertices* points;
	vector<int> indices;
	BufferId bID;
	
	void ShowVBODefault(GLenum affichage);
public:

	void GenereVBO();
	Vertices* GetVertices();
	void SetVertices(Vertices * Sommet);
	
	virtual TypeObject GetType() =0;
	virtual void ShowVBO() =0;

	Object();
	Object(Vertices* Sommet);
	~Object();
};

#endif

