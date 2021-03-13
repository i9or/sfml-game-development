//
// Created by igor on 3/13/21.
//

#include "Snake.h"

Snake::Snake(int t_blockSize) {
    m_size = t_blockSize;
    m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
    reset();
}

Snake::~Snake() = default;

void Snake::reset() {
    m_snakeBody.clear();

    m_snakeBody.push_back(SnakeSegment(5, 7));
    m_snakeBody.push_back(SnakeSegment(5, 6));
    m_snakeBody.push_back(SnakeSegment(5, 5));

    setDirection(Direction::None);
    m_speed = 15;
    m_lives = 3;
    m_score = 0;
    m_lost = false;
}

void Snake::setDirection(Direction t_dir) {
    m_dir = t_dir;
}

Direction Snake::getDirection() {
    return m_dir;
}

int Snake::getSpeed() {
    return m_speed;
}

sf::Vector2i Snake::getPosition() {
    return (!m_snakeBody.empty()
            ? m_snakeBody.front().position
            : sf::Vector2i(1, 1));
}


