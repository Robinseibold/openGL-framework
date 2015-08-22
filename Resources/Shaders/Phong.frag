
#version 330 core

in vec3 normal;
in vec3 fragmentPosition;

out vec4 color;

uniform vec3 objectColor;

uniform vec3 lightColor;
uniform vec3 lightPosition;

uniform vec3 viewPosition;

uniform float ambientStrength = 0.1f;
uniform float specularStrength = 0.5f;
uniform float shininess = 32.0f;

void main() {
    vec3 norm = normalize(normal);
    vec3 lightDirection = normalize(lightPosition - fragmentPosition);
    vec3 viewDirection = normalize(viewPosition - fragmentPosition);
    vec3 reflectDirection = reflect(-lightDirection, norm);
    
    vec3 ambient = ambientStrength * lightColor;
    vec3 diffuse = max(dot(norm, lightDirection), 0.0f) * lightColor;
    vec3 specular = pow(max(dot(viewDirection, reflectDirection), 0.0f), shininess) * specularStrength * lightColor;
    
    color = vec4(((ambient + diffuse + specular) * objectColor), 1.0f);
}