
#version 330 core

in vec3 texCoord;

out vec4 color;

uniform samplerCube skyBox;

void main() {
    color = texture(skyBox, texCoord);
}
