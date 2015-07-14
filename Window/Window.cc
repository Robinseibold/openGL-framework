
#include "Window.h"

Window::Window(int width, int height, const char *title) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Could not initilize SDL: " << SDL_GetError() << std::endl;
    }
    
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    if(!window) {
        std::cout << "Could not initilize SDL window: " << SDL_GetError() << std::endl;
    }
}

int Window::getWidth() {
    int width;
    SDL_GetWindowSize(window, &width, NULL);
    return width;
}

int Window::getHeight() {
    int height;
    SDL_GetWindowSize(window, &height, NULL);
    return height;
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}


