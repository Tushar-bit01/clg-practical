#pragma once

#include <SFML/Graphics.hpp>
#include <array>

class Rating
{
public:
    Rating(sf::Vector2f position);

    void setPosition(
        sf::Vector2f position
    );

    void update(
        sf::Vector2f mousePosition
    );

    void handleClick(
        sf::Vector2f mousePosition
    );

    void render(
        sf::RenderWindow& window
    );

private:
    std::array<
        sf::ConvexShape,
        5
    > stars;

    sf::Vector2f position;

    int selectedRating = 0;
    int hoveredRating = 0;

    void createStar(
        sf::ConvexShape& star,
        sf::Vector2f center
    );
};