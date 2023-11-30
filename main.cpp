#include <SFML/Graphics.hpp>

#include <Interface/IGCarte.h>
#include <MOMap.h> // A Supp
#include <MainMenu.h>

/*int main()
{
    //test push guillaume
    MOMap moMap;
    MOPlayer mOPlayer;

    IGCarte igCarte(mOPlayer, moMap.Niveau(-1)); // -1 = Map test
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

        igCarte.update();

    }

    return 0;
}*/

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "The world of Soinc",sf::Style::Titlebar);
    MainMenu mainMenu;

    while (window.isOpen()) {
       sf::Event event;
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed) {
               window.close();
           }
       }

       // Display the main menu
       mainMenu.displayMenu(window);
    }


    return 0;
}
