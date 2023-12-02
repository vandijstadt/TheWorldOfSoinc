#include "MainMenu.h"
#include "MOMap.h"
#include "MOPlayer.h"
#include "IGCarte.h"
#include <SFML/Graphics.hpp>
#include <iostream>

MainMenu::MainMenu()
{
    isFullscreen = false;
    if (!font.loadFromFile("files/SuperMario256.ttf"))
    {
        std::cerr << "Erreur de chargement de la police.\n";
    }

    leaveButton.setFont(font);
    leaveButton.setString("Leave");
    leaveButton.setLetterSpacing(2.0f);

    settingsButton.setFont(font);
    settingsButton.setString("Settings");
    settingsButton.setLetterSpacing(2.0f);

    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setLetterSpacing(2.0f);

    fullscreenCheckbox.setSize(sf::Vector2f(50.f, 50.f)); // Set the size of the checkbox

    fullscreenLabel.setFont(font);
    fullscreenLabel.setString("Fullscreen");
    fullscreenLabel.setFillColor(sf::Color::Blue);
    fullscreenLabel.setLetterSpacing(2.0f);
}

void MainMenu::displayMenu(sf::RenderWindow & window)
{
    sf::Vector2u windowSize = window.getSize();

    sf::Vector2f buttonSize = leaveButton.getGlobalBounds().getSize();
    float spaceBetweenButtons = buttonSize.y * 1.5;
    float totalHeight = buttonSize.y * 3 + spaceBetweenButtons * 2;

    float shiftAmount = 40.0f; //
    sf::Vector2f buttonPosition = sf::Vector2f(windowSize.x / 2.f - buttonSize.x / 2.f - shiftAmount, windowSize.y / 2.f - totalHeight / 2.f);
    playButton.setPosition(buttonPosition);

    buttonPosition.y += buttonSize.y + spaceBetweenButtons;
    settingsButton.setPosition(buttonPosition);

    buttonPosition.y += buttonSize.y + spaceBetweenButtons;
    leaveButton.setPosition(buttonPosition);

    float checkboxY = windowSize.y / 2.f + totalHeight / 2.f + buttonSize.y + spaceBetweenButtons;
    fullscreenCheckbox.setPosition(sf::Vector2f(windowSize.x / 2.f - buttonSize.x / 2.f - shiftAmount, checkboxY));

    fullscreenLabel.setPosition(sf::Vector2f(fullscreenCheckbox.getPosition().x + fullscreenCheckbox.getSize().x + 10.f, checkboxY));

    // Vérifier si la souris est sur le bouton
    if (leaveButton.getGlobalBounds().contains(static_cast < sf::Vector2f > (sf::Mouse::getPosition(window))))
    {
        leaveButton.setFillColor(sf::Color::Yellow);
    }
    else
    {
        leaveButton.setFillColor(sf::Color::Blue);
    }
    if (playButton.getGlobalBounds().contains(static_cast < sf::Vector2f > (sf::Mouse::getPosition(window))))
    {
        playButton.setFillColor(sf::Color::Yellow);
    }
    else
    {
        playButton.setFillColor(sf::Color::Blue);
    }
    if (settingsButton.getGlobalBounds().contains(static_cast < sf::Vector2f > (sf::Mouse::getPosition(window))))
    {
        settingsButton.setFillColor(sf::Color::Yellow);
    }
    else
    {
        settingsButton.setFillColor(sf::Color::Blue);
    }
    if (fullscreenCheckbox.getGlobalBounds().contains(static_cast < sf::Vector2f > (sf::Mouse::getPosition(window))))
    {
        fullscreenCheckbox.setFillColor(sf::Color::Yellow);
        fullscreenLabel.setFillColor(sf::Color::Yellow);
    }
    else
    {
        fullscreenCheckbox.setFillColor(sf::Color::Blue);
        fullscreenLabel.setFillColor(sf::Color::Blue);
    }

    window.draw(leaveButton);
    window.draw(settingsButton);
    window.draw(playButton);
    window.draw(fullscreenCheckbox);
    window.draw(fullscreenLabel);

    window.display();

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                if (leaveButton.getGlobalBounds().contains(static_cast < sf::Vector2f > (mousePosition)))
                {
                    window.close();
                }
                else if (playButton.getGlobalBounds().contains(static_cast < sf::Vector2f > (mousePosition)))
                {
                    window.close();
                    executePlayButtonCode(window);
                }
                else if (fullscreenCheckbox.getGlobalBounds().contains(static_cast < sf::Vector2f > (mousePosition)))
                {
                    isFullscreen = !isFullscreen;
                    if (isFullscreen)
                    {
                        switchToFullscreen(window);
                    }
                    else
                    {
                        switchToWindowed(window, 800, 600);
                    }
                }
            }
        }
    }
}

void MainMenu::executePlayButtonCode(sf::RenderWindow & window)
{
    MOMap moMap;
    MOPlayer mOPlayer;

    sf::Vector2u windowSize;
    if (isFullscreen)
    {
        windowSize.x = 500;
        windowSize.y = 500;
    }
    else
    {
        windowSize = window.getSize();
    }

    IGCarte igCarte(mOPlayer, moMap.Niveau(-1), windowSize, isFullscreen);
    igCarte.setActive(true);

    while (igCarte.isOpen())
    {
        sf::Event event;
        while (igCarte.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                igCarte.close();
            }
        }

        igCarte.update(&event);
    }
}

void MainMenu::switchToFullscreen(sf::RenderWindow & window)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(desktop, "The world of Soinc", sf::Style::Fullscreen);
}

void MainMenu::switchToWindowed(sf::RenderWindow & window, unsigned int width, unsigned int height)
{
    window.create(sf::VideoMode(width, height), "The world of Soinc", sf::Style::Titlebar);
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width - width) / 2, (sf::VideoMode::getDesktopMode().height - height) / 2));
}
