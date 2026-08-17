#include "UI.h"
#include "Theme.h"

#include <stdexcept>
#include <string>

namespace
{
    constexpr float CARD_X = 60.f;
    constexpr float CARD_Y = 30.f;

    constexpr float CARD_WIDTH = 880.f;
    constexpr float CARD_HEIGHT = 760.f;

    constexpr float CONTENT_X = 120.f;
    constexpr float CONTENT_WIDTH = 750.f;

    constexpr float SCROLL_TOP = 205.f;
    constexpr float SCROLL_BOTTOM = 665.f;

    constexpr float TEACHER_START_Y = 220.f;
    constexpr float TEACHER_SPACING = 225.f;
}

UI::UI()
    : title(
          font,
          "STUDENT FEEDBACK",
          Theme::titleSize()
      ),

      subtitle(
          font,
          "YOUR FEEDBACK QUEST",
          Theme::subtitleSize()
      ),

      questLabel(
          font,
          "FEEDBACK // 2026",
          Theme::smallSize()
      ),

      progressText(
          font,
          "TEACHER 01 / 03",
          Theme::smallSize()
      ),

      teacherNames{
          sf::Text(
              font,
              "DR. SHARMA",
              Theme::teacherNameSize()
          ),

          sf::Text(
              font,
              "PROF. MEHTA",
              Theme::teacherNameSize()
          ),

          sf::Text(
              font,
              "DR. KAPOOR",
              Theme::teacherNameSize()
          )
      },

      teacherSubjects{
          sf::Text(
              font,
              "DATA STRUCTURES",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "COMPUTER NETWORKS",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "DATABASE MANAGEMENT",
              Theme::smallSize()
          )
      },

      ratingLabels{
          sf::Text(
              font,
              "TEACHING QUALITY",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "TEACHING QUALITY",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "TEACHING QUALITY",
              Theme::smallSize()
          )
      },

      feedbackLabels{
          sf::Text(
              font,
              "ADDITIONAL COMMENTS",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "ADDITIONAL COMMENTS",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "ADDITIONAL COMMENTS",
              Theme::smallSize()
          )
      },

      teacherNumbers{
          sf::Text(
              font,
              "1",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "2",
              Theme::smallSize()
          ),

          sf::Text(
              font,
              "3",
              Theme::smallSize()
          )
      },

      rating1({350.f, 0.f}),
      rating2({350.f, 0.f}),
      rating3({350.f, 0.f}),

      input1(
          font,
          {0.f, 0.f},
          {690.f, 48.f}
      ),

      input2(
          font,
          {0.f, 0.f},
          {690.f, 48.f}
      ),

      input3(
          font,
          {0.f, 0.f},
          {690.f, 48.f}
      ),

      submitButton(
          font,
          "SUBMIT FEEDBACK",
          {350.f, 700.f},
          {300.f, 55.f}
      )
{
    // ========================================================
    // LOAD PIXEL FONT
    // ========================================================

    if (!font.openFromFile(
            Theme::fontPath()
        ))
    {
        throw std::runtime_error(
            "Failed to load pixel font: " +
            Theme::fontPath()
        );
    }

    // IMPORTANT:
    // Disable font texture smoothing.
    // This keeps pixel glyphs crisp instead of blurred.
    font.setSmooth(false);

    // ========================================================
    // MAIN CARD
    // ========================================================

    card.setSize({
        CARD_WIDTH,
        CARD_HEIGHT
    });

    card.setPosition({
        CARD_X,
        CARD_Y
    });

    card.setFillColor(
        Theme::panel()
    );

    card.setOutlineThickness(4.f);

    card.setOutlineColor(
        Theme::borderDark()
    );

    // ========================================================
    // HEADER
    // ========================================================

    header.setSize({
        CARD_WIDTH,
        145.f
    });

    header.setPosition({
        CARD_X,
        CARD_Y
    });

    header.setFillColor(
        Theme::panelLight()
    );

    headerStripe.setSize({
        CARD_WIDTH,
        7.f
    });

    headerStripe.setPosition({
        CARD_X,
        CARD_Y + 138.f
    });

    headerStripe.setFillColor(
        Theme::red()
    );

    // Pixel decorations
    headerBlock1.setSize({
        18.f,
        18.f
    });

    headerBlock1.setPosition({
        845.f,
        53.f
    });

    headerBlock1.setFillColor(
        Theme::yellow()
    );

    headerBlock2.setSize({
        12.f,
        12.f
    });

    headerBlock2.setPosition({
        870.f,
        83.f
    });

    headerBlock2.setFillColor(
        Theme::red()
    );

    // ========================================================
    // HEADER TEXT
    // ========================================================

    title.setFillColor(
        Theme::textPrimary()
    );

    title.setPosition({
        100.f,
        60.f
    });

    subtitle.setFillColor(
        Theme::textSecondary()
    );

    subtitle.setPosition({
        100.f,
        105.f
    });

    questLabel.setFillColor(
        Theme::yellow()
    );

    questLabel.setPosition({
        100.f,
        145.f
    });

    progressText.setFillColor(
        Theme::textSecondary()
    );

    progressText.setPosition({
        780.f,
        145.f
    });

    // ========================================================
    // PROGRESS BAR
    // ========================================================

    progressBackground.setSize({
        180.f,
        8.f
    });

    progressBackground.setPosition({
        590.f,
        146.f
    });

    progressBackground.setFillColor(
        Theme::panelDark()
    );

    progressFill.setSize({
        60.f,
        8.f
    });

    progressFill.setPosition({
        590.f,
        146.f
    });

    progressFill.setFillColor(
        Theme::yellow()
    );

    // ========================================================
    // SCROLL AREA
    // ========================================================

    scrollArea.setSize({
        760.f,
        455.f
    });

    scrollArea.setPosition({
        100.f,
        SCROLL_TOP
    });

    scrollArea.setFillColor(
        Theme::backgroundLight()
    );

    scrollArea.setOutlineThickness(2.f);

    scrollArea.setOutlineColor(
        Theme::border()
    );

    // ========================================================
    // SCROLLBAR
    // ========================================================

    scrollTrack.setSize({
        6.f,
        435.f
    });

    scrollTrack.setPosition({
        875.f,
        215.f
    });

    scrollTrack.setFillColor(
        Theme::borderDark()
    );

    scrollThumb.setFillColor(
        Theme::yellow()
    );

    // ========================================================
    // TEACHER CARDS
    // ========================================================

    for (int i = 0;
         i < TEACHER_COUNT;
         ++i)
    {
        teacherCards[i].setSize({
            CONTENT_WIDTH,
            205.f
        });

        teacherCards[i].setFillColor(
            Theme::panelDark()
        );

        teacherCards[i].setOutlineThickness(
            2.f
        );

        teacherCards[i].setOutlineColor(
            Theme::border()
        );

        teacherBadges[i].setRadius(
            18.f
        );

        teacherBadges[i].setFillColor(
            Theme::red()
        );

        teacherNumbers[i].setFillColor(
            Theme::textPrimary()
        );

        teacherNames[i].setFillColor(
            Theme::textPrimary()
        );

        teacherSubjects[i].setFillColor(
            Theme::textSecondary()
        );

        ratingLabels[i].setFillColor(
            Theme::textMuted()
        );

        feedbackLabels[i].setFillColor(
            Theme::textMuted()
        );
    }

    layoutContent();
    updateScrollbar();
}

