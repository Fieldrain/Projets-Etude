#include "Transform.h"

Transform::Transform(S_ParameterTransform* ParameterTransform, E_TypeTransform Type) : parameterTransform(ParameterTransform), typeTransform(Type)
{
}

Transform::Transform(Transform * transform)
{
	typeTransform = transform->GetType();

	parameterTransform = new S_ParameterTransform(transform->GetParameter()->X,transform->GetParameter()->Y,transform->GetParameter()->Z,transform->GetParameter()->Alpha);
}


Transform::~Transform()
{
	delete parameterTransform;
}

S_ParameterTransform* Transform::GetParameter()
{
	return parameterTransform;
}

E_TypeTransform Transform::GetType()
{
	return typeTransform;
}

void Transform::SetParameter(S_ParameterTransform* ParameterTransform)
{
	parameterTransform = ParameterTransform;
}

vec3 Transform::Apply(vec3 vertex)
{
	vec3 newVertex = vertex;
	float x = newVertex[0];
	float y = newVertex[1];
	float z = newVertex[2];

	switch (typeTransform) {
		case E_Translate:
			newVertex[0]=(newVertex[0] + parameterTransform->X);
			newVertex[1]=(newVertex[1] + parameterTransform->Y);
			newVertex[2]=(newVertex[2] + parameterTransform->Z);
			break;

		case E_Rotate:
			
				if (parameterTransform->X == 1.f) {

					newVertex[1]=((y * cos(parameterTransform->Alpha)) - (z * sin(parameterTransform->Alpha)));
					newVertex[2]=((y * sin(parameterTransform->Alpha)) + (z * cos(parameterTransform->Alpha)));
				}
				if (parameterTransform->Y == 1.f) {

					newVertex[0]=((x * cos(parameterTransform->Alpha)) + (z * sin(parameterTransform->Alpha)));
					newVertex[2]=((x * -sin(parameterTransform->Alpha)) + (z * cos(parameterTransform->Alpha)));
				}
				if (parameterTransform->Z == 1.f) {

					newVertex[0]=((x * cos(parameterTransform->Alpha)) - (y * sin(parameterTransform->Alpha)));
					newVertex[1]=((x * sin(parameterTransform->Alpha)) + (y * cos(parameterTransform->Alpha)));
				}
			
			break;

		case E_Scale:
			newVertex[0]=(newVertex[0] * parameterTransform->X);
			newVertex[1]=(newVertex[1] * parameterTransform->Y);
			newVertex[2]=(newVertex[2] * parameterTransform->Z);
			break;

		default:
			break;
	}
	return newVertex;
}

vec3 Transform::Inverse(vec3 vertex)
{
	vec3 newVertex = vertex;
	float x = newVertex[0];
	float y = newVertex[1];
	float z = newVertex[2];

	switch (typeTransform) {
		case E_Translate:
			newVertex[0]=(newVertex[0] - parameterTransform->X);
			newVertex[1]=(newVertex[1] - parameterTransform->Y);
			newVertex[2]=(newVertex[2] - parameterTransform->Z);
			break;

		case E_Rotate:
			
				if (parameterTransform->X == 1.f) {
					newVertex[1]=((y * cos(-parameterTransform->Alpha)) - (z * sin(-parameterTransform->Alpha)));
					newVertex[2]=((y * sin(-parameterTransform->Alpha)) + (z * cos(-parameterTransform->Alpha)));
				}

				if (parameterTransform->Y == 1.f) {
					newVertex[0]=((x * cos(-parameterTransform->Alpha)) + (z * sin(-parameterTransform->Alpha)));
					newVertex[2]=((x * -sin(-parameterTransform->Alpha)) + (z * cos(-parameterTransform->Alpha)));
				}

				if (parameterTransform->Z == 1.f) {
					newVertex[0]=((x * cos(-parameterTransform->Alpha)) - (y * sin(-parameterTransform->Alpha)));
					newVertex[1]=((x * sin(-parameterTransform->Alpha)) + (y * cos(-parameterTransform->Alpha)));
				}
		
			
			break;

		case E_Scale:
			newVertex[0]=(newVertex[0] * (1/parameterTransform->X));
			newVertex[1]=(newVertex[1] * (1/parameterTransform->Y));
			newVertex[2]=(newVertex[2] * (1/parameterTransform->Z));
			break;

		default:
			break;
	}
	return newVertex;
}

void Transform::Display()
{
	switch (typeTransform) {
		case E_Translate:
				glTranslatef(parameterTransform->X,parameterTransform->Y,parameterTransform->Z);
				//cout << "GlTranslate(" << parameterTransform->X << "," << parameterTransform->Y << "," << parameterTransform->Z << ")" << endl;
			
			break;

		case E_Rotate:
				glRotatef(parameterTransform->Alpha, parameterTransform->X, parameterTransform->Y, parameterTransform->Z);
				//cout << "GlRotate(" << parameterTransform->Alpha << "," << parameterTransform->X << "," << parameterTransform->Y << "," << parameterTransform->Z << ")" << endl;
			break;

		case E_Scale:
			
			glScalef(parameterTransform->X, parameterTransform->Y, parameterTransform->Z);
			break;

		default:
			break;
	}

}


