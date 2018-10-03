#version 450

uniform mat4 VIEW;
uniform mat4 MODEL;
uniform mat4 PROJECTION;

uniform float scaleMin;
uniform float scaleMax;

uniform float angleMin;
uniform float angleMax;

layout(location = 0) in vec3 vVertex; // le location permet de dire de quel flux/canal on récupère la données												
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec3 vNormal;
layout(location = 3) in vec2 vUV;

out vec3 colorV;
out vec3 fragNormal;
out vec3 fragVert;
out vec2 fragTexCoord;

void main(){
    //float scaleMin = 1;
    //float scaleMax = 0.1;

    //float angleMin = 0;
    //float angleMax = 3.14;

    float t = (vVertex.y + 1) /2;
    float angle = (1-t)*angleMin + t*angleMax;
    float s = (1-t)*scaleMin + t*scaleMax;

    fragVert = vVertex;
    fragVert.x = ((vVertex.x * cos(angle))+(vVertex.z*sin(angle)))*s;
    fragVert.y = vVertex.y;
    fragVert.z = ((vVertex.x * - sin(angle))+(vVertex.z*cos(angle)))*s;

	colorV = vColor;
	fragTexCoord = vUV;
	fragNormal = vNormal;

	gl_Position = PROJECTION*VIEW*MODEL*vec4(fragVert, 1.0);
}


