#pragma once

#include <SFML/Graphics.hpp>

#include "UI.h"

class App
{
public:
    App();

    void run();

private:
    enum class Screen
    {
        Form,
        Success
    };

    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;

    UI ui;

    Screen currentScreen =
        Screen::Form;
};