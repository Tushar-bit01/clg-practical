#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Theme
{
public:
    // Background
    static sf::Color background();
    static sf::Color backgroundLight();

    // Panels
    static sf::Color panel();
    static sf::Color panelLight();
    static sf::Color panelDark();

    // Borders
    static sf::Color border();
    static sf::Color borderDark();

    // Text
    static sf::Color textPrimary();
    static sf::Color textSecondary();
    static sf::Color textMuted();

    // Accents
    static sf::Color red();
    static sf::Color redLight();
    static sf::Color yellow();
    static sf::Color yellowLight();
    static sf::Color cyan();
    static sf::Color green();

    // Rating
    static sf::Color starEmpty();
    static sf::Color starHover();
    static sf::Color starSelected();

    // Font
    static std::string fontPath();

    // Font sizes
    static unsigned int titleSize();
    static unsigned int subtitleSize();
    static unsigned int teacherNameSize();
    static unsigned int bodySize();
    static unsigned int smallSize();
    static unsigned int buttonSize();
};