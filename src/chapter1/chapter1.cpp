#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing mushroom!");

    sf::Texture mushroomTexture;
    mushroomTexture.loadFromFile("../assets/mushroom.png");
    sf::Sprite mushroom(mushroomTexture);
    sf::Vector2u size = mushroomTexture.getSize();
    mushroom.setOrigin(size.x / 2.0f, size.y / 2.0f);
    sf::Vector2f increment(0.4f, 0.4f);

    unsigned short alpha {};
    unsigned short alphaIncrement = 1;

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if ((mushroom.getPosition().x + (size.x / 2.0f) > window.getSize().x &&
             increment.x > 0) ||
            (mushroom.getPosition().x - (size.x / 2.0f) < 0 && increment.x < 0)) {
            increment.x = -increment.x;
        }

        if ((mushroom.getPosition().y + (size.y / 2.0f) > window.getSize().y &&
             increment.y > 0) ||
            (mushroom.getPosition().y - (size.y / 2.0f) < 0 && increment.y < 0)) {
            increment.y = -increment.y;
        }

        alpha += alphaIncrement;

        if (alpha < 0 || alpha > 255) {
            alphaIncrement = -alphaIncrement;
        }

        mushroom.setPosition(mushroom.getPosition() + increment);
        mushroom.setColor(sf::Color(255, 255, 255, alpha));

        window.clear(sf::Color::Black);

        window.draw(mushroom);

        window.display();
    }

    return 0;
}
