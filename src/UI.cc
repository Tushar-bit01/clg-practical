#include "UI.h"

#include <stdexcept>

UI::UI()
    : title(font, "STUDENT FEEDBACK", 32),
      subtitle(font, "Share your experience and help us improve.", 18),

      courseLabel(font, "Course", 16),
      facultyLabel(font, "Faculty", 16),

      courseValue(font, "Data Structures", 17),
      facultyValue(font, "Dr. Sharma", 17),

      ratingLabel(font, "How would you rate the teaching?", 20),
      feedbackLabel(font, "Additional comments", 20),

      submitButton(
          font,
          "SUBMIT FEEDBACK",
          {370.f, 530.f},
          {260.f, 55.f}
      ),

      rating({330.f, 375.f}),

      feedbackInput(
          font,
          {140.f, 430.f},
          {720.f, 70.f}
      )
{
    if (!font.openFromFile("assets/fonts/Arial.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }

    // Main card
    card.setSize({800.f, 500.f});
    card.setPosition({100.f, 100.f});
    card.setFillColor(sf::Color::White);

    // Title
    title.setFillColor(sf::Color(30, 41, 59));
    title.setPosition({140.f, 135.f});

    // Subtitle
    subtitle.setFillColor(sf::Color(100, 116, 139));
    subtitle.setPosition({140.f, 180.f});

    // Course label
    courseLabel.setFillColor(sf::Color(51, 65, 85));
    courseLabel.setPosition({140.f, 215.f});

    // Faculty label
    facultyLabel.setFillColor(sf::Color(51, 65, 85));
    facultyLabel.setPosition({510.f, 215.f});

    // Course box
    courseBox.setSize({330.f, 45.f});
    courseBox.setPosition({140.f, 240.f});
    courseBox.setFillColor(sf::Color(248, 250, 252));
    courseBox.setOutlineThickness(1.f);
    courseBox.setOutlineColor(sf::Color(226, 232, 240));

    // Faculty box
    facultyBox.setSize({330.f, 45.f});
    facultyBox.setPosition({510.f, 240.f});
    facultyBox.setFillColor(sf::Color(248, 250, 252));
    facultyBox.setOutlineThickness(1.f);
    facultyBox.setOutlineColor(sf::Color(226, 232, 240));

    // Course value
    courseValue.setFillColor(sf::Color(30, 41, 59));
    courseValue.setPosition({155.f, 251.f});

    // Faculty value
    facultyValue.setFillColor(sf::Color(30, 41, 59));
    facultyValue.setPosition({525.f, 251.f});

    // Rating label
    ratingLabel.setFillColor(sf::Color(51, 65, 85));
    ratingLabel.setPosition({140.f, 310.f});

    // Feedback label
    feedbackLabel.setFillColor(sf::Color(51, 65, 85));
    feedbackLabel.setPosition({140.f, 405.f});
}

void UI::update(sf::Vector2f mousePosition)
{
    submitButton.update(mousePosition);
    rating.update(mousePosition);
    feedbackInput.update(mousePosition);
}

void UI::handleClick(sf::Vector2f mousePosition)
{
    rating.handleClick(mousePosition);
}

void UI::handleEvent(const sf::Event& event)
{
    feedbackInput.handleEvent(event);
}

bool UI::isSubmitClicked(sf::Vector2f mousePosition) const
{
    return submitButton.isClicked(mousePosition);
}

void UI::render(sf::RenderWindow& window)
{
    window.draw(card);

    window.draw(title);
    window.draw(subtitle);

    window.draw(courseLabel);
    window.draw(facultyLabel);

    window.draw(courseBox);
    window.draw(facultyBox);

    window.draw(courseValue);
    window.draw(facultyValue);

    window.draw(ratingLabel);
    rating.render(window);

    window.draw(feedbackLabel);
    feedbackInput.render(window);

    submitButton.render(window);
}

void UI::renderSuccess(sf::RenderWindow& window)
{
    sf::Text message(
        font,
        "Feedback submitted successfully!",
        28
    );

    message.setFillColor(sf::Color(30, 41, 59));

    const auto bounds = message.getLocalBounds();

    message.setPosition({
        500.f - bounds.position.x - bounds.size.x / 2.f,
        350.f - bounds.position.y - bounds.size.y / 2.f
    });

    window.draw(message);
}