#version 450

uniform mat4 VIEW;
uniform mat4 MODEL;
uniform mat4 PROJECTION;

layout(location = 0) in vec3 vVertex; // le location permet de dire de quel flux/canal on récupère la données												
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec2 vUv;

out vec3 colorV;
out vec3 fragVert;
out vec2 fragTexCoord;

void main(){

	colorV = vColor;

	fragTexCoord = vUv;
	fragVert = vVertex;

	gl_Position = PROJECTION*VIEW*MODEL*vec4(vVertex, 1.0);
}

