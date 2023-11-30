// MainMenu.h
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu();
    void displayMenu(sf::RenderWindow& window);
    void switchToFullscreen(sf::RenderWindow& window);
    void switchToWindowed(sf::RenderWindow& window, unsigned int width, unsigned int height);


private:
    sf::Font font;
    sf::Text leaveButton;
    sf::Text settingsButton;
    sf::Text playButton;
    sf::RectangleShape fullscreenCheckbox;
    sf::Text fullscreenLabel;
    bool isFullscreen;
    void executePlayButtonCode(sf::RenderWindow& window);
};


#endif // MAINMENU_H
