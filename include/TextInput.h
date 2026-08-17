#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextInput {
public:
    TextInput(
        const sf::Font& font,
        sf::Vector2f position,
        sf::Vector2f size
    );

    void handleEvent(const sf::Event& event);
    void update(sf::Vector2f mousePosition);
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape box;

    sf::Text text;
    sf::Text placeholder;

    std::string value;

    bool focused = false;

    void updateTextPosition();
};