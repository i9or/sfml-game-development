//
// Created by igor on 3/3/21.
//

#ifndef SFML_GAME_DEVELOPMENT_GAME_H
#define SFML_GAME_DEVELOPMENT_GAME_H


#include "Window.h"

class Game {
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
    Window *getWindow();

private:
    void moveMushroom();

    Window m_window;
    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2f m_increment;
};


#endif //SFML_GAME_DEVELOPMENT_GAME_H
