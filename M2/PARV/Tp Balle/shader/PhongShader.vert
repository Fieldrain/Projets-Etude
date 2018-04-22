#version 450

uniform mat4 VIEW;
uniform mat4 MODEL;
uniform mat4 PROJECTION;
uniform mat4 transformation;


layout(location = 0) in vec3 vVertex; // le location permet de dire de quel flux/canal on récupère la données												
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec3 vNormal;

out vec3 colorV;
out vec3 fragNormal;
out vec4 fragVert;

void main(){

	colorV = vColor;

	//fragTexCoord = vertexUV;
	fragVert = transformation*vec4(vVertex, 1.0);
	
	fragNormal = vNormal;

	gl_Position = PROJECTION*VIEW*MODEL*fragVert;
}


