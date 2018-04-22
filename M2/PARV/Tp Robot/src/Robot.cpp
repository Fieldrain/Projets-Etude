
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <Teclibs/src/Tec3D.h>
#include "Robot.h"
#include "Ground.h"
#include "Forest.h"
#include "Cadeau.h"

#undef PI
#define PI 3.14156f

#define RAYON_ROBOT 0.35f

extern Ground *gGround;
extern Forest *pForest;
extern Cadeau *pCadeau;

Robot::Robot()
{
	int i,j;
	VertexCount = 46;
	VertexArray = new Point3D[VertexCount];

	VertexArray[0].Set(0.1f,0.45f,-0.05f);
	VertexArray[1].Set(0.1f,0.45f, 0.05f);
	VertexArray[2].Set(0.1f,0.55f, 0.05f);
	VertexArray[3].Set(0.1f,0.55f,-0.05f);
	VertexArray[4].Set(0.1f,0.40f,-0.15f);
	VertexArray[5].Set(0.1f,0.40f, 0.15f);
	VertexArray[6].Set(0.1f,0.70f, 0.15f);
	VertexArray[7].Set(0.1f,0.70f,-0.15f);
	VertexArray[8].Set(0.1f,0.56f, 0.05f);
	VertexArray[9].Set(0.1f,0.56f,-0.05f);

	VertexArray[10].Set(-0.1f,0.45f,-0.05f);
	VertexArray[11].Set(-0.1f,0.45f, 0.05f);
	VertexArray[12].Set(-0.1f,0.55f, 0.05f);
	VertexArray[13].Set(-0.1f,0.55f,-0.05f);
	VertexArray[14].Set(-0.1f,0.40f,-0.15f);
	VertexArray[15].Set(-0.1f,0.40f, 0.15f);
	VertexArray[16].Set(-0.1f,0.70f, 0.15f);
	VertexArray[17].Set(-0.1f,0.70f,-0.15f);
	VertexArray[18].Set(-0.1f,0.56f, 0.05f);
	VertexArray[19].Set(-0.1f,0.56f,-0.05f);

	for (i=0;i<4;i++) VertexArray[20+i] = VertexArray[i] + Point3D(0.24f,0,0);
	for (i=0;i<4;i++) VertexArray[24+i] = VertexArray[i] + Point3D(0.25f,0,0);
	for (i=0;i<4;i++) VertexArray[28+i] = VertexArray[i] + Point3D(0.26f,0,0);
	for (i=0;i<4;i++) VertexArray[32+i] = VertexArray[i+10] - Point3D(0.24f,0,0);
	for (i=0;i<4;i++) VertexArray[36+i] = VertexArray[i+10] - Point3D(0.25f,0,0);
	for (i=0;i<4;i++) VertexArray[40+i] = VertexArray[i+10] - Point3D(0.26f,0,0);
	VertexArray[44].Set(0.7f,0.5f,0);
	VertexArray[45].Set(-0.7f,0.5f,0);

	AttachArray = new Attach[VertexCount];

	for (i=0;i<VertexCount;i++) AttachArray[i].Set(0,-1,1.0f,0);

	AttachArray[0].Set(1,4,0.5f,0.5f);
	AttachArray[1].Set(1,4,0.5f,0.5f);
	AttachArray[2].Set(1,4,0.5f,0.5f);
	AttachArray[3].Set(1,4,0.5f,0.5f);
	AttachArray[4].Set(1,-1,1.0f,0.0f);
	AttachArray[5].Set(1,-1,1.0f,0.0f);
	AttachArray[6].Set(1,-1,1.0f,0.0f);
	AttachArray[7].Set(1,-1,1.0f,0.0f);
	AttachArray[8].Set(1,-1,1.0f,0.0f);
	AttachArray[9].Set(1,-1,1.0f,0.0f);
	AttachArray[10].Set(1,2,0.5f,0.5f);
	AttachArray[11].Set(1,2,0.5f,0.5f);
	AttachArray[12].Set(1,2,0.5f,0.5f);
	AttachArray[13].Set(1,2,0.5f,0.5f);
	AttachArray[14].Set(1,-1,1.0f,0.0f);
	AttachArray[15].Set(1,-1,1.0f,0.0f);
	AttachArray[16].Set(1,-1,1.0f,0.0f);
	AttachArray[17].Set(1,-1,1.0f,0.0f);
	AttachArray[18].Set(1,-1,1.0f,0.0f);
	AttachArray[19].Set(1,-1,1.0f,0.0f);

	for (i=0;i<4;i++) AttachArray[20+i].Set(4,5,0.7f,0.3f);
	for (i=0;i<4;i++) AttachArray[24+i].Set(4,5,0.5f,0.5f);
	for (i=0;i<4;i++) AttachArray[28+i].Set(4,5,0.3f,0.7f);
	for (i=0;i<4;i++) AttachArray[32+i].Set(2,3,0.7f,0.3f);
	for (i=0;i<4;i++) AttachArray[36+i].Set(2,3,0.5f,0.5f);
	for (i=0;i<4;i++) AttachArray[40+i].Set(2,3,0.3f,0.7f);
	AttachArray[44].Set(5,-1,1.0f,0.0f);
	AttachArray[45].Set(3,-1,1.0f,0.0f);


	NormalCount = 6+8;
	NormalArray = new Vector3D[NormalCount];
	NormalArray[0].Set(1,0,0);
	NormalArray[1].Set(-1,0,0);
	NormalArray[2].Set(0,0,1);
	NormalArray[3].Set(0,0,-1);
	NormalArray[4].Set(0,1,0);
	NormalArray[5].Set(0,-1,0);

	TriangleCount = 88;
	TriangleArray = new Triangle[TriangleCount];
	Set(0, 5,4,1, 0,0,0);
	Set(1, 4,0,1, 0,0,0);
	Set(2, 3,8,2, 0,0,0);
	Set(3, 8,3,9, 0,0,0);
	Set(4, 8,9,6, 0,0,0);
	Set(5, 9,7,6, 0,0,0);
	Set(6, 1,2,5, 0,0,0);
	Set(7, 5,2,8, 0,0,0);
	Set(8, 5,8,6, 0,0,0);
	Set(9, 3,0,4, 0,0,0);
	Set(10, 3,4,9, 0,0,0);
	Set(11, 9,4,7, 0,0,0);
	
	Set(12, 15,11,14, 1,1,1);
	Set(13, 14,11,10, 1,1,1);
	Set(14, 13,12,18, 1,1,1);
	Set(15, 18,19,13, 1,1,1);
	Set(16, 18,16,19, 1,1,1);
	Set(17, 19,16,17, 1,1,1);
	Set(18, 11,15,12, 1,1,1);
	Set(19, 15,18,12, 1,1,1);
	Set(20, 15,16,18, 1,1,1);
	Set(21, 13,14,10, 1,1,1);
	Set(22, 13,19,14, 1,1,1);
	Set(23, 19,17,14, 1,1,1);

	Set(24, 5,6,15, 2,2,2);
	Set(25, 15,6,16, 2,2,2);
	Set(26, 7,4,14, 3,3,3);
	Set(27, 7,14,17, 3,3,3);

	Set(28, 6,7,17, 4,4,4);
	Set(29, 6,17,16, 4,4,4);

	Set(30, 4,5,15, 5,5,5);
	Set(31, 4,15,14, 5,5,5);

	int n[4] = {5,2,4,3};
	for (i=0;i<4;i++)
	{
		Set(32+i*2, i,i+20,(i+1)%4+20 ,n[i],n[i],n[i]);
		Set(32+i*2+1, i,(i+1)%4+20,(i+1)%4 ,n[i],n[i],n[i]);
		Set(40+i*2, i+20,i+24,(i+1)%4+24 ,n[i],n[i],n[i]);
		Set(40+i*2+1, i+20,(i+1)%4+24,(i+1)%4+20 ,n[i],n[i],n[i]);
		Set(48+i*2, i+24,i+28,(i+1)%4+28 ,n[i],n[i],n[i]);
		Set(48+i*2+1, i+24,(i+1)%4+28,(i+1)%4+24 ,n[i],n[i],n[i]);
		Set(56+i, i+28,44,(i+1)%4+28, 6+i,6+i,6+i);
		NormalArray[6+i] = TriangleArray[56+i].Normal(VertexArray);
	}

	for (i=0;i<4;i++)
	{
		Set(60+i*2, i+10,(i+1)%4+32,i+32 ,n[i],n[i],n[i]);
		Set(60+i*2+1, i+10,(i+1)%4+10,(i+1)%4+32 ,n[i],n[i],n[i]);
		Set(68+i*2, i+32,(i+1)%4+36,i+36 ,n[i],n[i],n[i]);
		Set(68+i*2+1, i+32,(i+1)%4+32,(i+1)%4+36 ,n[i],n[i],n[i]);
		Set(76+i*2, i+36,(i+1)%4+40,i+40 ,n[i],n[i],n[i]);
		Set(76+i*2+1, i+36,(i+1)%4+36,(i+1)%4+40 ,n[i],n[i],n[i]);
		Set(84+i, i+40,(i+1)%4+40,45, 10+i,10+i,10+i);
		NormalArray[10+i] = TriangleArray[84+i].Normal(VertexArray);
	}


	Vector3D *N;
	N = new Vector3D[VertexCount];
	for (i=0;i<VertexCount;i++) N[i].Set(0);

	for (i=0;i<TriangleCount;i++)
	for (j=0;j<3;j++)
	{
		int p = TriangleArray[i].Vertex_Index[j];
		N[p]+= NormalArray[TriangleArray[i].Normal_Index[j]];
	}

	for (i=0;i<VertexCount;i++) N[i].Normalize();

	delete [] NormalArray;
	NormalArray = N;
	NormalCount = VertexCount;

	for (i=0;i<TriangleCount;i++)
		for (j=0;j<3;j++) TriangleArray[i].Normal_Index[j] = TriangleArray[i].Vertex_Index[j];


	m_bIsWalking = false;
	m_Turning = 0;

	MainRoot = new Bone();
	MainRoot->Ref.Set(Point3D(0,0,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));
	MainRoot->Id = 0;

	Bone *B0,*B1,*B2,*B3,*B4,*B5,*B6,*B7;

	B0 = new Bone();
	B0->Id = 128;
	B0->Ref.Set(Point3D(0.0f,0.0f,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));


	B1 = new Bone();
	B1->Id = 1;
	B1->Ref.Set(Point3D(0.0f,0.5f,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));
	B2 = new Bone();
	B2->Id = 2;
	B2->Ref.Set(Point3D(-0.1f,0,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));
	B3 = new Bone();
	B3->Id = 3;
	B3->Ref.Set(Point3D(-0.25f,0.0f,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));
	B4 = new Bone();
	B4->Id = 4;
	B4->Ref.Set(Point3D( 0.1f,0.0f,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));
	B5 = new Bone();
	B5->Id = 5;
	B5->Ref.Set(Point3D( 0.25f,0.0f,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));


	MainRoot->Sons = (Bone**)malloc(sizeof(Bone*));
	MainRoot->Sons[0] = B0;
	MainRoot->SonCount = 1;

	B0->Sons = (Bone**)malloc(sizeof(Bone*));
	B0->Sons[0] = B1;
	B0->SonCount = 1;
		
	B1->Sons = (Bone**)malloc(2*sizeof(Bone*));
	B1->Sons[0] = B2;
	B1->Sons[1] = B4;
	B1->SonCount = 2;

	B2->Sons = (Bone**)malloc(sizeof(Bone*));
	B2->Sons[0] = B3;
	B2->SonCount = 1;
	B4->Sons = (Bone**)malloc(sizeof(Bone*));
	B4->Sons[0] = B5;
	B4->SonCount = 1;

	B6 = new Bone();
	B6->Id = 6;
	B6->Ref.Set(Point3D( -0.35f,0.0f,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));
	B3->Sons = (Bone**)malloc(sizeof(Bone*));
	B3->Sons[0] = B6;
	B3->SonCount = 1;
	B7 = new Bone();
	B7->Id = 7;
	B7->Ref.Set(Point3D( 0.35f,0.0f,0),
						Vector3D(1,0,0),
						Vector3D(0,1,0),
						Vector3D(0,0,1));
	B5->Sons = (Bone**)malloc(sizeof(Bone*));
	B5->Sons[0] = B7;
	B5->SonCount = 1;

	AttachToBone();
}

