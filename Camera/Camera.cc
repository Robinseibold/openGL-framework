
#include "Camera.h"

Camera::Camera(vec3<GLfloat> position, vec3<GLfloat> front, vec3<GLfloat> up) {
    cameraPosition = position;
    cameraFront = front;
    cameraUp = up;
    
    lastFrameTime = GLfloat (SDL_GetTicks());
    cameraSpeedMultiplier = 0.005f;
    
    if (SDL_SetRelativeMouseMode(SDL_TRUE) != 0) {
        std::cout << "Relative mouse mode error:" << SDL_GetError() << std::endl;
    }
    SDL_GetRelativeMouseState(NULL, NULL);
    mouseSensitivity = 0.2f;
    yaw = 0.0f;
    pitch = 0.0f;
}

mat4<GLfloat> Camera::getViewMatrix() {
    return viewMatrix.lookAt(cameraUp, (cameraPosition + cameraFront), cameraPosition);
}

void Camera::move() {
    GLfloat currentFrameTime = GLfloat (SDL_GetTicks());
    GLfloat deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;
    handleKeyboardInputs(deltaTime);
    handleMouseInputs();
}

void Camera::handleKeyboardInputs(GLfloat deltaTime) {
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
    GLfloat cameraSpeed = cameraSpeedMultiplier * deltaTime;
    if (currentKeyStates[SDL_SCANCODE_W])
        cameraPosition += cameraSpeed * cameraFront;
    if (currentKeyStates[SDL_SCANCODE_A])
        cameraPosition -= cameraSpeed * cameraFront.crossProduct(cameraUp).normalize();
    if (currentKeyStates[SDL_SCANCODE_S])
        cameraPosition -= cameraSpeed * cameraFront;
    if (currentKeyStates[SDL_SCANCODE_D])
        cameraPosition += cameraSpeed * cameraFront.crossProduct(cameraUp).normalize();
}

void Camera::handleMouseInputs() {
    int newMousePositionX;
    int newMousePositionY;
    SDL_GetRelativeMouseState(&newMousePositionX, &newMousePositionY);
    
    yaw += (mouseSensitivity * newMousePositionX);
    pitch += (mouseSensitivity * -newMousePositionY);
    
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;
    
    GLfloat yawRadians = yaw * (M_PI / 180);
    GLfloat pitchRadians = pitch * (M_PI / 180);
    cameraFront = (vec3<GLfloat>((cos(yawRadians) * cos(pitchRadians)), (sin(pitchRadians)), (sin(yawRadians) * cos(pitchRadians)))).normalize();
}




























