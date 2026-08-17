#include "Button.h"

Button::Button(
    const sf::Font& font,
    const std::string& label,
    sf::Vector2f position,
    sf::Vector2f size
)
    : text(font, label, 18)
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(sf::Color(37, 99, 235));

    text.setFillColor(sf::Color::White);
}

void Button::update(sf::Vector2f mousePosition)
{
    hovered = shape.getGlobalBounds().contains(mousePosition);

    if (hovered)
    {
        shape.setFillColor(sf::Color(29, 78, 216));
    }
    else
    {
        shape.setFillColor(sf::Color(37, 99, 235));
    }
}

void Button::render(sf::RenderWindow& window)
{
    const auto bounds = text.getLocalBounds();
    const auto buttonPosition = shape.getPosition();
    const auto buttonSize = shape.getSize();

    text.setPosition({
        buttonPosition.x +
            (buttonSize.x - bounds.size.x) / 2.f -
            bounds.position.x,

        buttonPosition.y +
            (buttonSize.y - bounds.size.y) / 2.f -
            bounds.position.y
    });

    window.draw(shape);
    window.draw(text);
}

bool Button::isClicked(sf::Vector2f mousePosition) const
{
    return shape.getGlobalBounds().contains(mousePosition);
}