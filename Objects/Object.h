#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "../Shaders/Shader.h"
#include "../Math/Math.h"

class Object {
    
public:
    Object();
    ~Object();
    void draw();
    
protected:
    GLuint vertexArrayObject;
    GLuint vertexBufferObject;
    GLuint elementBufferObject;
    
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    
    Shader *shader;
    
    void bindBuffers();
    
};

#endif