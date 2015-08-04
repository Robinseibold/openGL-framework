
#version 330 core

layout (location = 0) in vec3 Position;

out vec4 ambientColor;

uniform vec4 AmbientColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(Position, 1.0f);
    ambientColor = AmbientColor;
}