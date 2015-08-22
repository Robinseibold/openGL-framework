
#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Normal;

out vec3 normal;
out vec3 fragmentPosition;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform mat4 InverseTransposeModel;

void main() {
    gl_Position = Projection * View * Model * vec4(Position, 1.0f);
    fragmentPosition = vec3(Model * vec4(Position, 1.0f));
    normal = mat3(InverseTransposeModel) * Normal;
}