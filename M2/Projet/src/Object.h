#ifndef OBJECT_H
#define OBJECT_H

#include "Vertices.h"
#include "Shader.h"
#include "Uv.h"
#include "Tangentes.h"

enum TypeObject{TRIANGLE,LIGNE,CARRE,POLYGONE};
#define PI 3.141592654

struct BufferId{
	GLuint bIDVert;
	GLuint bIDCoul;
	GLuint bIDInd;
	GLuint bIDUv;

	GLuint bIDTang1;
	GLuint bIDTang2;
	GLuint bIDUvIndice;

	GLuint bIDVao;
	bool set = false;

	void BufferID(){
		glGenBuffers(1, &bIDVert);
    	glGenBuffers(1, &bIDCoul);
    	glGenBuffers(1, &bIDInd);
		glGenBuffers(1, &bIDUv);

    	glGenTextures(1, &bIDTang1);
		glGenTextures(1, &bIDTang2);
		glGenTextures(1, &bIDUvIndice);

    	glGenVertexArrays(1, &bIDVao);
		set = true;
	}

	~BufferId(){
		glDeleteBuffers(1, &bIDVert);
    	glDeleteBuffers(1, &bIDCoul);
    	glDeleteBuffers(1, &bIDInd);
		glDeleteBuffers(1, &bIDUv);

    	glDeleteTextures(1, &bIDTang1);
		glDeleteTextures(1, &bIDTang2);
		glDeleteTextures(1, &bIDUvIndice);

    	glDeleteVertexArrays(1, &bIDVao);
	}
};

class Object
{
protected:
	Vertices* points;
	vector<int> indices;
	Tangentes* tangentes;
	Uv* uv;

	BufferId bID;
	
	void ShowDefault(GLenum affichage,int pas);
	void ShowVBODefault(GLenum affichage);

public:

	Vertices* GetVertices();
	vector<int> GetIndices();
	Tangentes* getTangentes();
	
	void SetVertices(Vertices* Sommet);
	void SetIndices(vector<int> Indices);
	void SetTangentes(Tangentes* newTangentes);
	void SetUv(Uv* newUv);

	Vertices * ApplyMat(Mat<double> transformation);
	vector<pair<Col<double>,Col<double>>> CalculTangentes(vector<pair<Col<double>,Col<double>>> tangentesInit,Mat<double> transformation);

	void GenereVBO(Shader* shader);
	void ShowTangentes(int repere);
	
	virtual TypeObject GetType() =0;
	virtual void Show() =0;
	virtual void ShowVBO() =0;
	virtual vector<int> GetIndices(int numeroDepart) = 0;

	Object();
	Object(Vertices* Sommet);
	Object(Vertices* Sommet, vector<int> Indices);
	~Object();
};

#endif

