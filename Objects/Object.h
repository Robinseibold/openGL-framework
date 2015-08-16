#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "Node.h"
#include "../Shaders/Shader.h"

class Object : public Node {
    
public:
    ~Object();
    void draw();
    void moveBy(GLfloat x, GLfloat y, GLfloat z);
    
protected:
    GLuint vertexArrayObject;
    GLuint vertexBufferObject;
    GLuint elementBufferObject;
    
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    
    std::shared_ptr<Shader> shader;
    
    Object(std::shared_ptr<Shader> shaderProgram);
    void bindBuffers();
    void setTransformationMatrices(mat4<GLfloat> &model, mat4<GLfloat> *view, mat4<GLfloat> *projection);
    
};

#endif