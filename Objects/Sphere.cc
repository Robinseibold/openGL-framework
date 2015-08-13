
#include "Sphere.h"

Sphere::Sphere(GLfloat radius, int thetaResolution, int phiResolution, Shader *shaderProgram) {
    shader = shaderProgram;
    vertices.assign((thetaResolution * phiResolution), Vertex());
    indices.assign((6.0f * (thetaResolution - 1) * (phiResolution - 1)), 0);
    
    GLfloat theta = 0.0f;
    GLfloat deltaTheta = (2.0f * M_PI) / (thetaResolution - 1.0f);
    
    GLfloat phi = 0.0f;
    GLfloat deltaPhi = M_PI / (phiResolution - 1.0f);
    
    int vertexIndex;
    for (int i = 0; i != phiResolution; ++i) {
        GLfloat cosPhi = cos(phi);
        GLfloat sinPhi = sin(phi);
        
        for (int j = 0; j != thetaResolution; ++j) {
            GLfloat cosTheta = cos(theta);
            GLfloat sinTheta = sin(theta);
            vertexIndex = (thetaResolution * i) + j;
            
            vertices[vertexIndex].position.x =  radius * sinTheta * sinPhi;
            vertices[vertexIndex].position.y = -radius * cosPhi;
            vertices[vertexIndex].position.z =  radius * cosTheta * sinPhi;
            
            vertices[vertexIndex].texCoord.x = (GLfloat (j)) / (thetaResolution - 1.0f);
            vertices[vertexIndex].texCoord.y = (GLfloat (i)) / (phiResolution - 1.0f);
            
            vertices[vertexIndex].tangent.x =  radius * cosTheta;
            vertices[vertexIndex].tangent.z = -radius * sinTheta;
            
            vertices[vertexIndex].binormal.x = radius * sinTheta * cosPhi;
            vertices[vertexIndex].binormal.y = radius * sinPhi;
            vertices[vertexIndex].binormal.z = radius * cosTheta * cosPhi;
            
            vertices[vertexIndex].normal = vertices[vertexIndex].tangent.crossProduct(vertices[vertexIndex].binormal);
            
            theta += deltaTheta;
        }
        
        theta = 0.0f;
        phi += deltaPhi;
    }
    
    for (int i = 0; i != (phiResolution - 1); ++i) {
        
        for (int j = 0; j != (thetaResolution - 1); ++j) {
            vertexIndex = (thetaResolution * i) + j;
            int index = 6 * (((thetaResolution - 1) * i) + j);
            
            indices[index    ] = vertexIndex;
            indices[index + 1] = vertexIndex + 1;
            indices[index + 2] = vertexIndex + thetaResolution;
            indices[index + 3] = vertexIndex + 1;
            indices[index + 4] = vertexIndex + 1 + thetaResolution;
            indices[index + 5] = vertexIndex + thetaResolution;
        }
    }
    
    Object::bindBuffers();
}
