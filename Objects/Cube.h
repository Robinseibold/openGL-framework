
#include "Object.h"

class Cube : public Object {
    
public:
    Cube(GLfloat sideLength, std::shared_ptr<Shader> shaderProgram);
  
};