
#include "Cube.h"

Cube::Cube(GLfloat sideLength, std::shared_ptr<Shader> shaderProgram) : Object(shaderProgram) {
    GLfloat vertexPosition = sideLength / 2;
    
    vertices = {
        Vertex(-vertexPosition, -vertexPosition, -vertexPosition,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f),
        Vertex( vertexPosition, -vertexPosition, -vertexPosition,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f),
        Vertex( vertexPosition,  vertexPosition, -vertexPosition,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f),
        Vertex( vertexPosition,  vertexPosition, -vertexPosition,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f),
        Vertex(-vertexPosition,  vertexPosition, -vertexPosition,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f),
        Vertex(-vertexPosition, -vertexPosition, -vertexPosition,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f),
        
        Vertex(-vertexPosition, -vertexPosition,  vertexPosition,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f),
        Vertex( vertexPosition, -vertexPosition,  vertexPosition,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f),
        Vertex( vertexPosition,  vertexPosition,  vertexPosition,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f),
        Vertex( vertexPosition,  vertexPosition,  vertexPosition,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f),
        Vertex(-vertexPosition,  vertexPosition,  vertexPosition,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f),
        Vertex(-vertexPosition, -vertexPosition,  vertexPosition,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f),
        
        Vertex(-vertexPosition,  vertexPosition,  vertexPosition, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
        Vertex(-vertexPosition,  vertexPosition, -vertexPosition, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f),
        Vertex(-vertexPosition, -vertexPosition, -vertexPosition, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
        Vertex(-vertexPosition, -vertexPosition, -vertexPosition, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
        Vertex(-vertexPosition, -vertexPosition,  vertexPosition, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f),
        Vertex(-vertexPosition,  vertexPosition,  vertexPosition, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
        
        Vertex( vertexPosition,  vertexPosition,  vertexPosition,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
        Vertex( vertexPosition,  vertexPosition, -vertexPosition,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f),
        Vertex( vertexPosition, -vertexPosition, -vertexPosition,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
        Vertex( vertexPosition, -vertexPosition, -vertexPosition,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f),
        Vertex( vertexPosition, -vertexPosition,  vertexPosition,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f),
        Vertex( vertexPosition,  vertexPosition,  vertexPosition,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f),
        
        Vertex(-vertexPosition, -vertexPosition, -vertexPosition,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f),
        Vertex( vertexPosition, -vertexPosition, -vertexPosition,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f),
        Vertex( vertexPosition, -vertexPosition,  vertexPosition,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f),
        Vertex( vertexPosition, -vertexPosition,  vertexPosition,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f),
        Vertex(-vertexPosition, -vertexPosition,  vertexPosition,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f),
        Vertex(-vertexPosition, -vertexPosition, -vertexPosition,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f),
        
        Vertex(-vertexPosition,  vertexPosition, -vertexPosition,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f),
        Vertex( vertexPosition,  vertexPosition, -vertexPosition,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f),
        Vertex( vertexPosition,  vertexPosition,  vertexPosition,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f),
        Vertex( vertexPosition,  vertexPosition,  vertexPosition,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f),
        Vertex(-vertexPosition,  vertexPosition,  vertexPosition,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f),
        Vertex(-vertexPosition,  vertexPosition, -vertexPosition,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f)
    };
    
    indices = {
        0,  1,  2,  3,  4,  5,
        6,  7,  8,  9,  10, 11,
        12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23,
        24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35
    };
    
    Object::bindBuffers();
}