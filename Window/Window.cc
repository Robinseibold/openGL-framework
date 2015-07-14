
#include "Window.h"

Window::Window(int width, int height, const char *title) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Could not initilize SDL: " << SDL_GetError() << std::endl;
    }
    
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    if (!window) {
        std::cout << "Could not initilize SDL window: " << SDL_GetError() << std::endl;
    }
    initilizeOpenGL();
    active = true;
}

int Window::getWindowWidth() {
    int width;
    SDL_GetWindowSize(window, &width, NULL);
    return width;
}

int Window::getWindowHeight() {
    int height;
    SDL_GetWindowSize(window, &height, NULL);
    return height;
}

bool Window::isActive() {
    return active;
}

void Window::initiateCloseDown() {
    active = false;
}

void Window::update() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::initilizeOpenGL() {
    context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cout << "Could not initilize OpenGL context: " << SDL_GetError() << std::endl;
    }
    
    glViewport(0, 0, getWindowWidth(), getWindowHeight());
}











