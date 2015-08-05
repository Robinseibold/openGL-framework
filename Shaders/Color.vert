
#version 330 core

layout (location = 0) in vec3 Position;

out vec3 objectColor;

uniform vec3 ObjectColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(Position, 1.0f);
    objectColor = ObjectColor;
}