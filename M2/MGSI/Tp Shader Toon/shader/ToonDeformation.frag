#version 450

uniform mat4 MODEL;
uniform vec3 cameraPosition;

// material settings
uniform sampler2D TextureSampler;
uniform float materialShininess;
uniform vec3 materialSpecularColor;

uniform struct Light {
   vec3 position;
   vec3 intensities; //a.k.a the color of the light
   float attenuation;
   float ambientCoefficient;
} light;

in vec3 colorV;
in vec3 fragNormal;
in vec3 fragVert;
in vec2 fragTexCoord;

out vec4 finalColor;

void main() {

    vec3 normal = normalize(transpose(inverse(mat3(MODEL))) * fragNormal);
    vec3 surfacePos = vec3(MODEL * vec4(fragVert, 0));
    vec4 surfaceColor = vec4(colorV,1);
    //vec4 surfaceColor = texture(TextureSampler, fragTexCoord);
    vec3 surfaceToLight = normalize(light.position - surfacePos);
    vec3 surfaceToCamera = normalize(cameraPosition - surfacePos);
    
    //ambient
    vec3 ambient = light.ambientCoefficient * surfaceColor.rgb * light.intensities;

    //diffuse

    float B = 4;
    float diffuseCoefficient = max(0.0, dot(normal, surfaceToLight));
    float i = floor(diffuseCoefficient*B);
    float newDiffuseCoefficient = (i/B + (i+1)/B);

    vec3 diffuse = newDiffuseCoefficient * surfaceColor.rgb * light.intensities;
    
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
    finalColor = vec4(pow(linearColor, gamma), surfaceColor.a);
}