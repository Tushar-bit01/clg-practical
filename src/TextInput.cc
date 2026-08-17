#include "TextInput.h"

TextInput::TextInput(
    const sf::Font& font,
    sf::Vector2f position,
    sf::Vector2f size
)
    : text(font, "", 17),
      placeholder(font, "Write your feedback here...", 17)
{
    box.setPosition(position);
    box.setSize(size);

    box.setFillColor(sf::Color(248, 250, 252));
    box.setOutlineThickness(1.f);
    box.setOutlineColor(sf::Color(226, 232, 240));

    text.setFillColor(sf::Color(30, 41, 59));

    placeholder.setFillColor(sf::Color(148, 163, 184));
    placeholder.setPosition({
        position.x + 15.f,
        position.y + 12.f
    });
}

void TextInput::update(sf::Vector2f mousePosition)
{
    if (box.getGlobalBounds().contains(mousePosition))
    {
        box.setOutlineColor(sf::Color(37, 99, 235));
    }
    else if (!focused)
    {
        box.setOutlineColor(sf::Color(226, 232, 240));
    }
}

void TextInput::handleEvent(const sf::Event& event)
{
    if (const auto* mousePressed =
            event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mousePressed->button == sf::Mouse::Button::Left)
        {
            sf::Vector2f mousePosition{
                static_cast<float>(mousePressed->position.x),
                static_cast<float>(mousePressed->position.y)
            };

            focused = box.getGlobalBounds().contains(mousePosition);

            if (focused)
            {
                box.setOutlineColor(sf::Color(37, 99, 235));
            }
            else
            {
                box.setOutlineColor(sf::Color(226, 232, 240));
            }
        }
    }

    if (!focused)
    {
        return;
    }

    if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
    {
        const char32_t unicode = textEntered->unicode;

        if (unicode == '\b')
        {
            if (!value.empty())
            {
                value.pop_back();
            }
        }
        else if (unicode == '\r' || unicode == '\n')
        {
            value.push_back('\n');
        }
        else if (unicode >= 32 && unicode < 127)
        {
            value.push_back(static_cast<char>(unicode));
        }

        text.setString(value);
        updateTextPosition();
    }
}

void TextInput::updateTextPosition()
{
    auto position = box.getPosition();

    text.setPosition({
        position.x + 15.f,
        position.y + 12.f
    });
}

void TextInput::render(sf::RenderWindow& window)
{
    window.draw(box);

    if (value.empty())
    {
        window.draw(placeholder);
    }
    else
    {
        window.draw(text);
    }
}