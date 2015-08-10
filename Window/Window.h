
#include <SDL2/SDL.h>

#include <string>
#include <iostream>

#include "../Math/Math.h"

class Window {
    
public:
    Window(int width, int height, const char *title);
    int getWindowWidth();
    int getWindowHeight();
    mat4<GLfloat>* getProjectionMatrix();
    void setProjectionMatrix(mat4<GLfloat> newProjectionMatrix);
    bool isActive();
    void initiateCloseDown();
    void clear();
    void update();
    ~Window();
    
private:
    bool active;
    SDL_Window *window;
    SDL_GLContext context;
    
    mat4<GLfloat> projectionMatrix;
    
    void initilizeOpenGL();
    
};