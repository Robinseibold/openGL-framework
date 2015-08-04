
#include "Rectangle.h"

Rectangle::Rectangle(GLfloat sideLengthOne, GLfloat sideLengthTwo, Shader *shaderProgram) {
    shader = shaderProgram;
    GLfloat vertexPositionOne = sideLengthOne / 2;
    GLfloat vertexPositionTwo = sideLengthTwo / 2;
    
    vertices = {
         vertexPositionOne, 0.0f,  vertexPositionTwo,
         vertexPositionOne, 0.0f, -vertexPositionTwo,
        -vertexPositionOne, 0.0f, -vertexPositionTwo,
        -vertexPositionOne, 0.0f,  vertexPositionTwo
    };
    
    indices = {
        0, 1, 3,
        1, 2, 3
    };
    
    glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, (vertices.size() * sizeof(GLfloat)), &vertices.front(), GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (indices.size() * sizeof(GLuint)), &indices.front(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Rectangle::~Rectangle() {
    shader = NULL;
}

void Rectangle::draw() {
    shader->activate();
    glBindVertexArray(vertexArrayObject);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
