
#include "Camera.h"

Camera::Camera(vec3<GLfloat> position, vec3<GLfloat> front, vec3<GLfloat> up) : cameraPosition(position), cameraFront(front), cameraUp(up) {
    lastFrameTime = GLfloat (SDL_GetTicks());
    cameraSpeedMultiplier = 0.005f;
}

vec3<GLfloat>* Camera::getCameraPosition() {
    return &cameraPosition;
}

mat4<GLfloat>* Camera::getViewMatrix() {
    return &viewMatrix;
}
