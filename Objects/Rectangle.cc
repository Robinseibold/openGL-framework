
#include "Rectangle.h"

Rectangle::Rectangle(GLfloat sideLengthOne, GLfloat sideLengthTwo, int sideOneResolution, int sideTwoResolution, Shader *shaderProgram) {
    shader = shaderProgram;
    vertices.assign((sideOneResolution * sideTwoResolution), Vertex());
    indices.assign((6 * (sideOneResolution - 1) * (sideTwoResolution - 1)), 0);
    
    GLfloat sideOnePosition = -(sideLengthOne / 2);
    GLfloat sideOneDelta = sideLengthOne / sideOneResolution;
    
    GLfloat sideTwoPosition = -(sideLengthTwo / 2);
    GLfloat sideTwoDelta = sideLengthTwo / sideTwoResolution;
    
    int vertexIndex;
    for (int i = 0; i != sideOneResolution; ++i) {
        
        for (int j = 0; j != sideTwoResolution; ++j) {
            vertexIndex = (sideTwoResolution * i) + j;
            
            vertices[vertexIndex].position.x = sideOnePosition;
            vertices[vertexIndex].position.z = sideTwoPosition;
            
            vertices[vertexIndex].normal = vec3<GLfloat>(0.0f, 1.0f, 0.0f);
            
            vertices[vertexIndex].texCoord.x = (GLfloat (i)) / (sideOneResolution - 1);
            vertices[vertexIndex].texCoord.y = (GLfloat (j)) / (sideTwoResolution - 1);
            
            vertices[vertexIndex].tangent = vec3<GLfloat>(1.0f, 0.0f, 0.0f);
            vertices[vertexIndex].binormal = vec3<GLfloat>(0.0f, 0.0f, 1.0f);
            
            sideTwoPosition += sideTwoDelta;
        }
        
        sideTwoPosition = -(sideLengthTwo / 2);
        sideOnePosition += sideOneDelta;
    }

    for (int i = 0; i != (sideOneResolution - 1); ++i) {
        
        for (int j = 0; j != (sideTwoResolution - 1); ++j) {
            vertexIndex = (sideTwoResolution * i) + j;
            int index = 6 * (((sideTwoResolution - 1) * i) + j);
            
            indices[index    ] = vertexIndex;
            indices[index + 1] = vertexIndex + 1;
            indices[index + 2] = vertexIndex + sideTwoResolution;
            indices[index + 3] = vertexIndex + 1;
            indices[index + 4] = vertexIndex + 1 + sideTwoResolution;
            indices[index + 5] = vertexIndex + sideTwoResolution;
        }
        
    }
    Object::bindBuffers();
}