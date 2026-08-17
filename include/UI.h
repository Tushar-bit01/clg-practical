#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "Button.h"
#include "Rating.h"
#include "TextInput.h"

class UI
{
public:
    UI();

    void update(sf::Vector2f mousePosition);

    void handleClick(
        sf::Vector2f mousePosition
    );

    void handleEvent(
        const sf::Event& event
    );

    bool isSubmitClicked(
        sf::Vector2f mousePosition
    ) const;

    void render(
        sf::RenderWindow& window
    );

    void renderSuccess(
        sf::RenderWindow& window
    );

private:
    static constexpr int TEACHER_COUNT = 3;

    // Main window
    sf::RectangleShape card;
    sf::RectangleShape header;

    // Scroll area
    sf::RectangleShape scrollArea;
    sf::RectangleShape scrollTrack;
    sf::RectangleShape scrollThumb;

    // Decorative elements
    sf::RectangleShape headerStripe;
    sf::RectangleShape headerBlock1;
    sf::RectangleShape headerBlock2;

    // Progress
    sf::RectangleShape progressBackground;
    sf::RectangleShape progressFill;

    sf::Font font;

    // Header
    sf::Text title;
    sf::Text subtitle;
    sf::Text questLabel;
    sf::Text progressText;

    // Teacher cards
    std::array<
        sf::RectangleShape,
        TEACHER_COUNT
    > teacherCards;

    std::array<
        sf::CircleShape,
        TEACHER_COUNT
    > teacherBadges;

    std::array<
        sf::Text,
        TEACHER_COUNT
    > teacherNumbers;

    std::array<
        sf::Text,
        TEACHER_COUNT
    > teacherNames;

    std::array<
        sf::Text,
        TEACHER_COUNT
    > teacherSubjects;

    std::array<
        sf::Text,
        TEACHER_COUNT
    > ratingLabels;

    std::array<
        sf::Text,
        TEACHER_COUNT
    > feedbackLabels;

    // Ratings
    Rating rating1;
    Rating rating2;
    Rating rating3;

    // Inputs
    TextInput input1;
    TextInput input2;
    TextInput input3;

    // Submit
    Button submitButton;

    float scrollOffset = 0.f;

    static constexpr float MAX_SCROLL = 190.f;

    void layoutContent();

    bool isInsideScrollArea(
        sf::Vector2f mousePosition
    ) const;

    void updateScrollbar();
};