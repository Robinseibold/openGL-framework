
#include "Rectangle.h"

Rectangle::Rectangle(GLfloat sideLengthOne, GLfloat sideLengthTwo, Shader *shaderProgram) {
    shader = shaderProgram;
    GLfloat vertexPositionOne = sideLengthOne / 2;
    GLfloat vertexPositionTwo = sideLengthTwo / 2;
    
    vertices = {
        Vertex( vertexPositionOne, 0.0f,  vertexPositionTwo, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f),
        Vertex( vertexPositionOne, 0.0f, -vertexPositionTwo, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f),
        Vertex(-vertexPositionOne, 0.0f, -vertexPositionTwo, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f),
        Vertex(-vertexPositionOne, 0.0f,  vertexPositionTwo, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f)
    };
    
    indices = {
        0, 1, 3,
        1, 2, 3
    };
    
    Object::bindBuffers();
}