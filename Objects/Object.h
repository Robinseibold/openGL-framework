#ifndef OBJECT_H
#define OBJECT_H

#include <openGL/gl3.h>
#include <vector>

#include "../Shaders/Shader.h"

class Object {
    
public:
    Object() {
        glGenVertexArrays(1, &vertexArrayObject);
        glGenBuffers(1, &vertexBufferObject);
        glGenBuffers(1, &elementBufferObject);
    }
    virtual ~Object() {
        glDeleteVertexArrays(1, &vertexArrayObject);
        glDeleteBuffers(1, &vertexBufferObject);
        glDeleteBuffers(1, &elementBufferObject);
    }
    virtual void draw() = 0;
    
protected:
    GLuint vertexArrayObject;
    GLuint vertexBufferObject;
    GLuint elementBufferObject;
    
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    
};

#endif