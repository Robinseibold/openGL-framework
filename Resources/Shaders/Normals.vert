
#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Normal;

out vec3 normal;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform mat4 InverseTransposeModel;

uniform bool worldNormal = true;

void main() {
    gl_Position = Projection * View * Model * vec4(Position, 1.0f);
    if (worldNormal) {
        normal = mat3(InverseTransposeModel) * Normal;
    } else {
        normal = Normal;
    }
}