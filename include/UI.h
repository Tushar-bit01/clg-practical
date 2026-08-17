#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Rating.h"
#include "TextInput.h"

class UI
{
public:
    UI();

    void update(sf::Vector2f mousePosition);
    void handleClick(sf::Vector2f mousePosition);
    void handleEvent(const sf::Event& event);

    bool isSubmitClicked(sf::Vector2f mousePosition) const;

    void render(sf::RenderWindow& window);
    void renderSuccess(sf::RenderWindow& window);

private:
    sf::RectangleShape card;

    sf::Font font;

    sf::Text title;
    sf::Text subtitle;

    sf::Text courseLabel;
    sf::Text facultyLabel;

    sf::RectangleShape courseBox;
    sf::RectangleShape facultyBox;

    sf::Text courseValue;
    sf::Text facultyValue;

    sf::Text ratingLabel;
    sf::Text feedbackLabel;

    Button submitButton;
    Rating rating;
    TextInput feedbackInput;
};