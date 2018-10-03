#version 330

in vec4 vVertexColor;
in vec4 vNormalPoint;

layout(location = 0) out vec4 vFragColor;

void main(void)
{
	vFragColor = vVertexColor+vNormalPoint;
}