void UI::layoutContent()
{
    Rating* ratings[] = {
        &rating1,
        &rating2,
        &rating3
    };

    TextInput* inputs[] = {
        &input1,
        &input2,
        &input3
    };

    for (int i = 0;
         i < TEACHER_COUNT;
         ++i)
    {
        const float y =
            TEACHER_START_Y +
            i * TEACHER_SPACING -
            scrollOffset;

        // Card
        teacherCards[i].setPosition({
            CONTENT_X,
            y
        });

        // Badge
        teacherBadges[i].setPosition({
            CONTENT_X + 18.f,
            y + 17.f
        });

        teacherNumbers[i].setPosition({
            CONTENT_X + 29.f,
            y + 27.f
        });

        // Teacher
        teacherNames[i].setPosition({
            CONTENT_X + 60.f,
            y + 15.f
        });

        teacherSubjects[i].setPosition({
            CONTENT_X + 60.f,
            y + 43.f
        });

        // Rating
        ratingLabels[i].setPosition({
            CONTENT_X + 25.f,
            y + 74.f
        });

        ratings[i]->setPosition({
            CONTENT_X + 195.f,
            y + 84.f
        });

        // Feedback
        feedbackLabels[i].setPosition({
            CONTENT_X + 25.f,
            y + 122.f
        });

        inputs[i]->setPosition({
            CONTENT_X + 25.f,
            y + 145.f
        });
    }
}

bool UI::isInsideScrollArea(
    sf::Vector2f mousePosition
) const
{
    return
        mousePosition.x >= 100.f &&
        mousePosition.x <= 860.f &&
        mousePosition.y >= SCROLL_TOP &&
        mousePosition.y <= SCROLL_BOTTOM;
}

void UI::updateScrollbar()
{
    constexpr float TRACK_HEIGHT = 435.f;

    const float contentHeight = 655.f;

    float thumbHeight =
        TRACK_HEIGHT *
        (TRACK_HEIGHT / contentHeight);

    if (thumbHeight < 90.f)
    {
        thumbHeight = 90.f;
    }

    const float travel =
        TRACK_HEIGHT - thumbHeight;

    const float ratio =
        scrollOffset / MAX_SCROLL;

    scrollThumb.setSize({
        6.f,
        thumbHeight
    });

    scrollThumb.setPosition({
        875.f,
        215.f +
            ratio * travel
    });
}

void UI::update(
    sf::Vector2f mousePosition
)
{
    submitButton.update(
        mousePosition
    );

    rating1.update(
        mousePosition
    );

    rating2.update(
        mousePosition
    );

    rating3.update(
        mousePosition
    );

    input1.update(
        mousePosition
    );

    input2.update(
        mousePosition
    );

    input3.update(
        mousePosition
    );
}