Robot::~Robot()
{
}


void Robot::Walk(bool bOn)
{
	if (!bOn)
	{
		SetStand();
	}
	m_bIsWalking = bOn;
}

void Robot::TurnLeft(bool bOn)
{
	if (bOn) m_Turning = 1;
	else
		if (m_Turning==1) m_Turning = 0;
}

void Robot::TurnRight(bool bOn)
{
	if (bOn) m_Turning = -1;
	else
		if (m_Turning==-1) m_Turning = 0;
}

void Robot::StartAnimation(unsigned Time)
{
	m_uOldTime = Time;
	SetStand();
	tAnim = 0.0f;
	MainRoot->Ref.O.y = gGround->Elevation(MainRoot->Ref.O.x,MainRoot->Ref.O.z);
}

void Robot::SetStand()
{
	Bone *B;
	Matrix3x4 M;
	Vector3D T;

	M.SetIdentity();
	B = MainRoot->FindBone(1);
	T = B->Ref.O;
	M.PostTranslate(T);
	B->Ref.Set(M);

	
	B = MainRoot->FindBone(2);			// jambe droite
	M.SetRotationZ(0.2*PI);
	T = B->Ref.O;
	M.PostTranslate(T);
	B->Ref.Set(M);

	B = MainRoot->FindBone(3);			// pied droit
	M.SetRotationZ(0.3*PI);
	T = B->Ref.O;
	M.PostTranslate(T);
	B->Ref.Set(M);

	
	B = MainRoot->FindBone(4);			// jambe gauche
	M.SetRotationZ(-0.2*PI);
	T = B->Ref.O;
	M.PostTranslate(T);
	B->Ref.Set(M);

	B = MainRoot->FindBone(5);			// pied gauche
	M.SetRotationZ(-0.3*PI);
	T = B->Ref.O;
	M.PostTranslate(T);
	B->Ref.Set(M);

	M.SetIdentity();
	MainRoot->ComputeMatrix(M);

	UpdateMesh();
}

