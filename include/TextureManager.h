#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <map>

class TextureManager {
public:

    static TextureManager* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }

        return s_pInstance;
    }

    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void clearFromTextureMap(std::string id);

private:
    TextureManager() {}
    static TextureManager* s_pInstance;
    std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif