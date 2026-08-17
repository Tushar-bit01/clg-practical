#include "Rating.h"

#include <cmath>

namespace
{
    constexpr float PI = 3.14159265359f;
    constexpr float OUTER_RADIUS = 24.f;
    constexpr float INNER_RADIUS = 10.f;
    constexpr float STAR_SPACING = 65.f;
}

Rating::Rating(sf::Vector2f position)
{
    for (int i = 0; i < 5; ++i)
    {
        createStar(
            stars[i],
            {
                position.x + i * STAR_SPACING,
                position.y
            }
        );
    }
}

void Rating::createStar(sf::ConvexShape& star, sf::Vector2f center)
{
    star.setPointCount(10);

    for (int i = 0; i < 10; ++i)
    {
        float radius = (i % 2 == 0)
            ? OUTER_RADIUS
            : INNER_RADIUS;

        float angle = -PI / 2.f + i * PI / 5.f;

        sf::Vector2f point{
            center.x + std::cos(angle) * radius,
            center.y + std::sin(angle) * radius
        };

        star.setPoint(i, point);
    }

    star.setFillColor(sf::Color(203, 213, 225));
}

void Rating::update(sf::Vector2f mousePosition)
{
    hoveredRating = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (stars[i].getGlobalBounds().contains(mousePosition))
        {
            hoveredRating = i + 1;
            break;
        }
    }
}

void Rating::handleClick(sf::Vector2f mousePosition)
{
    for (int i = 0; i < 5; ++i)
    {
        if (stars[i].getGlobalBounds().contains(mousePosition))
        {
            selectedRating = i + 1;
            break;
        }
    }
}

void Rating::render(sf::RenderWindow& window)
{
    for (int i = 0; i < 5; ++i)
    {
        if (i < selectedRating)
        {
            stars[i].setFillColor(sf::Color(250, 180, 40));
        }
        else if (i < hoveredRating)
        {
            stars[i].setFillColor(sf::Color(250, 210, 100));
        }
        else
        {
            stars[i].setFillColor(sf::Color(203, 213, 225));
        }

        window.draw(stars[i]);
    }
}