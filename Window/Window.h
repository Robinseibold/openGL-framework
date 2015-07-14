
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Window {
    
public:
    Window(int width, int height, const char *title);
    int getWidth();
    int getHeight();
    ~Window();
    
private:
    SDL_Window *window;
    
};