void Robot::Animate(unsigned Time)
{
	Bone *B;
	Matrix3x4 M;
	Vector3D T;
	float t;
	//float dt = 3.0f*(float)(Time-m_uOldTime)/1000.0f;
	float  dt = 0.05;
		
	if (m_bIsWalking)
	{
		tAnim+=dt;		// boucle de temps pour l'animation : pas gauche, pas droit etc....
		while (tAnim>1.0f) tAnim-=1.0f;

		// rotation du buste
		M.SetIdentity();
		B = MainRoot->FindBone(1);
		float angle = cos(2*PI*tAnim)*0.3;
		M.SetRotationY(angle);
		// inclinaison du buste
		float angle2 = cos(2*PI*tAnim)*0.1;
		M.PostRotateZ(angle2);

		// zig zag haut bas du bassin
		float angle3 = cos(PI*tAnim)*0.2;
		M.PostRotateX(angle3);

		T = B->Ref.O;
		M.PostTranslate(T);
		B->Ref.Set(M);	
		
		// membre droit
		if (tAnim>=0.25f && tAnim<=0.75f) 
		{
			t = 2.0f*(tAnim-0.25f);			// t dans  [0,1]
			t = 0.3f*(fabsf(t-0.5f)*2.0f); // 0.3 * (decroissant de 0.5 à 0 puis croissant de 0 à 0.5)
		}
		else{
			t = 0.3f;	
		} 

		// on bouge le pied droit
		//pied droit
		M.SetIdentity();
		B = MainRoot->FindBone(3);
		M.SetRotationZ(0.3*PI);
		M.PostRotateX(PI*t);
		T = B->Ref.O;
		M.PostTranslate(T);
		B->Ref.Set(M);	
		
		// membre gauche
		if (tAnim<=0.25f || tAnim>=0.75f) 
		{
			t = (tAnim-0.75f);
			while (t<0.0f) t+=1.0f; 	// entre 0 et 1/2
			t*=2.0f;					// t dans  [0,1]
			t = -0.3f*(fabsf(t-0.5f)*2.0f);
		}
		else t = -0.3f;

		//pied gauche
		M.SetIdentity();
		B = MainRoot->FindBone(5);
		M.SetRotationZ(-0.3*PI);
		M.PostRotateX(PI*t);
		T = B->Ref.O;
		M.PostTranslate(T);
		B->Ref.Set(M);	

		MoveFromTo(MainRoot->Ref.O,MainRoot->Ref.O+1.5f*dt*(Point3D)MainRoot->Ref.K);
	}

	switch (m_Turning)
	{
	case 1:
		M = MainRoot->Ref;
		M.PostRotateY(1.0f*dt);
		MainRoot->Ref.Set(M);
		break;
	case -1:
		M = MainRoot->Ref;
		M.PostRotateY(-1.0f*dt);
		MainRoot->Ref.Set(M);
		break;
	}


	UpdateMesh();
	
	m_uOldTime = Time;


}

