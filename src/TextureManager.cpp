#include "TextureManager.h"
#include <SDL2/SDL_image.h>

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
    //Create texture from file specified
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if (pTempSurface == 0) {
        std::cout << "Error loading file: " << fileName << std::endl;
        return false;
    }
    
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    if (pTexture != 0) {
        //Texture created; Store in map at key id
        m_textureMap[id] = pTexture;
        return true;
    }

    //Something wrong return false*/
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    //Create rectangles for displaying texture
    SDL_Rect srcRect;
    SDL_Rect destRect;

    //Set dimensions of rectangles
    //Top left corner of texture
    srcRect.x = 0;
    srcRect.y = 0;

    //Height & Width of texture
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    //Position of texture in window
    destRect.x = x;
    destRect.y = y;

    //Copy texture to renderer
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    //Create rectangles for displaying texture
    SDL_Rect srcRect;
    SDL_Rect destRect;

    //Set dimensions of rectangles
    //Top left corner of specific texture 
    //based on current frame & row of sheet
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);

    //Height & Width of texture
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    //Position of texture in window
    destRect.x = x;
    destRect.y = y;

    //Copy texture to renderer
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id) {
    m_textureMap.erase(id);
}