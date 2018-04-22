#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "Bone.h"
#include "Mesh.h"

class Attach
{
public:
	void Set(int B1, int B2, float w1, float w2)
	{
		Bone1 = B1;
		Bone2 = B2;
		Weight1 = w1;
		Weight2 = w2;
	}
public:
	int Bone1,Bone2;
	float Weight1,Weight2;
};

class LocalVert
{
public:
	Point3D Vertex1,Vertex2;
	Vector3D Normal1,Normal2;
	Bone *B1,*B2;
	float weight1,weight2;
};


class Robot : public Mesh
{
public:
	Robot();
	~Robot();
	void AttachToBone();
	void Walk(bool bOn);
	void TurnLeft(bool bOn);
	void TurnRight(bool bOn);
	void StartAnimation(unsigned Time);
	void Animate(unsigned Time);
	void UpdateMesh();

	void DrawSkeleton();
	void Draw();

	void MoveFromTo(const Point3D &Origin, const Point3D &Destination);


	const Reference3D& GetRef() {return MainRoot->Ref;}
private:
	void SetStand();
private:
	bool m_bIsWalking;
	int m_Turning;
	unsigned m_uOldTime;
	Bone *MainRoot;
	float tAnim;
	Attach *AttachArray;
	LocalVert *LocalArray;
};

#endif
