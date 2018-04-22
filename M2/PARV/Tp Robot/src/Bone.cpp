
#include <GL/gl.h>
#include "Bone.h"

Bone::Bone()
{
	SonCount = 0;
	Sons = NULL;
}


// Draws the Bone (The Reference + line from Center to Sons center)
void Bone::Draw(Matrix3x4 M)
{
	int i;
	Point3D O,R;

	M = M*Ref;
	O = M*Point3D(0,0,0);

	glBegin(GL_LINES);

	glColor3f(0.6f,0.6f,0);
	for (i=0;i<SonCount;i++)
	{
		glVertex3f(O.x,O.y,O.z);
		R = M*Sons[i]->Ref.O;
		glVertex3f(R.x,R.y,R.z);
	}


	glColor4f(0.8f,0,0,1);
	glVertex3f(O.x,O.y,O.z);
	R = M*Point3D(0.1f,0,0);
	glVertex3f(R.x,R.y,R.z);;

	glColor4f(0,0.8f,0,1);
	glVertex3f(O.x,O.y,O.z);
	R = M*Point3D(0,0.1f,0);
	glVertex3f(R.x,R.y,R.z);
	
	glColor4f(0,0,0.8f,1);
	glVertex3f(O.x,O.y,O.z);
	R = M*Point3D(0,0,0.1f);
	glVertex3f(R.x,R.y,R.z);
	glEnd();

	for (i=0;i<SonCount;i++)
	{
		Sons[i]->Draw(M);
	}

}


// Computes the global Matrice based on M being the parent World Matrix
void Bone::ComputeMatrix(Matrix3x4 M)
{
	Matrix = M*Ref;
	for (int i=0;i<SonCount;i++)
	{
		Sons[i]->ComputeMatrix(Matrix);
	}
}

// return a pointer to the bone whose Is==v
Bone* Bone::FindBone(unsigned v)
{
	Bone *B;
	int i;
	if (Id==v) return this;
	for (i=0;i<SonCount;i++)
	{
		B = Sons[i]->FindBone(v);
		if (B) return B;
	}
	return NULL;
}
