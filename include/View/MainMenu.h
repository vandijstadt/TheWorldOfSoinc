// MainMenu.h
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu();

    void displayMenu(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text leaveButton;
    sf::Text settingsButton;
    sf::Text playButton;

    void executePlayButtonCode();
};

#endif // MAINMENU_H
