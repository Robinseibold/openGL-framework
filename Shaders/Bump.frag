
#version 330 core

in vec3 fragmentPosition;
in vec2 texCoord;
in mat3 TBN;

out vec4 color;

uniform sampler2D textureImage;
uniform sampler2D normalMap;

uniform vec3 lightColor;
uniform vec3 lightPosition;

uniform vec3 viewPosition;

uniform float ambientStrength = 0.1f;
uniform float specularStrength = 0.5f;
uniform float shininess = 32.0f;

void main() {
    vec3 normal = normalize(vec3((texture(normalMap, texCoord) * 2.0f) - 1.0f));
    vec3 norm = normalize(TBN * normal);
    vec3 lightDirection = normalize(lightPosition - fragmentPosition);
    vec3 viewDirection = normalize(viewPosition - fragmentPosition);
    vec3 reflectDirection = reflect(-lightDirection, norm);
    
    vec3 ambient = ambientStrength * lightColor;
    vec3 diffuse = max(dot(norm, lightDirection), 0.0f) * lightColor;
    vec3 specular = pow(max(dot(viewDirection, reflectDirection), 0.0f), shininess) * specularStrength * lightColor;
    
    vec4 lightStrength = vec4((ambient + diffuse + specular), 1.0f);
    vec4 objectColor = texture(textureImage, texCoord);
    
    color = lightStrength * objectColor;
}
