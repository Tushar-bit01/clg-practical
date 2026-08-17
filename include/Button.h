#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
    Button(
        const sf::Font& font,
        const std::string& label,
        sf::Vector2f position,
        sf::Vector2f size
    );

    void update(
        sf::Vector2f mousePosition
    );

    void render(
        sf::RenderWindow& window
    );

    bool isClicked(
        sf::Vector2f mousePosition
    ) const;

private:
    sf::RectangleShape shape;
    sf::Text text;

    bool hovered = false;
};