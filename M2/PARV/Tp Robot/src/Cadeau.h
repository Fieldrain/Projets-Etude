#ifndef _CADEAU_H_
#define _CADEAU_H_

#include "Ground.h"
#include "Forest.h"

class Cadeau
{
public:
	Cadeau(int MaxCount, Ground *pGround, Forest *pForest);
	void Draw();
	void Collision(const Point3D &Destination);
	Point3D *Position;
	int MaxCount;
	bool *Alive;
	int StillAlive;
	unsigned TextureId;
};

#endif
