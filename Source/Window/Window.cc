
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
    projectionMatrix.perspectiveProjection((GLfloat)(M_PI / 4), ((GLfloat)this->getWindowWidth() / (GLfloat)this->getWindowHeight()), 0.1f, 100.0f);
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

mat4<GLfloat>* Window::getProjectionMatrix() {
    return &projectionMatrix;
}

void Window::setProjectionMatrix(mat4<GLfloat> newProjectionMatrix) {
    projectionMatrix = newProjectionMatrix;
}

bool Window::isActive() {
    return active;
}

void Window::initiateCloseDown() {
    active = false;
}

void Window::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() {
    SDL_GL_SwapWindow(window);
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::initilizeOpenGL() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cout << "Could not initilize OpenGL context: " << SDL_GetError() << std::endl;
    }
    
    glViewport(0, 0, getWindowWidth(), getWindowHeight());
    glEnable(GL_DEPTH_TEST);
}











