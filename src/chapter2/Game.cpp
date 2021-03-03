//
// Created by igor on 3/3/21.
//

#include "Game.h"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600)) {
    m_mushroomTexture.loadFromFile("../assets/mushroom.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_increment = sf::Vector2f(4.0f, 4.0f);
}

Game::~Game() = default;

void Game::update() {
    m_window.update();
    moveMushroom();
}

void Game::moveMushroom() {
    sf::Vector2u windowSize = m_window.getWindowSize();
    sf::Vector2u textureSize = m_mushroomTexture.getSize();

    if ((m_mushroom.getPosition().x >
         static_cast<float>(windowSize.x - textureSize.x) &&
         m_increment.x > 0) ||
        (m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
        m_increment.x = -m_increment.x;
    }

    if ((m_mushroom.getPosition().y >
         static_cast<float>(windowSize.y - textureSize.y) &&
         m_increment.y > 0) ||
        (m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
        m_increment.y = -m_increment.y;
    }

    m_mushroom.setPosition(m_mushroom.getPosition() + m_increment);
}

void Game::render() {
    m_window.beginDraw();
    m_window.draw(m_mushroom);
    m_window.endDraw();
}

void Game::handleInput() {

}

Window *Game::getWindow() {
    return &m_window;
}
