
#include <GL/gl.h>
#include <glext.h>
#include "Ground.h"
#include "Texture.h"


Ground::Ground(float Size, int Nb) : Size(Size)
{
	int i,j;
	NbSide = Nb;
	VertexCount = Nb*Nb;
	VertexArray = new Point3D[VertexCount];
	NormalArray = new Vector3D[VertexCount];
	for (i=0;i<Nb;i++)
		for (j=0;j<Nb;j++)
		{
			VertexArray[i+j*Nb].x = Size*(float)i/(float)(Nb-1)-Size*0.5f;
			VertexArray[i+j*Nb].z = Size*(float)j/(float)(Nb-1)-Size*0.5f;
			VertexArray[i+j*Nb].y = Elevation(VertexArray[i+j*Nb].x,VertexArray[i+j*Nb].z);
			NormalArray[i+j*Nb] = Normal(VertexArray[i+j*Nb].x,VertexArray[i+j*Nb].z);
		}

	TexId = LoadTexture("Neige.tga",GL_MIRRORED_REPEAT);
}

float Ground::Elevation(float x, float z)
{
	return 1.0f*cosf(x/5.0f)*cosf(z/3.0f);
}

Vector3D Ground::Normal(float x, float z)
{
	Vector3D u;
	Vector3D v;
	u.x = 1e-4f;
	u.y = Elevation(x+1e-4f,z)-Elevation(x,z);
	u.z = 0.0f;
	v.x = 0.0f;
	v.y = Elevation(x,z+1e-4f)-Elevation(x,z);
	v.z = 1e-4f;
	Vector3D N;
	N.CrossProduct(v,u);
	N.Normalize();
	return N;
}

void Ground::Draw()
{
	int i,j;

/*	glDisable(GL_LIGHTING);
	glPointSize(4.0f);
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
	for (i=0;i<VertexCount;i++) glVertex3fv(&VertexArray[i].x);
	glEnd();
	glPointSize(1.0f);

	glColor3f(0,1,1);
	glBegin(GL_LINES);
		for (i=0;i<VertexCount;i++) 
		{
			Point3D P = VertexArray[i];
			glVertex3fv(&P.x);
			P+=NormalArray[i];
			glVertex3fv(&P.x);
		}
	glEnd();*/

	float AmbDiff[4] = {0.9f,0.9f,0.9f,1};
	float SpecCol[4] = {0.5f,0.5f,1.0f,1};
	glMaterialfv(GL_FRONT, GL_SPECULAR,SpecCol);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,AmbDiff);	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,TexId);


	for (j=0;j<NbSide-1;j++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (i=0;i<NbSide-1;i++)
		{
			glTexCoord2f(VertexArray[i+NbSide*j].x/10.0f,VertexArray[i+NbSide*j].z/10.0f);
			glNormal3fv(&NormalArray[i+NbSide*j].x);
			glVertex3fv(&VertexArray[i+NbSide*j].x);
			glTexCoord2f(VertexArray[i+NbSide*(j+1)].x/10.0f,VertexArray[i+NbSide*(j+1)].z/10.0f);
			glNormal3fv(&NormalArray[i+NbSide*(j+1)].x);
			glVertex3fv(&VertexArray[i+NbSide*(j+1)].x);
		}
		glEnd();
	}

	glDisable(GL_TEXTURE_2D);


}

