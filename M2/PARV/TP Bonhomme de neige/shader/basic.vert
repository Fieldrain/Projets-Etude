#version 330
uniform mat4 VIEW,MODEL,PROJECTION;
uniform mat4 transformation;
uniform bool selected;

layout(location = 0) in vec3 vVertex;
layout(location = 1) in vec3 vColor;

out vec4 vVertexColor;

void main()
{
	if(selected)
		vVertexColor = vec4(1.0,0.0,0.0,1.0);
	else	
		vVertexColor = vec4(vColor,1);

	gl_Position = PROJECTION * VIEW * MODEL * (transformation*vec4(vVertex, 1.0));
}