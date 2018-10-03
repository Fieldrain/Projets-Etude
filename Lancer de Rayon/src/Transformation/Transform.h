#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include "../include/glm/glm.hpp"

using namespace glm;
using namespace std;

enum E_TypeTransform {E_Translate,E_Rotate,E_Scale,E_Union,E_Inter,E_Minus};

struct S_ParameterTransform{
	float X;
	float Y;
	float Z;

	float Alpha;
	bool Dim3;

	S_ParameterTransform(float x=0.f, float y=0.f, float z=0.f, float alpha=0.f) : X(x),Y(y),Z(z),Alpha(alpha)
	{}
};

class Transform
{
protected:
	E_TypeTransform typeTransform;
	S_ParameterTransform* parameterTransform;


public:
	vec3 Apply(vec3 vertex);
	vec3 Inverse(vec3 vertex);

	void Display();

	void SetParameter(S_ParameterTransform* ParameterTransform);
	S_ParameterTransform* GetParameter();

	E_TypeTransform GetType();

	Transform(S_ParameterTransform* ParameterTransform, E_TypeTransform Type);
	Transform(Transform* transform);
	~Transform();
};

