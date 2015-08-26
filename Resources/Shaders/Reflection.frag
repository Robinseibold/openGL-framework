
#version 330 core

in vec3 fragmentPosition;
in vec3 normal;

out vec4 color;

uniform samplerCube skyBox;

uniform vec3 viewPosition;

void main() {
    vec3 inverseViewDirection = normalize(fragmentPosition - viewPosition);
    vec3 reflectDirection = reflect(inverseViewDirection, normalize(normal));
    
    color = texture(skyBox, reflectDirection);
}