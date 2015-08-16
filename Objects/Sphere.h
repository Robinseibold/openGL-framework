
#include "Object.h"

class Sphere : public Object {
    
public:
    Sphere(GLfloat radius, int thetaResolution, int phiResolution, std::shared_ptr<Shader> shaderProgram);

};