void UI::handleClick(
    sf::Vector2f mousePosition
)
{
    if (!isInsideScrollArea(
            mousePosition))
    {
        return;
    }

    rating1.handleClick(
        mousePosition
    );

    rating2.handleClick(
        mousePosition
    );

    rating3.handleClick(
        mousePosition
    );
}

void UI::handleEvent(
    const sf::Event& event
)
{
    if (
        const auto* wheel =
            event.getIf<
                sf::Event::MouseWheelScrolled>()
    )
    {
        if (
            wheel->wheel ==
            sf::Mouse::Wheel::Vertical
        )
        {
            sf::Vector2f mousePosition{
                static_cast<float>(
                    wheel->position.x
                ),

                static_cast<float>(
                    wheel->position.y
                )
            };

            if (
                isInsideScrollArea(
                    mousePosition
                )
            )
            {
                scrollOffset -=
                    wheel->delta * 45.f;

                if (scrollOffset < 0.f)
                {
                    scrollOffset = 0.f;
                }

                if (scrollOffset > MAX_SCROLL)
                {
                    scrollOffset = MAX_SCROLL;
                }

                layoutContent();
                updateScrollbar();
            }
        }
    }

    input1.handleEvent(event);
    input2.handleEvent(event);
    input3.handleEvent(event);
}

bool UI::isSubmitClicked(
    sf::Vector2f mousePosition
) const
{
    return submitButton.isClicked(
        mousePosition
    );
}

void UI::render(
    sf::RenderWindow& window
)
{
    // Main frame
    window.draw(card);

    // Header
    window.draw(header);
    window.draw(headerStripe);

    window.draw(headerBlock1);
    window.draw(headerBlock2);

    window.draw(title);
    window.draw(subtitle);
    window.draw(questLabel);
    window.draw(progressText);

    window.draw(
        progressBackground
    );

    window.draw(
        progressFill
    );

    // Scroll area
    window.draw(
        scrollArea
    );

    // ========================================================
    // CLIP CONTENT
    // ========================================================

    sf::View contentView =
        window.getDefaultView();

    contentView.setScissor(
        sf::FloatRect(
            {0.10f, 0.25f},
            {0.76f, 0.555f}
        )
    );

    window.setView(
        contentView
    );

    for (int i = 0;
         i < TEACHER_COUNT;
         ++i)
    {
        window.draw(
            teacherCards[i]
        );

        window.draw(
            teacherBadges[i]
        );

        window.draw(
            teacherNumbers[i]
        );

        window.draw(
            teacherNames[i]
        );

        window.draw(
            teacherSubjects[i]
        );

        window.draw(
            ratingLabels[i]
        );

        if (i == 0)
        {
            rating1.render(window);
        }
        else if (i == 1)
        {
            rating2.render(window);
        }
        else
        {
            rating3.render(window);
        }

        window.draw(
            feedbackLabels[i]
        );

        if (i == 0)
        {
            input1.render(window);
        }
        else if (i == 1)
        {
            input2.render(window);
        }
        else
        {
            input3.render(window);
        }
    }

    window.setView(
        window.getDefaultView()
    );

    // Scrollbar
    window.draw(
        scrollTrack
    );

    window.draw(
        scrollThumb
    );

    // Submit
    submitButton.render(
        window
    );
}

void UI::renderSuccess(
    sf::RenderWindow& window
)
{
    window.draw(card);

    sf::Text titleText(
        font,
        "QUEST COMPLETE!",
        28
    );

    sf::Text subtitleText(
        font,
        "FEEDBACK RECORDED",
        16
    );

    sf::Text japaneseText(
        font,
        "ARIGATO!",
        20
    );

    titleText.setFillColor(
        Theme::yellow()
    );

    subtitleText.setFillColor(
        Theme::textSecondary()
    );

    japaneseText.setFillColor(
        Theme::red()
    );

    const auto titleBounds =
        titleText.getLocalBounds();

    const auto subtitleBounds =
        subtitleText.getLocalBounds();

    const auto japaneseBounds =
        japaneseText.getLocalBounds();

    titleText.setPosition({
        500.f -
            titleBounds.position.x -
            titleBounds.size.x / 2.f,

        320.f -
            titleBounds.position.y -
            titleBounds.size.y / 2.f
    });

    subtitleText.setPosition({
        500.f -
            subtitleBounds.position.x -
            subtitleBounds.size.x / 2.f,

        375.f -
            subtitleBounds.position.y -
            subtitleBounds.size.y / 2.f
    });

    japaneseText.setPosition({
        500.f -
            japaneseBounds.position.x -
            japaneseBounds.size.x / 2.f,

        425.f -
            japaneseBounds.position.y -
            japaneseBounds.size.y / 2.f
    });

    window.draw(titleText);
    window.draw(subtitleText);
    window.draw(japaneseText);
}