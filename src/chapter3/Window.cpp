//
// Created by igor on 3/3/21.
//

#include "Window.h"

Window::Window() {
    setup("Window", sf::Vector2u(1280, 800));
}

Window::Window(const std::string& t_title, const sf::Vector2u& t_size) {
    setup(t_title, t_size);
}

Window::~Window() {
    destroy();
}

void Window::setup(const std::string& t_title, const sf::Vector2u& t_size) {
    m_windowTitle = t_title;
    m_windowSize = t_size;
    m_isFullscreen = false;
    m_isDone = false;
    create();
}

void Window::create() {
    auto style = m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Close;
    sf::VideoMode videoMode { m_windowSize };
    m_window.create(videoMode, m_windowTitle, style);
}

void Window::destroy() {
    m_window.close();
}

void Window::update() {
    sf::Event event {};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_isDone = true;
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::F5:
                    toggleFullscreen();
                    break;
                case sf::Keyboard::Escape:
                    m_isDone = true;
                    break;
                default:
                    break;
            }
        }
    }
}

void Window::toggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    destroy();
    create();
}

void Window::beginDraw() {
    m_window.clear(sf::Color::Black);
}

void Window::endDraw() {
    m_window.display();
}

bool Window::isDone() const {
    return m_isDone;
}

bool Window::isFullScreen() const {
    return m_isFullscreen;
}

sf::Vector2u Window::getWindowSize() {
    return m_isFullscreen ? m_window.getSize() : m_windowSize;
}

void Window::draw(sf::Drawable& t_drawable) {
    m_window.draw(t_drawable);
}
