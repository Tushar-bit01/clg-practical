#include "App.h"

App::App()
    : window(
          sf::VideoMode({1000, 700}),
          "Student Feedback System"
      )
{
}

void App::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void App::processEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        ui.handleEvent(*event);

        if (const auto* mousePressed =
                event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mousePressed->button == sf::Mouse::Button::Left)
            {
                sf::Vector2f mousePosition{
                    static_cast<float>(mousePressed->position.x),
                    static_cast<float>(mousePressed->position.y)
                };

                ui.handleClick(mousePosition);

                if (currentScreen == Screen::Form &&
                    ui.isSubmitClicked(mousePosition))
                {
                    currentScreen = Screen::Success;
                }
            }
        }
    }
}

void App::update()
{
    if (currentScreen == Screen::Form)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        ui.update({
            static_cast<float>(mousePosition.x),
            static_cast<float>(mousePosition.y)
        });
    }
}

void App::render()
{
    window.clear(sf::Color(245, 247, 250));

    if (currentScreen == Screen::Form)
    {
        ui.render(window);
    }
    else
    {
        ui.renderSuccess(window);
    }

    window.display();
}