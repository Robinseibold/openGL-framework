
#include "Object.h"

class Rectangle : public Object {
    
public:
    Rectangle(GLfloat sideLengthOne, GLfloat sideLengthTwo, Shader *shaderProgram);
    ~Rectangle();
    void draw();
    
private:
    Shader *shader;
    
};