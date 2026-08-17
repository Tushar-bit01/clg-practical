#include "Theme.h"

// ============================================================
// VINTAGE JAPANESE / RETRO GAME PALETTE
// ============================================================

sf::Color Theme::background()
{
    return {24, 22, 20};
}

sf::Color Theme::backgroundLight()
{
    return {39, 35, 30};
}

// ============================================================
// PANELS
// ============================================================

sf::Color Theme::panel()
{
    return {62, 52, 42};
}

sf::Color Theme::panelLight()
{
    return {83, 67, 49};
}

sf::Color Theme::panelDark()
{
    return {39, 34, 29};
}

// ============================================================
// BORDERS
// ============================================================

sf::Color Theme::border()
{
    return {177, 143, 82};
}

sf::Color Theme::borderDark()
{
    return {12, 11, 10};
}

// ============================================================
// TEXT
// ============================================================

sf::Color Theme::textPrimary()
{
    return {249, 239, 210};
}

sf::Color Theme::textSecondary()
{
    return {211, 190, 150};
}

sf::Color Theme::textMuted()
{
    return {145, 124, 91};
}

// ============================================================
// ACCENTS
// ============================================================

sf::Color Theme::red()
{
    return {190, 55, 43};
}

sf::Color Theme::redLight()
{
    return {220, 70, 52};
}

sf::Color Theme::yellow()
{
    return {225, 178, 69};
}

sf::Color Theme::yellowLight()
{
    return {245, 207, 101};
}

// Matcha green
sf::Color Theme::cyan()
{
    return {91, 132, 83};
}

sf::Color Theme::green()
{
    return {92, 151, 91};
}

// ============================================================
// STARS
// ============================================================

sf::Color Theme::starEmpty()
{
    return {89, 76, 57};
}

sf::Color Theme::starHover()
{
    return {245, 207, 101};
}

sf::Color Theme::starSelected()
{
    return {225, 178, 69};
}

// ============================================================
// FONT
// ============================================================

std::string Theme::fontPath()
{
    return "assets/fonts/pixel.ttf";
}

// ============================================================
// FONT SIZES
// ============================================================

unsigned int Theme::titleSize()
{
    return 30;
}

unsigned int Theme::subtitleSize()
{
    return 14;
}

unsigned int Theme::teacherNameSize()
{
    return 18;
}

unsigned int Theme::bodySize()
{
    return 14;
}

unsigned int Theme::smallSize()
{
    return 12;
}

unsigned int Theme::buttonSize()
{
    return 14;
}