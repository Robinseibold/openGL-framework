
#include <openGL/gl3.h>
#include <SDL2_image/SDL_image.h>

#include <string>
#include <iostream>

class Texture {
    
public:
    Texture();
    virtual void activate() = 0;
    virtual void unactivate() = 0;
    
protected:
    GLuint texture;
    int width, height;
    
};


class Texture2D : public Texture {
    
public:
    Texture2D(std::string textureName);
    void activate();
    void unactivate();
    
};