void Robot::DrawSkeleton()
{
	Matrix3x4 M;
	M.SetIdentity();
	MainRoot->Draw(M);
}

void Robot::Draw()
{
	float AmbDiff[4] = {0.9f,0.7f,0,1};
	float SpecCol[4] = {1,0.9f,0.9f,1};
	int i,j;
	glMaterialfv(GL_FRONT, GL_SPECULAR,SpecCol);
	glMaterialf(GL_FRONT, GL_SHININESS, 10.0f);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,AmbDiff);	
	glBegin(GL_TRIANGLES);
	for (i=0;i<TriangleCount;i++)
		for (j=0;j<3;j++)
	{
		glNormal3fv(&NormalArray[TriangleArray[i].Vertex_Index[j]].x);
		glVertex3fv(&VertexArray[TriangleArray[i].Normal_Index[j]].x);
	}
	glEnd();
}


void Robot::AttachToBone()
{
	int i;
	Bone *B;
	Matrix3x4 M;
	LocalArray = new LocalVert[VertexCount];
	M.SetIdentity();
	MainRoot->ComputeMatrix(M);
	for (i=0;i<VertexCount;i++)
	{
		B = MainRoot->FindBone(AttachArray[i].Bone1);
		M = Inv(B->Matrix);
		LocalArray[i].B1 = B;
		LocalArray[i].Vertex1 = M*VertexArray[i];
		LocalArray[i].Normal1 = M*NormalArray[i];
		LocalArray[i].weight1 = AttachArray[i].Weight1;
		if (AttachArray[i].Bone2!=-1)
		{
			B = MainRoot->FindBone(AttachArray[i].Bone2);
			M = Inv(B->Matrix);
			LocalArray[i].B2 = B;
			LocalArray[i].Vertex2 = M*VertexArray[i];
			LocalArray[i].Normal2 = M*NormalArray[i];
			LocalArray[i].weight2 = AttachArray[i].Weight2;
		}
		else
		{
			LocalArray[i].B2 = NULL;
		}			
	}
}

void Robot::UpdateMesh()
{
	Matrix3x4 M;
	int i;
	M.SetIdentity();
	MainRoot->ComputeMatrix(M);

	for (i=0;i<VertexCount;i++)
	{
		VertexArray[i] = LocalArray[i].weight1*(LocalArray[i].B1->Matrix*LocalArray[i].Vertex1);
		NormalArray[i] = LocalArray[i].weight1*(LocalArray[i].B1->Matrix*LocalArray[i].Normal1);
		if (LocalArray[i].B2)
		{
			VertexArray[i]+=LocalArray[i].weight2*(LocalArray[i].B2->Matrix*LocalArray[i].Vertex2);
			NormalArray[i] += LocalArray[i].weight2*(LocalArray[i].B2->Matrix*LocalArray[i].Normal2);
			NormalArray[i].Normalize();
		}
	}
}

void Robot::MoveFromTo(const Point3D &Origin, const Point3D &Dest)
{
		pCadeau->Collision(Dest);

		if(!pForest->Collision(Dest)){
			MainRoot->Ref.O = Dest;
			MainRoot->Ref.O.y = gGround->Elevation(MainRoot->Ref.O.x,MainRoot->Ref.O.z);
		}

}
