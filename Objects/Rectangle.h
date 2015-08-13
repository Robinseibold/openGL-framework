
#include "Object.h"

class Rectangle : public Object {
    
public:
    Rectangle(GLfloat sideLengthOne, GLfloat sideLengthTwo, int sideOneResolution, int sideTwoResolution, Shader *shaderProgram);

};