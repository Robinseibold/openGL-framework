
#include "Object.h"

class Sphere : public Object {
    
public:
    Sphere(GLfloat radius, int thetaResolution, int phiResolution, Shader *shaderProgram);

};
