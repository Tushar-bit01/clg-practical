#include "Button.h"
#include "Theme.h"

Button::Button(
    const sf::Font& font,
    const std::string& label,
    sf::Vector2f position,
    sf::Vector2f size
)
    : text(
          font,
          label,
          Theme::buttonSize()
      )
{
    shape.setPosition(position);
    shape.setSize(size);

    shape.setFillColor(
        Theme::red()
    );

    shape.setOutlineThickness(3.f);

    shape.setOutlineColor(
        Theme::yellow()
    );

    text.setFillColor(
        Theme::textPrimary()
    );
}

void Button::update(
    sf::Vector2f mousePosition
)
{
    hovered =
        shape.getGlobalBounds()
            .contains(mousePosition);

    if (hovered)
    {
        shape.setFillColor(
            Theme::redLight()
        );

        shape.setOutlineColor(
            Theme::yellowLight()
        );
    }
    else
    {
        shape.setFillColor(
            Theme::red()
        );

        shape.setOutlineColor(
            Theme::yellow()
        );
    }
}

void Button::render(
    sf::RenderWindow& window
)
{
    const auto bounds =
        text.getLocalBounds();

    const auto position =
        shape.getPosition();

    const auto size =
        shape.getSize();

    text.setPosition({
        position.x +
            (size.x - bounds.size.x) / 2.f -
            bounds.position.x,

        position.y +
            (size.y - bounds.size.y) / 2.f -
            bounds.position.y
    });

    window.draw(shape);
    window.draw(text);
}

bool Button::isClicked(
    sf::Vector2f mousePosition
) const
{
    return shape
        .getGlobalBounds()
        .contains(mousePosition);
}