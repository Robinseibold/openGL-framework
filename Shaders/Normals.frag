
#version 330 core

in vec3 normal;

out vec4 color;

void main() {
    vec3 norm = normalize(normal);
    color = vec4(((norm * 0.5f) + 0.5f), 1.0f);
}
