#include "Game.h"
#include <SDL2/SDL_image.h>

Game::Game(): m_pWindow(NULL), m_pRenderer(NULL) {}

Game::~Game() { clean(); }

bool Game::init (const char* title, int w, int h) {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        //Succeeded; Create window
        std::cout << "SDL Initialized\n";
        m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

        if (m_pWindow != 0) {
            //Window created; Render window
            std::cout << "Created Window.\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                //Renderer created
                std::cout << "Created Renderer.\n";
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
            }
            else {
                std::cout << "Failed to create Renderer. Error: " << SDL_GetError << std::endl;
                return false; 
            }
        }
        else {
            std::cout << "Failed to create Window. Error: " << SDL_GetError << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Error initializing SDL. Error: " << SDL_GetError << std::endl;
        return false;
    }

    //Create Texture from bmp file
    SDL_Surface* pTempSurface = IMG_Load("res/img/animate-alpha.png");
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    //Get and set texture dimensions
    //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    //Set coords to top left of window
    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    //Set W & H of destination rectangle
    m_destinationRectangle.w = m_sourceRectangle.w = 128;
    m_destinationRectangle.h = m_sourceRectangle.h = 82;

    m_bRunning = true;
    return true;
}

void Game::render() {
    //Clear window
    SDL_RenderClear(m_pRenderer);
    //Draw Texture
    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_NONE);
    //Display window
    SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
    m_sourceRectangle.x = 128 * int(((SDL_GetTicks64() / 100) % 6));
}

void Game::handleEvents() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;

            default:
                break;
        }
    }
}

void Game::clean() {
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
    std::cout << "SDL Quit Successfully.\n";
}