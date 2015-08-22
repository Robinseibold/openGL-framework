#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "Node.h"
#include "../Shader/Shader.h"
#include "../Texture/Texture.h"

class Object : public Node {
    
public:
    ~Object();
    void draw();
    void moveBy(GLfloat x, GLfloat y, GLfloat z);
    void addTexture(std::shared_ptr<Texture> texture, std::string uniformName);
    
protected:
    GLuint vertexArrayObject;
    GLuint vertexBufferObject;
    GLuint elementBufferObject;
    
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
    
    std::shared_ptr<Shader> shader;
    
    Object(std::shared_ptr<Shader> shaderProgram);
    void bindBuffers();
    void setTransformationMatrices(mat4<GLfloat> &model, mat4<GLfloat> *view, mat4<GLfloat> *projection);
    
};

#endif