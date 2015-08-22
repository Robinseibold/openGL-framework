
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
    
    int width;
    int height;
    SDL_Surface *image = IMG_Load(("Resources/Textures/" + textureName + ".png").c_str());
    if (image) {
        width = image->w;
        height = image->h;
    
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, image->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        SDL_FreeSurface(image);
    } else {
        std::cout << "Could not initilize 'Textures/" + textureName + ".png': " << IMG_GetError() << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::activate() {
    glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture2D::unactivate() {
    glBindTexture(GL_TEXTURE_2D, 0);
}


TextureCubeMap::TextureCubeMap(std::string textureName) {
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    
    std::vector<std::string> sides = { "Right", "Left", "Top", "Bottom", "Back", "Front" };
    SDL_Surface *image;
    int width;
    int height;
    
    for (int i = 0; i != sides.size(); ++i) {
        image = IMG_Load(("Resources/Textures/" + textureName + "/" + sides[i] + ".png").c_str());
        if (image) {
            width = image->w;
            height = image->h;
            
            glTexImage2D((GL_TEXTURE_CUBE_MAP_POSITIVE_X + i), 0, GL_RGBA8, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, image->pixels);
        } else {
            std::cout << "Could not initilize 'Textures/" + textureName + "/" + sides[i] + ".png': " << IMG_GetError() << std::endl;
        }
    }
    
}

void TextureCubeMap::activate() {
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
}

void TextureCubeMap::unactivate() {
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
