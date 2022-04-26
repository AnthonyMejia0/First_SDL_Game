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
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
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

    m_textureManager.load("res/img/animate-alpha.png", "animate", m_pRenderer);

    m_bRunning = true;
    return true;
}

void Game::render() {
    //Clear window
    SDL_RenderClear(m_pRenderer);
    //Draw Textures
    //m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
    //m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    //Display window
    SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
    m_currentFrame = 128 * int(((SDL_GetTicks64() / 100) % 6));
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