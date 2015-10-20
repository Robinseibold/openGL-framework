
#include "Camera.h"

class FirstPersonCamera : public Camera {

public:
    FirstPersonCamera(vec3<GLfloat> position, vec3<GLfloat> target, vec3<GLfloat> up);
    void move();
    
private:
    GLfloat mouseSensitivity;
    GLfloat yaw;
    GLfloat pitch;
    
    void handleKeyboardInputs(GLfloat deltaTime);
    void handleMouseInputs();
    
};
