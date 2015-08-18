
#include "Texture.h"

Texture::Texture() {
    glGenTextures(1, &texture);
}

Texture2D::Texture2D(std::string textureName) {
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    SDL_Surface *image = IMG_Load(("Textures/" + textureName + ".png").c_str());
    if (image) {
        width = image->w;
        height = image->h;
    
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, image->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        SDL_FreeSurface(image);
    } else {
        std::cout << "Could not initilize Texture: " << IMG_GetError() << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::activate() {
    glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture2D::unactivate() {
    glBindTexture(GL_TEXTURE_2D, 0);
}