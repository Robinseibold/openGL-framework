
#include "Object.h"

Object::Object(std::shared_ptr<Shader> shaderProgram) : shader(shaderProgram) {
    glGenVertexArrays(1, &vertexArrayObject);
    glGenBuffers(1, &vertexBufferObject);
    glGenBuffers(1, &elementBufferObject);
}

Object::~Object() {
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteBuffers(1, &vertexBufferObject);
    glDeleteBuffers(1, &elementBufferObject);
    shader = NULL;
}

void Object::draw() {
    shader->activate();
    if (viewMatrix) {
        shader->setPropertyMatrix("View", viewMatrix->array());
    }
    glBindVertexArray(vertexArrayObject);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    Node::draw();
}

void Object::moveBy(GLfloat x, GLfloat y, GLfloat z) {
    Node::moveBy(x, y, z);
    shader->setModelMatrix(modelMatrix);
}

void Object::setTransformationMatrices(mat4<GLfloat> &model, mat4<GLfloat> *view, mat4<GLfloat> *projection) {
    Node::setTransformationMatrices(model, view, projection);
    shader->setTransformationMatrices(modelMatrix, viewMatrix, projectionMatrix);
}

void Object::bindBuffers() {
    glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) 0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, normal));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, texCoord));
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, tangent));
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) offsetof(Vertex, binormal));
    glBindVertexArray(0);
}