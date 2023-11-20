#include <SFML/Graphics.hpp>

#include <Interface/IGCarte.h>
#include <MOMap.h> // A Supp

int main()
{
    // A supprimer ou supprimer dans igcarte
    int SCREEN_WIDTH = 1200;
    int SCREEN_HEIGHT = 600;

    MOMap moMap;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "The world of Sonic");
    window.setActive(true);

    MOPlayer mOPlayer;

    IGCarte igCarte(window, mOPlayer, moMap.Niveau(1));

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

