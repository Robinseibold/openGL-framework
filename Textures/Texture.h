
#include <openGL/gl3.h>
#include <SDL2_image/SDL_image.h>

#include <string>
#include <vector>
#include <iostream>

class Texture {
    
public:
    Texture();
    virtual void activate() = 0;
    virtual void unactivate() = 0;
    
protected:
    GLuint texture;
    
};


class Texture2D : public Texture {
    
public:
    Texture2D(std::string textureName);
    void activate();
    void unactivate();
    
};


class TextureCubeMap : public Texture {
    
public:
    TextureCubeMap(std::string textureName);
    void activate();
    void unactivate();
    
};
