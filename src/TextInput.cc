#include "TextInput.h"
#include "Theme.h"

TextInput::TextInput(
    const sf::Font& font,
    sf::Vector2f position,
    sf::Vector2f size
)
    : text(
          font,
          "",
          Theme::bodySize()
      ),

      placeholder(
          font,
          "WRITE YOUR FEEDBACK...",
          Theme::bodySize()
      )
{
    box.setPosition(position);
    box.setSize(size);

    box.setFillColor(
        Theme::panelDark()
    );

    box.setOutlineThickness(2.f);

    box.setOutlineColor(
        Theme::border()
    );

    text.setFillColor(
        Theme::textPrimary()
    );

    placeholder.setFillColor(
        Theme::textMuted()
    );

    setPosition(position);
}

void TextInput::setPosition(
    sf::Vector2f position
)
{
    box.setPosition(position);

    placeholder.setPosition({
        position.x + 14.f,
        position.y + 10.f
    });

    updateTextPosition();
}

void TextInput::updateTextPosition()
{
    const auto position =
        box.getPosition();

    text.setPosition({
        position.x + 14.f,
        position.y + 10.f
    });
}

void TextInput::update(
    sf::Vector2f mousePosition
)
{
    const bool inside =
        box.getGlobalBounds()
            .contains(mousePosition);

    if (focused)
    {
        box.setOutlineColor(
            Theme::yellow()
        );
    }
    else if (inside)
    {
        box.setOutlineColor(
            Theme::red()
        );
    }
    else
    {
        box.setOutlineColor(
            Theme::border()
        );
    }
}

void TextInput::handleEvent(
    const sf::Event& event
)
{
    if (
        const auto* mousePressed =
            event.getIf<
                sf::Event::MouseButtonPressed>()
    )
    {
        if (
            mousePressed->button ==
            sf::Mouse::Button::Left
        )
        {
            sf::Vector2f mousePosition{
                static_cast<float>(
                    mousePressed->position.x
                ),

                static_cast<float>(
                    mousePressed->position.y
                )
            };

            focused =
                box.getGlobalBounds()
                    .contains(mousePosition);
        }
    }

    if (!focused)
    {
        return;
    }

    if (
        const auto* textEntered =
            event.getIf<
                sf::Event::TextEntered>()
    )
    {
        const char32_t unicode =
            textEntered->unicode;

        if (unicode == '\b')
        {
            if (!value.empty())
            {
                value.pop_back();
            }
        }
        else if (
            unicode == '\r' ||
            unicode == '\n'
        )
        {
            value.push_back('\n');
        }
        else if (
            unicode >= 32 &&
            unicode < 127
        )
        {
            value.push_back(
                static_cast<char>(unicode)
            );
        }

        text.setString(value);

        updateTextPosition();
    }
}

void TextInput::render(
    sf::RenderWindow& window
)
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