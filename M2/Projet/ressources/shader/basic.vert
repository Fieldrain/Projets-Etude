#version 330

uniform mat4 VIEW,MODEL,PROJECTION;

layout(location = 0) in vec3 vVertex;
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec3 vNormal;

out vec4 vVertexColor;
out vec4 vNormalPoint;

void main()
{
	vVertexColor = vec4(vColor,1);
	vNormalPoint = vec4(vNormal,1);
	gl_Position = PROJECTION * VIEW * MODEL * vec4(vVertex,1);
}