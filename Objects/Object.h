#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <stddef.h>

#include "../Shaders/Shader.h"
#include "../Math/Math.h"

class Object {
    
public:
    Object();
    virtual ~Object();
    virtual void draw() = 0;
    
protected:
    GLuint vertexArrayObject;
    GLuint vertexBufferObject;
    GLuint elementBufferObject;
    
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    
    void bindBuffers();
    
};

#endif