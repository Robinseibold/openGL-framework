
#include <SDL2/SDL.h>
#include <openGL/gl3.h>

#include "../Math/Math.h"

class Camera {
    
public:
    Camera(vec3<GLfloat> position, vec3<GLfloat> target, vec3<GLfloat> up);
    vec3<GLfloat> getCameraPosition();
    mat4<GLfloat> getViewMatrix();
    void move();
    
private:
    vec3<GLfloat> cameraPosition;
    vec3<GLfloat> cameraFront;
    vec3<GLfloat> cameraUp;
    mat4<GLfloat> viewMatrix;
    
    GLfloat lastFrameTime;
    GLfloat cameraSpeedMultiplier;

    GLfloat mouseSensitivity;
    GLfloat yaw;
    GLfloat pitch;
    
    void handleKeyboardInputs(GLfloat deltaTime);
    void handleMouseInputs();
    
};
