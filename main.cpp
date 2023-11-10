#include <SFML/Graphics.hpp>

#include <IGCarte.h>

int main()
{
    int SCREEN_WIDTH = 1200;
    int SCREEN_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "The world of Sonic");

    IGCarte igCarte(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        igCarte.update();

        // Autre logique du jeu

    }

    return 0;
}

