
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <glext.h>
#include "Ground.h"
#include "Forest.h"


Forest::Forest(Ground *pGround, int NbTree) : NbTree(NbTree)
{
	int i,j;
	bool OK;
	Vector3D u;
	Point3D RayOrigin;
	Vector3D RayDirection(0,-1,0);

	Position = new Point3D[NbTree];
	Size = new float[NbTree];


	for (i=0;i<NbTree;i++)
	{
		do 
		{
			OK = true;
			Position[i].x = pGround->Size*((float)rand()/(float)RAND_MAX-0.5f);
			Position[i].z = pGround->Size*((float)rand()/(float)RAND_MAX-0.5f);
			Position[i].y = pGround->Elevation(Position[i].x, Position[i].z);
			Size[i] = 1.0f+2.0f*(float)rand()/(float)RAND_MAX;
			for (j=0;j<i;j++)
			{
				u = Vector3D((Point3D)Position[i] , (Point3D)Position[j]);
				u.y = 0.0f;
				if (Norm(u)<(Size[i]+Size[j]) || Norm(Position[i])<2.0f) OK=false;
			}
		} while(!OK);

	}

	
	Point3D P[9];
	float e;
	e = 0.01f;
	int Tr[7*3] = 
	{
		0,1,2,
		2,1,3,
		7,2,4,
		4,2,3,
		4,3,5,
		6,8,4,
		6,4,5
	};
	int T2[3*3] = 
	{
		0,2,1,
		7,4,2,
		8,6,4
	};

	P[0] = Point3D (-1.0f,0,-e);
	P[1] = Point3D (-e,0,-e);
	P[2] = Point3D (-0.3f,1,-e);
	P[3] = Point3D (-e,1,-e);
	P[4] = Point3D (-0.2f,2.0f,-e);
	P[5] = Point3D (-e,2.0f,-e);
	P[6] = Point3D (-e,3.0f,-e);
	P[7] = Point3D (-0.8f,1,-e);
	P[8] = Point3D (-0.5f,2.0f,-e);

	for (i=0;i<9;i++) P[i]*=0.5f;


	ListId = glGenLists(1);
	glNewList(ListId,GL_COMPILE);
	glPushMatrix();

	for (int n=0;n<9;n++)
	{
		glBegin(GL_TRIANGLES);

		for (i=0;i<7*3;i++)
		{
			glNormal3f(0,0,-1);
			glVertex3fv(&P[Tr[i]].x);
		}

		for (i=0;i<7;i++)
		{
			Point3D Pt;
			Pt = P[Tr[i*3]];
			Pt.z = Pt.z+2.0f*e;
			glNormal3f(0,0,1);
			glVertex3fv(&Pt.x);
			Pt = P[Tr[i*3+2]];
			Pt.z = Pt.z+2.0f*e;
			glNormal3f(0,0,1);
			glVertex3fv(&Pt.x);
			Pt = P[Tr[i*3+1]];
			Pt.z = Pt.z+2.0f*e;
			glNormal3f(0,0,1);
			glVertex3fv(&Pt.x);
		}
		glEnd();

		for (i=0;i<3;i++)
		{
			Point3D A,B,C,D,E,F;
			Vector3D N;

			A = P[T2[i*3]];
			B = P[T2[i*3+1]];
			C = P[T2[i*3+2]];
			D = A + Point3D(0,0,2*e);
			E = B + Point3D(0,0,2*e);
			F = C + Point3D(0,0,2*e);
			N.y = B.x-A.x;
			N.x = A.y-B.y;
			N.z = 0.0f;
			N.Normalize();

			glBegin(GL_QUADS);
			glNormal3fv(&N.x);
			glVertex3fv(&A.x);
			glNormal3fv(&N.x);
			glVertex3fv(&B.x);
			glNormal3fv(&N.x);
			glVertex3fv(&E.x);
			glNormal3fv(&N.x);
			glVertex3fv(&D.x);


			glNormal3f(0,-1,0);
			glVertex3fv(&A.x);
			glNormal3f(0,-1,0);
			glVertex3fv(&D.x);
			glNormal3f(0,-1,0);
			glVertex3fv(&F.x);
			glNormal3f(0,-1,0);
			glVertex3fv(&C.x);

			glEnd();
		}
		glRotatef(360.0/9.0,0,1,0);
	}
	glPopMatrix();
	glEndList();


}


void Forest::Draw()
{
	int i;
	float AmbDiff[4] = {0.0,0.7f,0,1};
	float SpecCol[4] = {0.3f,0.9f,0.3f,1};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDisable(GL_TEXTURE_2D);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_BLEND);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1.0, 1.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR,SpecCol);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,AmbDiff);	
	for (i=0;i<NbTree;i++)
	{
		glPushMatrix();
		glTranslatef(Position[i].x,Position[i].y,Position[i].z);
		glScalef(Size[i],Size[i],Size[i]);
		glCallList(ListId);

		glPopMatrix();	
	}
	
}

bool Forest::Collision(const Point3D &Destination){
	for (int i=0;i<NbTree;i++){

		Point3D centre = Position[i];
		float r = Size[i]/2.0;
		float d2 = (Destination.x-centre.x)*(Destination.x-centre.x) + (Destination.y-centre.y)*(Destination.y-centre.y) + (Destination.z-centre.z)*(Destination.z-centre.z); 
		if (d2<=r*r) 
			return true;

	}

	return false;
}
