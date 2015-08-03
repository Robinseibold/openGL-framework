
#include "Cube.h"

Cube::Cube(GLfloat sideLength, Shader *shaderProgram) {
    shader = shaderProgram;
    GLfloat vertexPosition = sideLength / 2;
    
    vertices = {
        -vertexPosition, -vertexPosition,  vertexPosition,
         vertexPosition, -vertexPosition,  vertexPosition,
         vertexPosition,  vertexPosition,  vertexPosition,
        -vertexPosition,  vertexPosition,  vertexPosition,
        
        -vertexPosition, -vertexPosition, -vertexPosition,
         vertexPosition, -vertexPosition, -vertexPosition,
         vertexPosition,  vertexPosition, -vertexPosition,
        -vertexPosition,  vertexPosition, -vertexPosition
    };
    
    indices = {
        0, 1, 2, 2, 3, 0,
        3, 2, 6, 6, 7, 3,
        7, 6, 5, 5, 4, 7,
        4, 5, 1, 1, 0, 4,
        4, 0, 3, 3, 7, 4,
        1, 5, 6, 6, 2, 1
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

Cube::~Cube() {
    shader = NULL;
}

void Cube::draw() {
    shader->activate();
    glBindVertexArray(vertexArrayObject);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}