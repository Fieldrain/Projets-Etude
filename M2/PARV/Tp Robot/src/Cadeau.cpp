
#include <GL/gl.h>
#include <stdlib.h>
#include <glext.h>
#include "Cadeau.h"

Cadeau::Cadeau(int MaxCount,  Ground *pGround, Forest *pForest) : MaxCount(MaxCount)
{
	int i,j;
	Alive = new bool[MaxCount];
	Position = new Point3D[MaxCount];
	StillAlive = MaxCount;
	for (i=0;i<MaxCount;i++) 
	{
		Position[i] = Point3D(0,500,0);
		Alive[i] = true;
	}
	TextureId = LoadTexture("textures/kdo.tga"); 
	bool Intersect;
	for (i=0;i<MaxCount;i++)
	{
		do 
		{
			Position[i].x = pGround->Size*((float)rand()/(float)RAND_MAX-0.5f);
			Position[i].z = pGround->Size*((float)rand()/(float)RAND_MAX-0.5f);
			Position[i].y = pGround->Elevation(Position[i].x, Position[i].z);
			Intersect = false;
			for (j=0;j<pForest->NbTree;j++)
			{
				Vector3D u(Position[i],pForest->Position[j]);
				float r = pForest->Size[j]+0.5f;
				if (NormSquare(u)<r*r)
				{
					Intersect = true;
					break;
				}
			}
		} while(Intersect);
		Alive[i] = true;
	}
	StillAlive = MaxCount;
}

void Cadeau::Draw()
{
	int i;
	float AmbDiff[4] = {1.0f,1.0f,1.0f,1};
	float SpecCol[4] = {0.9f,0.9f,0.9f,1};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_BLEND);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1.0, 1.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR,SpecCol);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,AmbDiff);	
	glBindTexture(GL_TEXTURE_2D,TextureId);


	for (i=0;i<MaxCount;i++)
		if (Alive[i])
		{
			glPushMatrix();
			glTranslatef(Position[i].x,Position[i].y,Position[i].z);
			glScalef(0.3f,0.3f,0.3f);
			glBegin(GL_QUADS);
			// face 1
			glNormal3f(0,0,-1);
			glTexCoord2f(0,0);
			glVertex3f(-1,0,-1);
			glTexCoord2f(0.495f,0);
			glVertex3f( 1,0,-1);
			glTexCoord2f(0.495f,0.495f);
			glVertex3f( 1,2,-1);
			glTexCoord2f(0,0.495f);
			glVertex3f(-1,2,-1);
			// face 2
			glNormal3f(1,0,0);
			glTexCoord2f(0,0);
			glVertex3f( 1,0,-1);
			glTexCoord2f(0.495f,0);
			glVertex3f( 1,0, 1);
			glTexCoord2f(0.495f,0.495f);
			glVertex3f( 1,2, 1);
			glTexCoord2f(0,0.495f);
			glVertex3f( 1,2,-1);
			// face 3
			glNormal3f(0,0,1);
			glTexCoord2f(0,0);
			glVertex3f( 1,0, 1);
			glTexCoord2f(0.495f,0);
			glVertex3f(-1,0, 1);
			glTexCoord2f(0.495f,0.495f);
			glVertex3f(-1,2, 1);
			glTexCoord2f(0,0.495f);
			glVertex3f( 1,2, 1);
			// face 4
			glNormal3f(-1,0,0);
			glTexCoord2f(0,0);
			glVertex3f(-1,0,-1);
			glTexCoord2f(0.495f,0);
			glVertex3f(-1,0, 1);
			glTexCoord2f(0.495f,0.495f);
			glVertex3f(-1,2, 1);
			glTexCoord2f(0,0.495f);
			glVertex3f(-1,2,-1);
			// face 5
			glNormal3f(0,1,0);
			glTexCoord2f(0,0.5f);
			glVertex3f(-1,2,-1);
			glTexCoord2f(0.5f,0.5f);
			glVertex3f( 1,2,-1);
			glTexCoord2f(0.5f,1);
			glVertex3f( 1,2, 1);
			glTexCoord2f(0,1);
			glVertex3f(-1,2, 1);
			glEnd();
			glPopMatrix();
		}

	glDisable(GL_TEXTURE_2D);
}

void Cadeau::Collision(const Point3D &Destination){
	for (int i=0;i<MaxCount;i++){
		if (Alive[i])
		{
			Point3D centre = Position[i];
			float d2 = (Destination.x-centre.x)*(Destination.x-centre.x) + (Destination.y-centre.y)*(Destination.y-centre.y) + (Destination.z-centre.z)*(Destination.z-centre.z); 
			if (d2<=1.0) 
				Alive[i] = false;
		}
	}
}
