
#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec2 TexCoord;
layout (location = 3) in vec3 Tangent;
layout (location = 4) in vec3 Binormal;

out vec3 fragmentPosition;
out vec2 texCoord;
out mat3 TBN;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform mat4 InverseTransposeModel;

void main() {
    gl_Position = Projection * View * Model * vec4(Position, 1.0f);
    
    fragmentPosition = vec3(Model * vec4(Position, 1.0f));
    texCoord = TexCoord;
    
    vec3 T = normalize(vec3(InverseTransposeModel * vec4(Tangent, 0.0f)));
    vec3 B = normalize(vec3(InverseTransposeModel * vec4(Binormal, 0.0f)));
    vec3 N = normalize(vec3(InverseTransposeModel * vec4(Normal, 0.0f)));
    TBN = mat3(T, B, N);
}
