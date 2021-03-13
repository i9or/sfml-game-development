//
// Created by igor on 3/13/21.
//

#ifndef SFML_GAME_DEVELOPMENT_SNAKE_H
#define SFML_GAME_DEVELOPMENT_SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

struct SnakeSegment {
    SnakeSegment(int x, int y) : position(x, y) {}

    sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction {
    None, Up, Down, Left, Right
};

class Snake {
public:
    explicit Snake(int t_blockSize);
    ~Snake();

    void setDirection(Direction t_dir);
    Direction getDirection();
    int getSpeed();
    sf::Vector2i getPosition();
    int getLives();
    int getScore();
    void increaseScore();
    bool hasLost();

    void lose();
    void toggleLost();

    void extend();
    void reset();

    void move();
    void tick();
    void cut(int t_segments);
    void render(sf::RenderWindow &t_window);

private:
    void checkCollision();

    SnakeContainer m_snakeBody;
    int m_size;
    Direction m_dir;
    int m_speed{};
    int m_lives{};
    int m_score{};
    bool m_lost{};
    sf::RectangleShape m_bodyRect;
};


#endif //SFML_GAME_DEVELOPMENT_SNAKE_H
