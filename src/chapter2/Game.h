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

    sf::Time getElapsed();
    void restartClock();

private:
    void moveMushroom();

    Window m_window;
    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2f m_increment;

    sf::Clock m_clock;
    sf::Time m_elapsed;

    static constexpr float FRAME_TIME = 1.0f / 60.0f;
};


#endif //SFML_GAME_DEVELOPMENT_GAME_H
