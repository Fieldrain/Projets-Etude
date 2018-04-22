#version 330
uniform mat4 VIEW,MODEL,PROJECTION;
uniform mat4 transformation;

layout(location = 0) in vec3 vVertex;
layout(location = 1) in vec3 vColor;

out vec4 vVertexColor;

void main()
{
	vVertexColor = vec4(vColor,1);

	gl_Position = PROJECTION * VIEW * MODEL * (transformation*vec4(vVertex, 1.0));
}