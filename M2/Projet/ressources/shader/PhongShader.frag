#version 450

uniform mat4 MODEL;
uniform vec3 cameraPosition;

uniform double pas;

//textures
uniform sampler2D INDICEUV;
uniform sampler1D TANGENTES1;
uniform sampler1D TANGENTES2;

// material settings
uniform float materialShininess;
uniform vec3 materialSpecularColor;

uniform struct Light {
   vec3 position;
   vec3 intensities; //a.k.a the color of the light
   float attenuation;
   float ambientCoefficient;
} light;

in vec3 colorV;
in vec3 fragVert;
in vec2 fragTexCoord;

out vec4 finalColor;

void main() {

    // calcul des coordonnées dans la texture
    vec2 coord = vec2(round(fragTexCoord.x/(1.0*pas)),round(fragTexCoord.y/(1.0*pas)));
    // recupere l'indice de la tangente
    vec4 indice = texture(INDICEUV,coord);

    vec3 tang1 = vec3(texture(TANGENTES1, indice.x).xyz);
    vec3 tang2 = vec3(texture(TANGENTES2, indice.x).xyz);
    vec3 fragNormal = cross(tang1,tang2);

    vec3 normal = normalize(transpose(inverse(mat3(MODEL))) * fragNormal);
    vec3 surfacePos = vec3(MODEL * vec4(fragVert, 0));
    vec4 surfaceColor = vec4(colorV,1);
    vec3 surfaceToLight = normalize(light.position - surfacePos);
    vec3 surfaceToCamera = normalize(cameraPosition - surfacePos);
    
    //ambient
    vec3 ambient = light.ambientCoefficient * surfaceColor.rgb * light.intensities;

    //diffuse
    float diffuseCoefficient = max(0.0, dot(normal, surfaceToLight));
    vec3 diffuse = diffuseCoefficient * surfaceColor.rgb * light.intensities;
    
    //specular
    float specularCoefficient = 0.0;
    if(diffuseCoefficient > 0.0)
        specularCoefficient = pow(max(0.0, dot(surfaceToCamera, reflect(-surfaceToLight, normal))), materialShininess);
    vec3 specular = specularCoefficient * materialSpecularColor * light.intensities;
    
    //attenuation
    float distanceToLight = length(light.position - surfacePos);
    float attenuation = 1.0 / (1.0 + light.attenuation * pow(distanceToLight, 2));

    //linear color (color before gamma correction)
    vec3 linearColor = ambient + attenuation*(diffuse + specular);
    
    //final color (after gamma correction)
    vec3 gamma = vec3(1.0/2.2);
    //finalColor = vec4(pow(linearColor, gamma), surfaceColor.a);
    finalColor = vec4(fragTexCoord,0,0);
}