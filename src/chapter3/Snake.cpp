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

int Snake::getLives() {
    return m_lives;
}

int Snake::getScore() {
    return m_score;
}

void Snake::increaseScore() {
    m_score += 10;
}

bool Snake::hasLost() {
    return m_lost;
}

void Snake::lose() {
    m_lost = true;
}

void Snake::toggleLost() {
    m_lost = !m_lost;
}

void Snake::extend() {
    if (m_snakeBody.empty()) {
        return;
    }

    SnakeSegment& tail_head = m_snakeBody[m_snakeBody.size() - 1];

    if (m_snakeBody.size() > 1) {
        SnakeSegment& tail_bone = m_snakeBody[m_snakeBody.size() - 2];
        if (tail_head.position.x == tail_bone.position.x) {
            if (tail_head.position.y > tail_bone.position.y) {
                m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
            }
        }
    } else {
    }
}

void Snake::move() {
}

void Snake::tick() {
}

void Snake::cut(int t_segments) {
}

void Snake::render(sf::RenderWindow& t_window) {
}

void Snake::checkCollision() {
}
