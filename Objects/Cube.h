
#include "Object.h"

class Cube : public Object {
    
public:
    Cube(GLfloat sideLength, Shader *shaderProgram);
    ~Cube();
    void draw();

private:
    Shader *shader;
    
};