#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "Vertex.h"

enum TypeObject{DISK,BLOB};
#define PI 3.141592654

class Object
{
protected:
	Vertex* centre;

public:
	Object();
	Object(Vertex* Centre);
	~Object();

	virtual void Move(Vertex* point) = 0;

	virtual Vertex* getCentre() =0;

	virtual TypeObject GetType() =0;
	virtual pair<bool,double> In(Vertex* point) =0;
};

#endif

