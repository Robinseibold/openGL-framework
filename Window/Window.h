
#include <SDL2/SDL.h>
#include <openGL/gl3.h>

#include <string>
#include <iostream>

class Window {
    
public:
    Window(int width, int height, const char *title);
    int getWindowWidth();
    int getWindowHeight();
    bool isActive();
    void initiateCloseDown();
    void clear();
    void update();
    ~Window();
    
private:
    bool active;
    SDL_Window *window;
    SDL_GLContext context;
    
    void initilizeOpenGL();
    
};