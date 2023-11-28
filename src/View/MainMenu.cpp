#include "MainMenu.h"
#include "MOMap.h"
#include "MOPlayer.h"
#include "IGCarte.h"
#include <SFML/Graphics.hpp>

MainMenu::MainMenu() {
    if (!font.loadFromFile("files/SuperMario256.ttf")) {

        std::cerr << "Erreur de chargement de la police.\n";
    }

    leaveButton.setFont(font);
    leaveButton.setString("Leave");
    leaveButton.setPosition(50, 150);

    settingsButton.setFont(font);
    settingsButton.setString("Settings");
    settingsButton.setPosition(50, 100);

    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setPosition(50, 50);
}

void MainMenu::displayMenu(sf::RenderWindow& window) {
    window.clear();

    window.draw(leaveButton);
    window.draw(settingsButton);
    window.draw(playButton);

    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {

                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);


                if (leaveButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {

                    window.close();
                }

                else if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {

                    executePlayButtonCode();
                }
            }
        }
    }
}

void MainMenu::executePlayButtonCode() {
    MOMap moMap;
    MOPlayer mOPlayer;

    IGCarte igCarte(mOPlayer, moMap.Niveau(-1)); // -1 = Map test
    igCarte.setActive(true);

    while (igCarte.isOpen()) {
        sf::Event event;
        while (igCarte.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                igCarte.close();
            }
        }

        igCarte.update();
    }
}
