#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include "Vertices.h"
#include "Shader.h"

#define PI 3.141592654

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
		glGenBuffers(1, &bIDNorm);
    	glGenVertexArrays(1, &bIDVao);
		set = true;
	}

	~BufferId(){
		glDeleteBuffers(1, &bIDVert);
    	glDeleteBuffers(1, &bIDCoul);
    	glDeleteBuffers(1, &bIDInd);
		glDeleteBuffers(1, &bIDNorm);
    	glDeleteVertexArrays(1, &bIDVao);
	}
};

class Object
{
protected:
	Vertices* points;
	Vertices* normales;
	vector<int> indices;
	BufferId bID;
	
	void ShowDefault(GLenum affichage,int pas);
	void ShowVBODefault(GLenum affichage);

public:

	Vertices* GetVertices();
	vector<int> GetIndices();
	
	void SetVertices(Vertices* Sommet);
	void SetIndices(vector<int> Indices);

	void GenereVBO(Shader* shader);
	virtual void Show() =0;
	virtual void ShowVBO() =0;

	Object();
	Object(Vertices* Sommet);
	Object(Vertices* Sommet, vector<int> Indices);
	~Object();
};

#endif

