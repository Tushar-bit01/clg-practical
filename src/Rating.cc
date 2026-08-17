#include "Rating.h"
#include "Theme.h"

#include <cmath>

namespace
{
    constexpr float PI = 3.14159265359f;

    constexpr float OUTER_RADIUS = 17.f;
    constexpr float INNER_RADIUS = 7.f;

    constexpr float STAR_SPACING = 43.f;
}

Rating::Rating(
    sf::Vector2f position
)
    : position(position)
{
    setPosition(position);
}

void Rating::setPosition(
    sf::Vector2f newPosition
)
{
    position = newPosition;

    for (int i = 0; i < 5; ++i)
    {
        createStar(
            stars[i],
            {
                position.x +
                    i * STAR_SPACING,

                position.y
            }
        );
    }
}

void Rating::createStar(
    sf::ConvexShape& star,
    sf::Vector2f center
)
{
    star.setPointCount(10);

    for (int i = 0; i < 10; ++i)
    {
        const float radius =
            (i % 2 == 0)
                ? OUTER_RADIUS
                : INNER_RADIUS;

        const float angle =
            -PI / 2.f +
            i * PI / 5.f;

        star.setPoint(
            i,
            {
                center.x +
                    std::cos(angle) * radius,

                center.y +
                    std::sin(angle) * radius
            }
        );
    }

    star.setFillColor(
        Theme::starEmpty()
    );
}

void Rating::update(
    sf::Vector2f mousePosition
)
{
    hoveredRating = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (
            stars[i]
                .getGlobalBounds()
                .contains(mousePosition)
        )
        {
            hoveredRating = i + 1;
            break;
        }
    }
}

void Rating::handleClick(
    sf::Vector2f mousePosition
)
{
    for (int i = 0; i < 5; ++i)
    {
        if (
            stars[i]
                .getGlobalBounds()
                .contains(mousePosition)
        )
        {
            selectedRating = i + 1;
            break;
        }
    }
}

void Rating::render(
    sf::RenderWindow& window
)
{
    for (int i = 0; i < 5; ++i)
    {
        if (i < selectedRating)
        {
            stars[i].setFillColor(
                Theme::starSelected()
            );
        }
        else if (i < hoveredRating)
        {
            stars[i].setFillColor(
                Theme::starHover()
            );
        }
        else
        {
            stars[i].setFillColor(
                Theme::starEmpty()
            );
        }

        window.draw(stars[i]);
    }
}