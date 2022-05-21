#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
    for (auto obj: m_gameObjects)
        obj->update();
}

void MenuState::render() {
    for (auto obj: m_gameObjects)
        obj->draw();
}

bool MenuState::onEnter() {
    if (!TheTextureManager::Instance()->load("res/img/button.png", "playbutton", TheGame::Instance()->getRenderer()))
        return false;
    
    if (!TheTextureManager::Instance()->load("res/img/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
        return false;
    
    GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"));
    GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"));

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Entering MenuState\n";
    return true;
}

bool MenuState::onExit() {
    for (auto obj: m_gameObjects)
        obj->clean();

    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

    std::cout << "Exiting MenuState\n";
    return true;
}