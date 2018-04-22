#ifndef _FOREST_H_
#define _FOREST_H_

#include "Ground.h"

class Forest
{
public:
	Forest(Ground *pGround, int NbTree);
	void Draw();
	bool Collision(const Point3D &Destination);
public:
	Point3D *Position;
	float *Size;
	int NbTree;
	unsigned ListId;
};

#endif
