#include "App.h"
#include "Theme.h"

App::App()
    : window(
          sf::VideoMode({1000, 820}),
          "Student Feedback"
      )
{
    window.setVerticalSyncEnabled(true);
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
    while (
        const std::optional event =
            window.pollEvent()
    )
    {
        if (
            event->is<
                sf::Event::Closed>()
        )
        {
            window.close();
        }

        if (
            currentScreen ==
            Screen::Form
        )
        {
            ui.handleEvent(
                *event
            );

            if (
                const auto* mousePressed =
                    event->getIf<
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
                            mousePressed
                                ->position.x
                        ),

                        static_cast<float>(
                            mousePressed
                                ->position.y
                        )
                    };

                    ui.handleClick(
                        mousePosition
                    );

                    if (
                        ui.isSubmitClicked(
                            mousePosition
                        )
                    )
                    {
                        currentScreen =
                            Screen::Success;
                    }
                }
            }
        }
    }
}

void App::update()
{
    if (
        currentScreen ==
        Screen::Form
    )
    {
        const sf::Vector2i mousePosition =
            sf::Mouse::getPosition(
                window
            );

        ui.update({
            static_cast<float>(
                mousePosition.x
            ),

            static_cast<float>(
                mousePosition.y
            )
        });
    }
}

void App::render()
{
    window.clear(
        Theme::background()
    );

    if (
        currentScreen ==
        Screen::Form
    )
    {
        ui.render(window);
    }
    else
    {
        ui.renderSuccess(
            window
        );
    }

    window.display();
}