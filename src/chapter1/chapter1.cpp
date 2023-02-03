#include <SFML/Graphics.hpp>

int main() {
    sf::Vector2u windowSize(800, 600);
    sf::VideoMode vm(windowSize);
    sf::RenderWindow window(vm, "Cool bouncing mushroom!");

    sf::Texture mushroomTexture;
    if (!mushroomTexture.loadFromFile("../assets/mushroom.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite mushroom(mushroomTexture);
    sf::Vector2f size {
        static_cast<float>(mushroomTexture.getSize().x),
        static_cast<float>(mushroomTexture.getSize().y)
    };
    mushroom.setOrigin({ size.x / 2.0f, size.y / 2.0f });
    sf::Vector2f increment(0.4f, 0.4f);

    unsigned short alpha {};
    unsigned short alphaIncrement = 1;

    float windowWidth = static_cast<float>(window.getSize().x);
    float windowHeight = static_cast<float>(window.getSize().y);

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if ((mushroom.getPosition().x + (size.x / 2.0f) > windowWidth &&
             increment.x > 0) ||
            (mushroom.getPosition().x - (size.x / 2.0f) < 0 && increment.x < 0)) {
            increment.x = -increment.x;
        }

        if ((mushroom.getPosition().y + (size.y / 2.0f) > windowHeight &&
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

    return EXIT_SUCCESS;
}
