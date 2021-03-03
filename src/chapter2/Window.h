//
// Created by igor on 3/3/21.
//

#ifndef SFML_GAME_DEVELOPMENT_WINDOW_H
#define SFML_GAME_DEVELOPMENT_WINDOW_H


#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window();

    Window(const std::string &t_title, const sf::Vector2u &t_size);
    ~Window();

    void beginDraw();
    void endDraw();

    void update();

    bool isDone() const;
    bool isFullScreen();
    sf::Vector2u getWindowSize();

    void toggleFullscreen();

    void draw(sf::Drawable &t_drawable);

private:
    void setup(const std::string &t_title, const sf::Vector2u &t_size);
    void destroy();
    void create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone{};
    bool m_isFullscreen{};
};


#endif //SFML_GAME_DEVELOPMENT_WINDOW_H
